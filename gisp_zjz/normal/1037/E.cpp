#include<bits/stdc++.h>
#define maxn 323456
#define M 1000000007
#define F first
#define S second

using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
vector<pi> h[maxn];
int x[maxn],y[maxn],d[maxn],n,m,k,ans[maxn],cnt;
bool f[maxn],g[maxn];
ll pow_(ll x,ll y){
    ll rt=1;
    while (y){
        if (y&1) rt=rt*x%M;
        x=x*x%M;
        y>>=1;
    }
    return rt;
}
queue <int> q;
void work(){
    while (!q.empty()){
        int u=q.front(); q.pop(); cnt--;
        for (int i=0;i<h[u].size();i++){
            int v=h[u][i].F,w=h[u][i].S;
            if (g[w]) continue;
            d[x[w]]--; d[y[w]]--; g[w]=true;
            if (!f[v]&&d[v]<k) f[v]=true,q.push(v);
        }
    }
}
int main(){
    cin >> n >> m >> k; cnt=n;
    for (int i=1;i<=m;i++) {
        scanf("%d%d",&x[i],&y[i]);
        h[x[i]].push_back({y[i],i});
        h[y[i]].push_back({x[i],i});
        d[x[i]]++; d[y[i]]++;
    }
    for (int i=1;i<=n;i++) if (d[i]<k&&!f[i]) f[i]=true,q.push(i);
    work();
    for (int i=m;i>=1;i--){
        ans[i]=cnt;
        if (g[i]) continue;
        d[x[i]]--; d[y[i]]--; g[i]=true;
        if (d[x[i]]<k&&!f[x[i]]) f[x[i]]=true,q.push(x[i]);
        if (d[y[i]]<k&&!f[y[i]]) f[y[i]]=true,q.push(y[i]);
        work();
    }
    for (int i=1;i<=m;i++) printf("%d\n",ans[i]);
    return 0;
}