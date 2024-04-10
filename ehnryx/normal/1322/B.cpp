//#pragma GCC optimize("O3")
//#pragma GCC target("sse4,avx2,abm,fma")
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
const ll MOD = 1e9+7;
const ld EPS = 1e-13;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 4e5 + 1;
const int L = 25;
int a[N], b[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}

	int ans = 0;
	for(int j=0; j<L; j++) {
		//transform(a, a+n, b, [=] (int x) { return x % (1<<(j+1)); });
		for(int i=0; i<n; i++) {
			b[i] = a[i] % (1<<(j+1));
		}
		sort(b, b+n);
		int cnt = 0;
		for(int i=0; i<n; i++) {
			{
				auto lb = lower_bound(b+i+1, b+n, (1<<j) - b[i]);
				auto rb = lower_bound(b+i+1, b+n, (1<<(j+1)) - b[i]);
				cnt ^= (rb - lb) % 2;
			}
			{
				auto lb = lower_bound(b+i+1, b+n, (1<<(j+1)) + (1<<j) - b[i]);
				auto rb = lower_bound(b+i+1, b+n, (1<<(j+2)) - b[i]);
				cnt ^= (rb - lb) % 2;
			}
		}
		ans |= cnt << j;
	}
	cout << ans << nl;

	return 0;
}