//#pragma GCC optimize("O3")
//#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;
const ld EPS = 1e-9;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int L = 18;
const int N = 1<<L;
int a[N];
int dsu[N];

int find(int i) {
	if(dsu[i] == -1) return i;
	return dsu[i] = find(dsu[i]);
}
void link(int i, int j) {
	i = find(i); j = find(j);
	if(i != j) dsu[i] = j;
}

struct Two {
	int first, second;
	Two(): first(-1), second(-1) {}
	void update(int v) {
		if(v == -1) return;
		if(first == -1) {
			first = v;
		} else if(find(v) != find(first)) {
			if(a[v] > a[first]) {
				second = first;
				first = v;
			} else if(second == -1 || a[v] > a[second]) {
				second = v;
			}
		} else if(a[v] > a[first]) {
			first = v;
		}
	}
};

Two dp[N];
pair<int,int> maxe[N];

// TODO
// double-check correctness
// read limits carefully
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	memset(dsu, -1, sizeof dsu);

	int n;
	cin >> n;
	ll sum = 0;
	for(int i=0; i<n; i++) {
		cin >> a[i];
		sum += a[i];
	}

	ll ans = 0;
	int groups = n+1;
	while(groups > 1) {
		for(int i=0; i<N; i++) {
			dp[i] = Two();
		}
		for(int i=0; i<=n; i++) {
			dp[a[i]].update(i);
			maxe[i] = make_pair(-1, -1);
		}
		for(int j=0; j<L; j++) {
			for(int bm=0; bm<N; bm++) {
				if(bm & 1<<j) {
					dp[bm].update(dp[bm^1<<j].first);
					dp[bm].update(dp[bm^1<<j].second);
				}
			}
		}
		for(int i=0; i<=n; i++) {
			int o = a[i] ^ (N-1);
			if(find(i) != find(dp[o].first)) {
				pair<int,int> cur(a[i] + a[dp[o].first], dp[o].first);
				maxe[find(i)] = max(maxe[find(i)], cur);
			} else if(dp[o].second != -1) {
				pair<int,int> cur(a[i] + a[dp[o].second], dp[o].second);
				maxe[find(i)] = max(maxe[find(i)], cur);
			}
		}
		for(int i=0; i<=n; i++) {
			if(find(i) != i) continue;
			assert(maxe[i].first != -1);
			if(find(i) != find(maxe[i].second)) {
				link(i, maxe[i].second);
				ans += maxe[i].first;
				groups--;
			}
		}
	}
	assert(groups == 1);

	cout << ans - sum << nl;

	return 0;
}