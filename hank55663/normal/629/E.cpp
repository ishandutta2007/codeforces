#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
vector<int> v[100005];
vector<int> number[100005];
int Size[100005];
LL sum[100005];
LL sum2[100005];
int in[100005];
int out[100005];
int dep[100005];
int p[20][1000005];
int t;
void dfs(int x,int f){
    in[x]=++t;
    dep[x]=dep[f]+1;
    p[0][x]=f;
    Size[x]=1;
    sum[x]=0;
    for(auto it:v[x]){
        if(it!=f){
            dfs(it,x);
            Size[x]+=Size[it];
            sum[x]+=sum[it]+Size[it];   
        }
        number[x].pb(t);
    }
    out[x]=t;
}
void dfs2(int x,int f,int n,LL s){
    s+=n-Size[x];
    sum2[x]=sum[x]+s;//+n-Size[x];
   // printf("%d %lld\n",x,sum2[x]);
    for(auto it:v[x]){
        if(it!=f){
            dfs2(it,x,n,sum2[x]-sum[it]-Size[it]);
        }
    }
}
void build(int n){
    for(int i = 1;i<20;i++){
        for(int j = 1;j<=n;j++){
            p[i][j]=p[i-1][p[i-1][j]];
        }
    }
}
int lca(int a,int b){
    if(dep[a]>dep[b])swap(a,b);
    int d=dep[b]-dep[a];
    for(int i = 0;i<20;i++){
        if(d&(1<<i)){
            b=p[i][b];
        }
    }
    if(a==b)return a;
    for(int i = 19;i>=0;i--){
        if(p[i][a]!=p[i][b]){
            a=p[i][a];
            b=p[i][b];
        }
    }
    return p[0][a];
}
bool solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1,0);
    dfs2(1,0,n,0);
    build(n);
    while(m--){
        int x,y;
        scanf("%d %d",&x,&y);
        if(in[x]>in[y])swap(x,y);
        if(out[x]>=in[y]){
            int idx=lower_bound(number[x].begin(),number[x].end(),in[y])-number[x].begin();
            LL tot=Size[y]*1ll*(n-Size[v[x][idx]]);
            LL ssum=sum[y]*(n-Size[v[x][idx]])+(sum2[x]-sum[v[x][idx]]-Size[v[x][idx]])*Size[y];
            //  printf("%lld %lld %d\n",tot,ssum,sum2[x]);
            printf("%.12f\n",ssum*1.0/tot+dep[y]-dep[x]+1);//-dep[r]*2);
        }
        else{
            int r=lca(x,y);
            LL tot=Size[x]*1ll*Size[y];
            LL ssum=sum[x]*Size[y]+sum[y]*Size[x];
          //  printf("%lld %lld\n",tot,ssum);
            printf("%.12f\n",ssum*1.0/tot+dep[x]+dep[y]-dep[r]*2+1);
        }
    }
    return true;
}
int main(){
    int t=1;
   // scanf("%d",&t);
    while(t--)solve();//solve();
}
/*

4 7 2 1 7 4 3 1 7 2
*/