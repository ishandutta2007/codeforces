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
const int M=1000000007;
int kase=0;
int n,a[maxn],f[maxn],nf[maxn],inv[maxn];
int C(int x,int y){
    return 1ll*f[x]*nf[y]%M*nf[x-y]%M;
}
void add(int &x,int y){x+=y;if (x>=M)x-=M;}
void init(){
    inv[1]=1; for (int i=2;i<maxn;i++) inv[i]=M-1ll*(M/i)*inv[M%i]%M;
    nf[0]=f[0]=1; for (int i=1;i<maxn;i++) f[i]=1ll*f[i-1]*i%M,nf[i]=1ll*nf[i-1]*inv[i]%M;
}
void solve(){
    init();
    cin >> n;
    for (int i=0;i<=n;i++) cin >> a[i];
    int ans=0;
    for (int i=0;i<=n;i++) if (a[i]) add(ans,C(i+a[i],i+1));
    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _; _=1;
    while (_--) solve();
}