#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(NULL)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define pre(a) cout<<fixed; cout.precision(a)

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 1e9;
const ll INF = 1e18;

int n, q;
ll a[200010];
ll cnt[200010];
ll ans;
map<pii, int> M;

int main() {
	fast;

	cnt[0] = inf;
	cin >> n;

	for(int i=1; i<=n; i++) {
		cin >> a[i];
		ans += a[i];
	}

	cin >> q;

	while(q--) {
		int s, t, u;
		cin >> s >> t >> u;

		int x = M[{s,t}];
		if(x > 0) ans -= max(0LL, a[x] - cnt[x]); 
		cnt[x]--;
		if(x > 0) ans += max(0LL, a[x] - cnt[x]);

		ans -= max(0LL, a[u] - cnt[u]);
		M[{s,t}] = u;
		cnt[u]++;
		ans += max(0LL, a[u] - cnt[u]);

		cout << ans << "\n";
	}
}