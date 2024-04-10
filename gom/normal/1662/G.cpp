#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
const int inf=1e9+7;
const ll INF=1e18;
const int N=1e6+5;
int n,sz[N],submx[N],cnt[N];
ll ans;
vector<int> c[N],g[N];
void dfs(int u){
    sz[u]=1;
    for(int v: c[u]){
        dfs(v);
        sz[u]+=sz[v];
        submx[u]=max(submx[u],sz[v]);
    }
}
pll dfs2(int u,int p){
    pll res(1,1);
    for(int v: g[u]) if(p!=v){
        auto T=dfs2(v,u);
        res.fi+=T.fi+T.se;
        res.se+=T.se;
    }
    return res;
}
void tryAns(int u){
    ll res=n,mx=0;
    for(int i=0;i<=n;i++) cnt[i]=0;
    for(int v: g[u]){
        auto T=dfs2(v,u);
        res+=T.fi;
        cnt[T.se]++;
    }
    for(int i=1;i<=n/2;i++) if(cnt[i]>=3){
        cnt[i*2]+=(cnt[i]-2)/2;
        cnt[i]-=(cnt[i]-2)/2*2;
    }
    bitset<N/2> dp;
    dp[0]=1;
    for(int i=1;i<=n/2;i++){
        for(int t=1;t<=cnt[i];t++){
            dp|=dp<<i;
        }
    }
    for(int i=1;i<=n/2;i++) if(dp[i]) mx=max(mx,i*((ll)n-1-i));
    ans=max(ans,res+mx);
}
void findCentroids(int u){
    bool found=false;
    for(int v: c[u]){
        if(sz[v]>=n/2) findCentroids(v);
        if(sz[v]>n/2) found=true;
    }
    if(!found) tryAns(u);
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    for(int i=2,p=1;i<=n;i++){
        cin>>p;
        c[p].emplace_back(i);
        g[p].emplace_back(i);
        g[i].emplace_back(p);
    }
    dfs(1);
    for(int i=1;i<=n;i++) if(max(n-sz[i],submx[i])<=n/2) tryAns(i);
    cout<<ans;
    return 0;
}