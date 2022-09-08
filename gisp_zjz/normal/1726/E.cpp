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
int n,g[maxn],h[maxn],f[maxn],nf[maxn],inv[maxn];
void add(int &x,int y){x+=y;if (x>=M)x-=M;}
int binom(int x,int y){
    return 1ll*f[x]*nf[y]%M*nf[x-y]%M;
}
void solve(){  
    cin >> n;
    int ans=0;
    for (int k=0;k*4<=n;k++){
        int cof=binom(n-k*2,k*2);
        add(ans,1ll*cof*g[n-k*4]%M*h[k]%M);
    }
    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    inv[1]=1; for (int i=2;i<maxn;i++) inv[i]=M-1ll*(M/i)*inv[M%i]%M;
    f[0]=nf[0]=1; for (int i=1;i<maxn;i++) f[i]=1ll*f[i-1]*i%M,nf[i]=1ll*nf[i-1]*inv[i]%M;
    g[0]=g[1]=1; for (int i=2;i<maxn;i++) g[i]=(g[i-1]+1ll*g[i-2]*(i-1))%M;
    h[0]=1; for (int i=1;i<maxn;i++) h[i]=2ll*h[i-1]*(i*2-1)%M;
    int _; cin >> _;
    while (_--) solve();
}