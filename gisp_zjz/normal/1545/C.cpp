#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef vector<int>vi;
const int maxn=505;
const int M=998244353;
int c[505][505],a[1005][505],n,_;
bool f[1005][1005],vis[1005];
vi ans;
void dfs(int u,int o){
    if (!o) ans.pb(u); vis[u]=1;
    for (int i=1;i<=n*2;i++) if (!vis[i]&&f[u][i]) dfs(i,o^1);
}
void del(int x){
    vis[x]=1;
    for (int i=1;i<=n;i++) c[i][a[x][i]]--;
}
void solve(){
    scanf("%d",&n);
    memset(vis,0,sizeof(vis));
    memset(c,0,sizeof(c));
    memset(f,0,sizeof(f));
    ans.clear();
    for (int i=1;i<=n*2;i++){
        for (int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
            c[j][a[i][j]]++;
        }
        for (int j=1;j<i;j++)
            for (int k=1;k<=n;k++)
                if (a[i][k]==a[j][k]){
                    f[i][j]=f[j][i]=1;
                    break;
                }
    }
    c[0][0]=1001;
    while (1){
        int p=0,q=0;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                if (c[i][j]>0&&c[i][j]<c[p][q]) p=i,q=j;
        if (c[p][q]>1) break;
        int w=-1;
        for (int i=1;i<=n*2;i++)
            if (!vis[i]&&a[i][p]==q){
                w=i;
                break;
            }
        assert(w!=-1);
        del(w);ans.pb(w);
        for (int i=1;i<=n*2;i++) if (!vis[i]&&f[i][w]) del(i);
    }
    int tot=1;
    for (int i=1;i<=n*2;i++) if (!vis[i]) dfs(i,0),tot=tot*2%M;
    printf("%d\n",tot);
    sort(ans.begin(),ans.end());
    for (auto x:ans) printf("%d ",x);puts("");
}
int main(){
    scanf("%d",&_);
    while (_--) solve();
}