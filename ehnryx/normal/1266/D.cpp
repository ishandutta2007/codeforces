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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-13;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

struct Edge {
	int a, b; ll c;
};

const int N = 1e5+1;
ll in[N], out[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n, m;
	cin >> n >> m;
	for(int i=0; i<m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		out[a] += c;
		in[b] += c;
	}

	for(int i=1; i<=n; i++) {
		ll rem = min(in[i], out[i]);
		in[i] -= rem;
		out[i] -= rem;
	}

	vector<Edge> ans;
	for(int i=1, j=1; i<=n; i++) {
		while(in[i] > 0) {
			ll use = min(in[i], out[j]);
			assert(use >= 0);
			if(use) {
				in[i] -= use;
				out[j] -= use;
				ans.push_back({j,i,use});
			}
			if(out[j] == 0) {
				j++;
			}
		}
	}

	cout << ans.size() << nl;
	for(const auto& [a,b,c]:ans) {
		cout << a << " " << b << " " << c << nl;
	}

	return 0;
}