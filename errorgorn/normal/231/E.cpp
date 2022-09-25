#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
typedef pair<int,int> ii;
const int MOD=1000000007;
struct ufds{
    int p[100005];
    int r[100005];
    int s[100005];

    ufds(){
        for (int x=0;x<100005;x++){
            p[x]=x;
            r[x]=0;
            s[x]=1;
        }
    }
    int parent(int i){return (p[i]==i)?i:p[i]=parent(p[i]);}
    void unions(int i,int j){
        i=parent(i),j=parent(j);
        if (i==j) return;
        if (r[i]<r[j]){
            p[i]=j;
            s[j]+=s[i];
        }
        else{
            p[j]=i;
            s[i]+=s[j];
            if (r[i]==r[j]) r[i]++;
        }
    }
}*dsu=new ufds();

long long qexp(long long b,long long p,int m){
    long long res=1;
    while (p){
        if (p&1) res=(res*b)%m;
        b=(b*b)%m;
        p>>=1;
    }
    return res;
}


int n,m;
vector<int> al[100005];
int counter;

int dfs_time[100005];
int low[100005];
void dfs(int i,int p){
    dfs_time[i]=low[i]=counter++;
    for (auto &it:al[i]){
        if (it==p) continue;
        if (dfs_time[it]){
            dsu->unions(i,it);
            low[i]=min(low[i],dfs_time[it]);
        }
        else{
            dfs(it,i);
            if (low[it]<=dfs_time[i]){ //not bridge
                dsu->unions(i,it);
            }
            low[i]=min(low[i],low[it]);
        }
    }
}

int component[100005]; ///which component the vertex is in now
vector<int> tal[100005]; ///new adj list
vector<int> euler; ///this is euler tour
int first[100005];
int depth[100005];
int cycles[100005];
void dfs2(int i,int p){
    first[i]=counter;
    euler.push_back(i);
    counter++;
    if (dsu->s[i]>1) cycles[i]++;
    
    for (auto it=tal[i].begin();it!=tal[i].end();it++){
        if (*it==p) continue;
        depth[*it]=depth[i]+1;
        cycles[*it]=cycles[i];
        dfs2(*it,i);
        euler.push_back(i);
        counter++;
    }
}

ii STmin[200005][20];
void buildST(){ //build sparse table
    for (int x=0;x<euler.size();x++){
        STmin[x][0]=ii(depth[euler[x]],euler[x]);
    }
    int j=1,logj=1;
    while (j<=(euler.size()>>1)){
        for (int x=0;x<=(euler.size()-(j<<1));x++){
            STmin[x][logj]=min(STmin[x][logj-1],STmin[x+j][logj-1]);
        }
        j<<=1;
        logj++;
    }
}

int lca_query(int i, int j){
    i=first[i],j=first[j];
    if (i>j) swap(i,j);
    j=j-i+1;
    int row=31-__builtin_clz(j);
    j-=1<<row;
    return min(STmin[i][row],STmin[i+j][row]).second;
}

int main(){
    scanf("%d%d",&n,&m);
    int a,b;
    while (m--){
        scanf("%d%d",&a,&b);
        al[a].push_back(b);
        al[b].push_back(a);
    }
    
    counter=1;
    dfs(1,-1);
        
    for (int x=1;x<=n;x++) component[x]=dsu->parent(x);
    for (int x=1;x<=n;x++){
        for (auto &it:al[x]){
            if (component[x]!=component[it]){
                tal[component[x]].push_back(component[it]);
            }
        }
    }
    
    counter=0;
    dfs2(component[1],-1);
    buildST();
    
    scanf("%d",&m);
    int __lca;
    while (m--){
        scanf("%d%d",&a,&b);
        a=component[a],b=component[b];
        __lca=lca_query(a,b);
        if (dsu->s[__lca]>1){
            printf("%lld\n",qexp(2,cycles[a]+cycles[b]-2*cycles[__lca]+1,MOD));
        }
        else{
            printf("%lld\n",qexp(2,cycles[a]+cycles[b]-2*cycles[__lca],MOD));
        }
    }
}