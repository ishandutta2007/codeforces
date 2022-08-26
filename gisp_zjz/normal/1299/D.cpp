#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
const int E=555;
typedef pair<int,int> pi;
typedef unsigned int ll;
const int maxn=1e5+3;
const int M=1000000007;
unordered_map<ll,int> f;
int a[E][E],tot,n,m,dp[E],tmp[E],vis[maxn],key[maxn],res,d[maxn],V[maxn];
ll b[E];
vector<pi> h[maxn];
void add(int &x,int y){
    x+=y; if (x>=M) x-=M;
}
int get_id(ll x){
    if (x&1) return -1;
    if (f.find(x)==f.end()) f[x]=++tot,b[tot]=x;
    return f[x];
}
int go(int x,int y){
    if (x==-1||y==-1) return -1;
    ll tx=b[x],ty=b[y],tz=tx^ty;
    if (a[x][y]!=-1) return a[x][y];
    for (int i=0;i<32;i++) if ((tx>>i)&1){
        for (int j=0;j<32;j++) if ((ty>>j)&1){
            tz|=((ll)1)<<(i^j);
        }
    }
    return a[x][y]=get_id(tz);
}
void dfs(int u,int fa,int val){
    vis[u]=1; V[u]=val;
    //cout<<u<<' '<<fa<<endl;
    for (auto e:h[u]){
        int v=e.F;
        if (key[v]||v==fa) continue;
        if (!vis[v]) dfs(v,u,val^e.S);
        else if (vis[v]==1){
            //cout << (V[u]^V[v]^e.S) << ' ' << u << endl;
            res=go(res,get_id(((ll)1)<<(V[u]^V[v]^e.S)));
        }
    }
    //cout<<"H"<<endl;
    vis[u]=2;
}
vector <pi> two;
vector <int> one;

int main(){
    scanf("%d%d",&n,&m);
    memset(a,-1,sizeof(a));
    for (int i=1;i<=m;i++){
        int u,v,w;scanf("%d%d%d",&u,&v,&w);
        h[u].pb((pi){v,w});
        h[v].pb((pi){u,w});
    }
    key[1]=-1;
    for (auto e:h[1]) key[e.F]=1,d[e.F]=e.S;
    for (auto e:h[1]) if (key[e.F]==1){
        int u=e.F;
        for (auto ee:h[u]){
            int v=ee.F;
            if (key[v]==1){
                key[u]=2; key[v]=2;
                d[v]^=ee.S;
                two.pb((pi){u,v});
            }
        }
        if (key[u]==1) one.pb(u);
    }
    dp[0]=1;
    for (int i=0;i<one.size();i++){
        memcpy(tmp,dp,sizeof(dp));
        int u=one[i];
        res=0; key[u]=0; dfs(u,0,0); key[u]=1;
        if (res!=-1){
            for (int j=0;j<=tot;j++){
                int now=go(res,j);
                if (now!=-1) add(tmp[now],dp[j]);
            }
        }
        memcpy(dp,tmp,sizeof(dp));
    }
    for (int i=0;i<two.size();i++){
        memcpy(tmp,dp,sizeof(dp));
        int u=two[i].F,v=two[i].S;
        int r1,r2;
        res=0; key[u]=0; dfs(u,0,0); r1=res; key[u]=2;
        res=0; key[v]=0; dfs(v,0,0); r2=res; key[v]=2;
        res=go(r1,r2);
        if (res!=-1){
            for (int j=0;j<=tot;j++){
                int now=go(res,j);
                if (now!=-1) add(tmp[now],dp[j]),add(tmp[now],dp[j]);
            }
        }
        res=go(res,get_id(1ll<<(d[u]^d[v])));
        //cout<<go(0,1)<<' '<<b[0]<<' '<<b[1]<<endl;
        if (res!=-1){
            for (int j=0;j<=tot;j++){
                int now=go(res,j);
                if (now!=-1) add(tmp[now],dp[j]);
            }
        }
        memcpy(dp,tmp,sizeof(dp));
        //for (int i=0;i<=tot;i++)cout<<b[i]<<' '<<dp[i]<<endl;
    }
    int ans=0;
    for (int j=0;j<=tot;j++) add(ans,dp[j]);
    printf("%d\n",ans);
    return 0;
}