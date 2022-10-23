#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<ll,ll>pi;
typedef vector<int> vi;
const int inf=1e9+10;
const int maxn=1e6+10;
const int M=998244353;
int kase=0;
int n,m,d[505][505];
int u[maxn],v[maxn],w[maxn];
void Min(int &x,int y){
    if (x>y) x=y;
}
void solve(){
    cin >> n >> m;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            d[i][j]=(i==j)?0:inf;
    for (int i=0;i<m;i++){
        cin >> u[i] >> v[i] >> w[i];
        d[u[i]][v[i]]=d[v[i]][u[i]]=1;
    }
    for (int k=1;k<=n;k++)
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                Min(d[i][j],d[i][k]+d[k][j]);
    ll ans=1e15;
    for (int i=0;i<m;i++){
        int ret=inf,x=u[i],y=v[i];
        for (int z=1;z<=n;z++) Min(ret,min(d[z][x],d[z][y])+2+d[z][1]+d[z][n]);
        Min(ret,d[x][1]+d[y][n]+1);
        Min(ret,d[x][n]+d[y][1]+1);
        ans=min(ans,1ll*ret*w[i]);
    }
    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _; cin >> _;
    while (_--) solve();
}