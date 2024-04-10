#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second
#define em emplace
#define eb emplace_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 1e9;
const ll INF = 1e18;
const ll Mod = 1e9 + 7;

ll inv(ll a) {
    ll b = Mod - 2, ret = 1;
    while(b) {
        if(b & 1) ret = a * ret % Mod;
        a = a * a % Mod;
        b >>= 1;
    }
    return ret;
}

int n;
int a[2000010];
ll fact[4000010];
ll infact[4000010];

ll f(int x, int y) {
    return fact[x+y] * infact[x] % Mod * infact[y] % Mod;
}

void solve() {
    fact[0] = 1;
    for(int i=1; i<=400000; i++) fact[i] = fact[i-1] * i % Mod;
    infact[400000] = inv(fact[400000]);
    for(int i=400000; i>=1; i--) infact[i-1] = infact[i] * i % Mod;

    cin >> n;
    for(int i=0; i<=n; i++) cin >> a[i];

    if(a[0] == 0) {
        cout << 0;
        return;
    }

    ll ans = Mod-1;
    int idx = a[0];
    a[n+1] = 0;
    for(int i=0; i<=n+1; i++) {
        if(a[i] > 0) ans += f(i, a[i]-1);
        while(idx > a[i]) {
            idx--;
            ans += f(i-1, idx);
        }
        ans %= Mod;
    }

    cout << ans;
}

int main() {
    fast;

    solve();
}