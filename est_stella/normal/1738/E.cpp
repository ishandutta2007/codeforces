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

ll pw(ll a, ll b) {
    ll ret = 1;
    while(b) {
        if(b & 1) ret = ret * a % Mod;
        a = a * a % Mod;
        b >>= 1;
    }
    return ret;
}

int n;
ll a[100010];
ll fact[200010];
ll infact[200010];

void solve() {
    cin >> n;
    map<ll, int> M;
    for(int i=1; i<=n; i++) cin >> a[i], a[i] += a[i-1], M[a[i]]++;
    M[a[n]]--;
    ll ans = 1;
    for(auto i : M) {
        if(i.fi * 2 > a[n]) break;
        if(i.fi * 2 == a[n]) {
            ans = ans * pw(2, i.se) % Mod;
        }
        else if(M.find(a[n]-i.fi) != M.end()) {
            int x = i.se;
            int y = M[a[n]-i.fi];

            ans = ans * fact[x+y] % Mod * infact[x] % Mod * infact[y] % Mod;
        }
    }
    cout << ans << "\n";
}

int main() {
    fast;

    fact[0] = 1;
    for(int i=1; i<=200000; i++) fact[i] = fact[i-1] * i % Mod;
    infact[200000] = pw(fact[200000], Mod - 2);
    for(int i=200000; i>=1; i--) infact[i-1] = infact[i] * i % Mod;

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}