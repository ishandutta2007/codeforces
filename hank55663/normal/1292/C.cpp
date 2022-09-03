#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
int Size[3005][3005];
int par[3005][3005];
vector<int> v[3005];
void dfs(int x,int f,int s){
    Size[s][x]=1;
    par[s][x]=f;
    for(auto it:v[x]){
        if(it!=f){
            dfs(it,x,s);
            Size[s][x]+=Size[s][it];
        }
    }
}
pii p[3005];
LL ans[3005][3005];
int inq[3005][3005];
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<n;i++){
        int x=rand()%i+1,y=i+1;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
        p[i]=mp(x,y);
    }    
    for(int i = 1;i<=n;i++){
        dfs(i,0,i);
    }
    queue<pii> q;
    for(int i = 1;i<n;i++){
        q.push(p[i]);
        ans[p[i].x][p[i].y]=Size[p[i].y][p[i].x]*Size[p[i].x][p[i].y];
        inq[p[i].x][p[i].y]=1;
        swap(p[i].x,p[i].y);
        q.push(p[i]);
        ans[p[i].x][p[i].y]=Size[p[i].y][p[i].x]*Size[p[i].x][p[i].y];
        inq[p[i].x][p[i].y]=1;
    }
    LL res=0;
    while(!q.empty()){
        pii p=q.front();
        q.pop();
        res=max(res,ans[p.x][p.y]);
      //  printf("%d %d %lld\n",p.x,p.y,ans[p.x][p.y]);
        for(auto it:v[p.y]){
            if(it!=par[p.x][p.y]){
              //  if(p.x==5&&p.y==1){
               //     printf("%d %d %d?\n",it,Size[p.y][p.x],Size[p.x][it]);
              //  }
                ans[it][p.x]=max(ans[it][p.x],ans[p.x][p.y]+Size[p.y][p.x]*Size[p.x][it]);
                ans[p.x][it]=max(ans[it][p.x],ans[p.x][p.y]+Size[p.y][p.x]*Size[p.x][it]);
                res=max(res,ans[it][p.x]);
                if(!inq[it][p.x]){
                    q.push(mp(it,p.x));
                    inq[it][p.x]=1;
                }
                if(!inq[p.x][it]){
                    q.push(mp(p.x,it));
                    inq[p.x][it]=1;
                }
            }
        }
    }
    printf("%lld\n",res);
}
/*
2 6
5 7
7 5
4 3
6 4
7 3
6 5
5 7
3 6
4 7
*/
//a+a+1=10a+1
//3a+2=10a+2