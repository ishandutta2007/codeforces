#include<bits/stdc++.h>  
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(0);
#define fi first
#define se second
#define pb push_back
#define em emplace
#define eb emplace_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define pre(x) cout<<fixed; cout.precision(x);

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 1e9;
const ll INF = 1e18;
const ll Mod = 998244353;

ll inv(ll a) {
    ll e = Mod - 2, ret = 1;
    while(e) {
        if(e & 1) ret = ret * a % Mod;
        a = a * a % Mod;
        e >>= 1;
    }
    return ret;
}

int n, m;
ll f[4000010];
ll invf[4000010];
int x[2000010];
int y[2000010];
int Y[2000010];
int chk[2000010];

ll tree[2000010];

void update(int i, int x) {
    for( ; i<=2000000; i += i&-i) tree[i] += x;
}

ll sum(int i) {
   ll ret = 0;
    for( ; i; i -= i & -i) ret += tree[i];
    return ret; 
}

void solve() {
    cin >> n >> m;

    for(int i=1; i<=m; i++) {
        cin >> x[i] >> y[i];
    }

    int cnt = 0;
    for(int i=m; i>=1; i--) {
        int l = 1, r = n;
        while(l != r) {
            int mid = l + r >> 1;
            if(sum(mid) >= y[i]) r = mid;
            else l = mid+1;
        }
        Y[i] = l;
        
        update(Y[i], -1);
        chk[Y[i]] = x[i];
        
        if(chk[Y[i]+1] < chk[Y[i]]) cnt++;
    }

    for(int i=1; i<=m; i++) {
        update(Y[i], 1);
        chk[Y[i]] = 0;
    }

    cout << f[2*n - cnt - 1] * invf[n] % Mod * invf[n-cnt-1] % Mod << "\n";
}

int main() {
    fast;

    f[0] = 1;
    for(int i=1; i<=4000000; i++) f[i] = f[i-1] * i % Mod;
    invf[4000000] = inv(f[4000000]);
    for(int i=4000000; i>=1; i--) invf[i-1] = invf[i] * i % Mod;

    for(int i=1; i<=2000000; i++) update(i, 1);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}