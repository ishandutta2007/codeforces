#include<bits/stdc++.h>
#define maxn 123456
#define F first
#define S second

using namespace std;
typedef pair<int,int> pi;
vector <pi> h[maxn];
int n,l,r,mid,k,w,rt,t,pre[maxn],dep[maxn],pp[maxn],res;
bool f[maxn];
pi dp[maxn];

void dfs(int u,int fa){
    pre[u]=fa; dep[u]=dep[fa]+1;
    for (int i=0;i<h[u].size();i++){
        int v=h[u][i].F;
        if (v==fa) continue;
        dfs(v,u); pp[v]=h[u][i].S;
        int res=dp[v].F+h[u][i].S;
        if (res>dp[u].F) dp[u].S=dp[u].F,dp[u].F=res;
        else if (res>dp[u].S) dp[u].S=res;
    }
}

bool check(int x){
    memset(f,0,sizeof(f));
    int cnt=0;
    for (int i=1;i<=n;i++) if (i==rt||dp[i].F+pp[i]>x) f[i]=true,cnt++;
    if (cnt>k) return false;
    for (int o=0;o<2;o++){
        t=-1; for (int i=1;i<=n;i++) if (f[i]&&(t==-1||dep[i]>dep[t])) t=i;
        if (t==-1) return true;
        while (t!=rt) {
            if (!f[t]) return false;
            f[t]=false,t=pre[t];
        }
    }
    for (int i=1;i<=n;i++) if (i!=rt&&f[i]) return false;
    return true;
}

int main(){
    cin >> n >> k;
    for (int i=1;i<n;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        h[u].push_back({v,w});
        h[v].push_back({u,w});
    }
    rt=1;dfs(1,0);res=dp[1].S;
    while (true){
        t=-1;
        for (int i=0;i<h[rt].size();i++){
            int v=h[rt][i].F;
            if (v==pre[rt]) continue;
            if (dp[rt].F==dp[v].F+pp[v]&&res<dp[v].F) t=v,res=max(res+pp[v],dp[v].S);
        }
        if (t==-1) break;
        rt=t;
    }
    for (int i=1;i<=n;i++) dp[i].F=dp[i].S=0;
    dfs(rt,0);
    l=-1; r=2e9;
    while (r-l>1){
        mid=(l+r)/2;
        if (check(mid)) r=mid; else l=mid;
    }
    cout << r << endl;
    return 0;
}