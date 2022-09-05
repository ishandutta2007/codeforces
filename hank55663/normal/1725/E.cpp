#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
vector<int> E[200005];
vector<int> fac[200005];
vector<int> cal[200005];
int d[200005];
int in[200005];
int out[200005];
int p[20][200005];
int t;
void dfs(int x,int f){
    d[x]=d[f]+1;
    in[x]=++t;
    p[0][x]=f;
    for(auto it:E[x]){
        if(it!=f){
            dfs(it,x);
        }
    }
    out[x]=t;
}
void build(int n){
    for(int i = 1;i<20;i++){
        for(int j=1;j<=n;j++){
            p[i][j]=p[i-1][p[i-1][j]];
        }
    }
}
int lca(int x,int y){
    if(d[x]>d[y])swap(x,y);
    int dd=d[y]-d[x];
    for(int i = 0;i<20;i++){
        if(dd&(1<<i))y=p[i][y];
    }
    if(x==y)return x;
    for(int i = 19;i>=0;i--){
        if(p[i][y]!=p[i][x]){
            x=p[i][x];
            y=p[i][y];
        }
    }
    return p[0][x];
}
vector<pii> v[200005];
LL ans;
int ok[200005];
bool cmp(const int &x,const int &y){
    return in[x]<in[y];
}
void build(vector<int> node){
    sort(node.begin(),node.end(),cmp);
    int n=node.size();
    for(int i = 1;i<n;i++){
        int x=lca(node[i-1],node[i]);
        node.pb(x);
    }
    sort(node.begin(),node.end(),cmp);
    node.resize(unique(node.begin(),node.end())-node.begin());
    for(auto it:node){
        v[it].clear();
    }
    vector<int> stk;
    for(auto it:node){
        while(stk.size()){
            if(out[stk.back()]<in[it])stk.pop_back();
            else break;
        }
        if(stk.size())v[stk.back()].pb(mp(it,d[it]-d[stk.back()])),v[it].pb(mp(stk.back(),d[it]-d[stk.back()]));//printf("%d %d %d\n",stk.back(),it,d[it]-d[stk.back()]);
        stk.pb(it);
    }
}
int Size[200005];
LL Sum[200005];
LL tot;
void dfsq(int x,int f){
    Size[x]=ok[x];
    Sum[x]=0;
    for(auto it:v[x]){
        if(it.x!=f){
            dfsq(it.x,x);
            Size[x]+=Size[it.x];
            Sum[x]+=Sum[it.x]+it.y*1ll*Size[it.x];
        }
    }
}
const int mod=998244353;
void dfsq(int x,int f,LL xx,LL S){
    LL dp[2][3]={0,0,0,0,0,0};
    dp[0][0]=1;
    dp[0][1]=S%mod;;
    dp[1][0]=xx%mod;
   
    for(auto it:v[x]){
        if(it.x!=f){
             dfsq(it.x,x,xx+Sum[x]-Sum[it.x]+it.y*1ll*(tot-2*Size[it.x]),tot-Size[it.x]);
        }
    }
    //vector<LL> vv;
    //vv.pb(xx);
    /* printf("///\n");
          for(int i = 0;i<2;i++){
              for(int j=0;j<3;j++){
                  printf("%d ",dp[i][j]);
              }
              printf("\n");
          }*/
    for(auto it:v[x]){
        if(it.x!=f){
            LL val=(Sum[it.x]+it.y*1ll*Size[it.x])%mod;
             for(int i = 1;i<=1;i++){
                for(int j = 1;j>=0;j--)dp[i][j+1]+=dp[i][j]*Size[it.x],dp[i][j+1]%=mod;
            }
            for(int i = 0;i<=2;i++)dp[1][i]+=dp[0][i]*val,dp[1][i]%=mod;
            for(int i = 0;i<=0;i++){
                for(int j = 1;j>=0;j--)dp[i][j+1]+=dp[i][j]*Size[it.x],dp[i][j+1]%=mod;
            }
          //  printf("%d\n",it.x)
        /*  printf("///\n");
          for(int i = 0;i<2;i++){
              for(int j=0;j<3;j++){
                  printf("%d ",dp[i][j]);
              }
              printf("\n");
          }*/
        
        }
    }
   //  printf("%d %d\n",S,xx);
    ans+=dp[1][2];
  //  printf("x%d %d\n",x,dp[1][2]);
    if(ok[x])ans+=dp[1][1];
    ans%=mod;
  //  printf("%lld ans: %lld\n",x,ans);
    //printf("%d %d\n",x,dp2);
    //for(auto it:vv)printf("%lld ",it);
 //   printf("\n");
}
void solve(){
    for(int i = 2;i<=200000;i++){
        if(fac[i].empty())
        for(int j = i;j<=200000;j+=i)fac[j].pb(i);
    }
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        int a;
        scanf("%d",&a);
        for(auto it:fac[a])cal[it].pb(i);
    }
    for(int i = 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        E[x].pb(y);
        E[y].pb(x);
    }
    dfs(1,0);
    build(n);
    for(int i = 2;i<=200000;i++){
        if(cal[i].size()){
            for(auto it:cal[i])ok[it]=1;
            build(cal[i]);

            dfsq(cal[i][0],0);
            tot=Size[cal[i][0]];
         //   printf("?\n");
            dfsq(cal[i][0],0,0,0);

            for(auto it:cal[i])ok[it]=0;
                //printf("?%d %lld %d\n",i,ans,cal[i].size());
        }
    }
    printf("%lld\n",ans);
}
int main(){
    int t=1;
   // scanf("%d",&t);
    for(int T=1;T<=t;T++){
        solve();
    }
   // printf("%d\n",s.size());
}

/*
3 5 7 8
4999850001
6
1 8 4 6 8 10
2 1
3 1
4 3
5 4
6 3
1 2 1
1 3 1
3 4 1
4 5 1
3 6 1
*/