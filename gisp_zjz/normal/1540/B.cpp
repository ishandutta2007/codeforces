#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int,int>pi;
const int maxn=1e6+10;
const int M=1000000007;
const int inv2=(M+1)/2;
vi G[205];
void add(int &x,int y){x+=y;if (x>=M)x-=M;}
int n,rt,sz[205],pre[205],dep[205],ans,inv[205];
int f[205][205];
void dfs(int u,int fa){
    sz[u]=1; pre[u]=fa;
    for (auto v:G[u]){
        if (v==fa) continue;
        dep[v]=dep[u]+1;
        dfs(v,u); sz[u]+=sz[v];
    }
}
int main(){
    for (int i=1;i<=200;i++) f[i][0]=1,f[0][i]=0;
    for (int i=1;i<=200;i++)
        for (int j=1;j<=200;j++)
            f[i][j]=1ll*inv2*(f[i-1][j]+f[i][j-1])%M;
    cin >> n;
    inv[1]=1; for (int i=2;i<=n;i++) inv[i]=M-1ll*(M/i)*inv[M%i]%M;
    for (int i=1;i<n;i++){
        int u,v; cin >> u >> v;
        G[u].pb(v); G[v].pb(u);
    }
    for (int i=1;i<=n;i++){
        rt=i; dep[i]=0;
        dfs(i,0);
        for (int j=i+1;j<=n;j++){
            int t=j,d1=dep[j],d2=0,last=0;
            while (t!=i){
                add(ans,1ll*f[d1][d2]*(sz[t]-last)%M);
                d1--; d2++;
                last=sz[t]; t=pre[t];
            }
        }
    }
    cout << 1ll*inv[n]*ans%M << endl;
    return 0;
}