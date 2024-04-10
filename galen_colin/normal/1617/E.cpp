#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

int cost_zero(int x) {
    if (x == 0)
        return 0;

    x >>= __builtin_ctz(x) + 1;

    bitset<31> b(x);
    int ans = 0;
    for (int i = 0, j = 0; i < b.size(); i = j) {
        while (j < b.size() && b[i] == b[j])
            j++;

        ans++;
    }

    return ans;
}

int cost(ll x, ll y) {
    if (__builtin_ctzll(x) != __builtin_ctzll(y)) {
        return cost_zero(x) + cost_zero(y);
    }
	x >>= __builtin_ctzll(x) + 1;
	    y >>= __builtin_ctzll(y) + 1;
    ll ans = 0;
	while (x != y) {
		if (x < y) swap(x, y);
		ll v = 63 - __builtin_clzll(x);
		x ^= (1LL << (v + 1)) - 1;
		++ans;		
	}
	return ans;
}


int n, a[MAXN];

int furthest(int x) {
    ar<int, 2> ans{0, x};
    for (int y = 0; y < n; y++) {
        ans = max(ans, {cost(a[y], a[x]), y});
    }
    return ans[1];
}
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int x = furthest(0);
    int y = furthest(x);
    cout << x+1 << ' ' << y+1 << ' ' << cost(a[x], a[y]) << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}