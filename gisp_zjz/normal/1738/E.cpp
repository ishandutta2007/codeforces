#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int>pi;
typedef vector<int> vi;
const int inf=1e9+10;
const int maxn=1e6+10;
const int M=998244353;
int kase=0;
int p2[maxn],f[maxn],nf[maxn],inv[maxn],ans;
int n,a[maxn];
map<ll,pi> B;
void init(){
    inv[1]=1; for (int i=2;i<maxn;i++) inv[i]=M-1ll*(M/i)*inv[M%i]%M;
    f[0]=nf[0]=1; for (int i=1;i<maxn;i++) f[i]=1ll*f[i-1]*i%M,nf[i]=1ll*nf[i-1]*inv[i]%M;
    p2[0]=1; for (int i=1;i<maxn;i++) p2[i]=p2[i-1]*2%M;
}
void add(int &x,int y){
    x+=y; if (x>=M)x-=M;
}
int C(int x,int y){
    return 1ll*f[x]*nf[y]%M*nf[x-y]%M;
}
int solve(int x,int y){
    int ret=0;
    for (int i=0;i<=min(x,y);i++) add(ret,1ll*C(x,i)*C(y,i)%M);
    return ret;
}
void solve(){
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    ll sum=0; B.clear();
    for (int i=1;i<=n;i++){
        sum+=a[i];
        B[sum].F++;
    }
    sum=0;
    for (int i=n;i>=1;i--){
        sum+=a[i];
        B[sum].S++;
    }
    ans=1;
    if (sum==0){
        cout << p2[n-1] << endl;
        return;
    }
    for (auto nd:B){
        ll s=nd.F;
        pi tmp=nd.S;
        if (s*2>sum) break;
        if (s*2==sum) ans=1ll*ans*p2[tmp.F]%M;
        else ans=1ll*ans*solve(tmp.F,tmp.S)%M;
    }
    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int _; cin >> _;
    while (_--) solve();
}