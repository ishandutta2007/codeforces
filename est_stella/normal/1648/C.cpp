#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second
#define em emplaces
#define eb emplace_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 1e9;
const ll INF = 1e18;
const ll Mod = 998244353;

int n, m;
ll fact[200010];
ll infact[200010];
ll cnt[200010];
int s[200010];
int t[200010];

ll tree[200010];

ll inv(ll a) {
    ll b = Mod - 2;
    ll ret = 1;
    while(b) {
        if(b & 1) ret = ret * a % Mod;
        a = a * a % Mod;
        b >>= 1;
    }
    return ret;
}

void update(int i, int x) {
    for(i; i <= 200000; i += i & -i) tree[i] += x;
}

ll sum(int i) {
    ll ret = 0;
    for(i; i; i -= i & -i) ret += tree[i];
    return ret;
}

int main() {
    fast;

    fact[0] = 1;
    for(int i=1; i<=200000; i++) fact[i] = fact[i-1] * i % Mod;
    infact[200000] = inv(fact[200000]);
    for(int i=200000; i>=1; i--) infact[i-1] = infact[i] * i % Mod;

    cin >> n >> m;

    for(int i=1; i<=n; i++) cin >> s[i], cnt[s[i]]++;
    for(int i=1; i<=m; i++) cin >> t[i];

    ll mul = 1;
    for(int i=1; i<=200000; i++) mul = mul * infact[cnt[i]] % Mod, update(i, cnt[i]);

    ll ans = 0;
    for(int i=1; i <= m; i++) {
        if(i > n) {
            ans += mul * fact[n-i+1] % Mod;
            ans %= Mod;
            break;
        }
        ans += mul * sum(t[i]-1) % Mod * fact[n-i] % Mod;
        ans %= Mod;

        if(!cnt[t[i]]) break;
        mul *= cnt[t[i]]--;
        mul %= Mod;
        update(t[i], -1);
    }

    cout << ans;
}