#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
using std::max;
using std::min;
using std::vector;
// Min-cost max-flow
// Vrtices de 0 a n
#define MAXN 2100
#define INF 10000000000000000LL
int n;
/*cap[i][j][0] = capacidades dadas, cap[i][j][1] = 0*/
long long cap[MAXN][MAXN][2];
/*cst[i][j][0] = custos dados, cst[i][j][1] = -cst[j][i][0]*/
long long cst[MAXN][MAXN][2];

vector<int> G[MAXN][2];

int par[MAXN],pr[MAXN];
long long p[MAXN];
void bellman(int s,int t)
{
    int i,j,k,h;
    for(i=0;i<=n;i++) {
        p[i] = INF;
        pr[i] = -1;
    }
    p[s] = 0;
    for(h=0;h<=n;h++) 
        for(k=0;k<=1;k++) 
            for(i=0;i<=n;i++) 
                for(j=0;j<(int)G[i][k].size();j++) {
                    int viz = G[i][k][j];
                    if(cap[i][viz][k] <= 0) continue;
                    if(p[viz] > p[i] + cst[i][viz][k]) p[viz] = p[i] + cst[i][viz][k];
                }
}

bool dijkstra(int s,int t)
{
    int v,i,k;
    bool intree[MAXN];
    long long dst[MAXN],men,c;
    for(i=0;i<=n;i++)
    {
        dst[i] = INF;
        par[i] = -1;
        pr[i] = -1;
        intree[i] = false;
    }
    dst[s] = 0;
    v = s;
    while(!intree[v])
    {
        intree[v] = true;
        for(i=0;i<=n;i++)
        {
            if(intree[i]) continue;
            for(k=0;k<=1;k++)
            {
                if(cap[v][i][k] <= 0) continue;
                c = cst[v][i][k] + p[v] - p[i];
                if(dst[i] > dst[v] + c){
                    dst[i] = dst[v] + c;
                    par[i] = v;
                    pr[i] = k;
                }
            }
        }
        men = INF;
        for(i=0;i<=n;i++)
        {
            if(intree[i]) continue;
            if(dst[i] < men)
            {
                men = dst[i];
                v = i;
            }
        }
    }
    for(i=0;i<=n;i++) p[i] += dst[i];
    return intree[t];
}

long long mincost(int s,int t)
{
    int i,j,k,v;
    long long aug,ret=0;
    /*somente se houver aresta com custo negativo, senao comece com p[i] = 0*/
    bellman(s,t);
    while(dijkstra(s,t))
    {
        v = t;
        aug = INF;
        while(v != s)
        {
            if(aug > cap[par[v]][v][pr[v]])
                aug = cap[par[v]][v][pr[v]];
            v = par[v];
        }
        v = t;
        while(v != s)
        {
            cap[par[v]][v][pr[v]] -= aug;
            cap[v][par[v]][1-pr[v]] += aug;
            v = par[v];
        }
    }
    for(i=0;i<=n;i++)
        for(j=0;j<=n;j++)
            ret += cap[j][i][1]*cst[i][j][0];
    return ret;
}
void initFlowNet(int nn){
    n=nn;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cst[i][j][1]=-cst[j][i][0];
            cap[i][j][1]=0;
        }
    }
    for(int i = 0; i < n; i++) {    
        for(int k=0;k<2;k++){
            G[i][k].clear();
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j=0;j<n;j++){
            for(int k=0;k<2;k++){
                if(cap[i][j][k]){
                    G[i][k].push_back(j);
                }
            }
        }   
    }
}

int ntasks,nmachines;

int taskEnterid(int task){
    return task;
}

int taskExitid(int task){
    return task + ntasks;
}

int presource(){
    return 2*ntasks;
}

int source(){
    return 2*ntasks+1;
}

int sink(){
    return 2*ntasks+2;
}

//int s[MAXN],t[MAXN],c[MAXN];
struct objeto{
    int s,t,c,id;
};
objeto tarefas[MAXN];
#include <algorithm>

bool cmp(objeto a, objeto b){
    return a.s<b.s;
}

int main(){
    scanf("%d %d",&ntasks,&nmachines);
    for(int i=0;i<ntasks;i++){
        scanf("%d %d %d",&tarefas[i].s,&tarefas[i].t,&tarefas[i].c);
        tarefas[i].id=i;
    }
    //for(int i=0;i<ntasks;i++){
//      printf("%d %d %d\n", tarefas[i].s,tarefas[i].t,tarefas[i].c);
//  }
//  printf("\n");
    std::sort(tarefas, tarefas+ntasks,cmp);
//  for(int i=0;i<ntasks;i++){
//      printf("%d %d %d\n", tarefas[i].s,tarefas[i].t,tarefas[i].c);
//  }
    memset(cap,0,sizeof(cap));
    cap[presource()][taskEnterid(0)][0]=nmachines;
    for(int i=0;i<ntasks;i++) {
        cap[taskEnterid(i)][taskExitid(i)][0] = 1;
        cst[taskEnterid(i)][taskExitid(i)][0] = -tarefas[i].c;
        if (i != ntasks-1) {
            cap[taskEnterid(i)][taskEnterid(i+1)][0] = nmachines;
        }
        cap[taskExitid(i)][sink()][0]=1;
        long long maximo=1LL<<50;
        for(int j=0;j<ntasks;j++){
            if(tarefas[i].s+tarefas[i].t<=tarefas[j].s){
                cap[taskExitid(i)][taskEnterid(j)][0]=1;
                cst[taskExitid(i)][taskEnterid(j)][0]=0;
                break;
            }
        }
    }
    initFlowNet(sink()+1);
    /*for(int i=0;i<ntasks;i++){
        printf("%d - ", tarefas[i].id);
        for(int j=0;j<ntasks;j++){
            printf("%5lld", cap[taskExitid(i)][taskEnterid(j)][0]);
        }
        printf("\n");
    }*/
    long long bestcost = mincost(presource(),sink());

    bool escolhido[2000];
    memset(escolhido,0,sizeof(escolhido));
    for(int i=0;i<ntasks;i++){
        if(cap[taskEnterid(i)][taskExitid(i)][0] == 0){
            escolhido[tarefas[i].id]=true;
        }
    }
    //printf("%lld\n", bestcost);
    for(int i=0;i<ntasks;i++){
        printf("%d ", escolhido[i]);
    }
    printf("\n");

}