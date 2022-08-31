#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
const int maxn=2e5+10;
const int M=1000000007;
void add(int &x,int y){x+=y;if(x>=M)x-=M;}
void sub(int &x,int y){x-=y;if(x<0) x+=M;}
bool ban[maxn];
int n,k,a[maxn],sz[maxn],ans,cnt[maxn],way[maxn],mx,tc[maxn],tw[maxn];
int scnt[2][maxn],sway[2][maxn];
vector<pi> G[maxn];
void dfs(int u,int fa){
    sz[u]=1;
    for (auto e:G[u]){
        int v=e.F;
        if (ban[v]) continue;
        if (v==fa) continue;
        dfs(v,u); sz[u]+=sz[v];
    }
}
void dfs2(int u,int fa,int o,int sum,int dep){
    if (dep>k) return;
    mx=max(mx,dep);
    add(way[dep],1);
    add(cnt[dep],sum);
    for (auto e:G[u]){
        int v=e.F;
        if (ban[v]||v==fa) continue;
        dfs2(v,u,e.S,(sum+a[v])%M,dep+(e.S^o));
    }
}
int work(int *cnt,int *way,int *cnt2,int *way2,int val,int mx,int k){
    if (k<0) return 0;
    mx=min(mx,k);
    for (int i=0;i<=mx;i++){
        tc[i]=cnt[i];
        tw[i]=way[i];
        if (i){
            add(tc[i],tc[i-1]);
            add(tw[i],tw[i-1]);
        }
    }
    int ret=0;
    for (int i=0;i<=mx;i++){
        int j=min(mx,k-i);
        add(ret,1ll*val*way2[i]%M*tw[j]%M);
        add(ret,1ll*cnt2[i]*tw[j]%M);
        add(ret,1ll*way2[i]*tc[j]%M);
    }
    return ret;
}
void solve(int u){
    dfs(u,0);
    int r=u;
    while (1){
        int tmp=0;
        for (auto e:G[u]){
            int v=e.F;
            if (ban[v]||sz[v]>sz[u]) continue;
            if (sz[v]*2>sz[r]) tmp=v;
        }
        if (!tmp) break;
        u=tmp;
    }
    int SZ=min(sz[r],k);
    for (int i=0;i<=SZ;i++){
        scnt[0][i]=scnt[1][i]=0;
        sway[0][i]=sway[1][i]=0;
    }
    for (auto e:G[u]){
        int v=e.F;
        if (ban[v]) continue;
        int o=e.S;
        mx=0;
        dfs2(v,u,o,a[v],0);
        for (int i=0;i<=mx;i++){
            add(ans,2ll*way[i]*a[u]%M);
            add(ans,2*cnt[i]%M);
        }
        sub(ans,work(cnt,way,cnt,way,a[u],mx,k));
        for (int i=0;i<=mx;i++){
            add(scnt[o][i],cnt[i]);
            add(sway[o][i],way[i]);
            cnt[i]=0;
            way[i]=0;
        }
    }
    add(ans,work(scnt[0],sway[0],scnt[0],sway[0],a[u],SZ,k));
    add(ans,work(scnt[1],sway[1],scnt[1],sway[1],a[u],SZ,k));
    add(ans,work(scnt[0],sway[0],scnt[1],sway[1],a[u],SZ,k-1)*2%M);
    ban[u]=1;
    for (auto e:G[u]){
        int v=e.F;
        if (ban[v]) continue;
        solve(v);
    }
}
int main(){
    cin >> n >> k;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<n;i++){
        int u,v,w; cin >> u >> v >> w;
        G[u].pb((pi){v,w});
        G[v].pb((pi){u,w});
    }
    solve(1);
    ans=1ll*ans*(M+1)/2%M;
    for (int i=1;i<=n;i++) add(ans,a[i]);
    cout << ans << endl;
}