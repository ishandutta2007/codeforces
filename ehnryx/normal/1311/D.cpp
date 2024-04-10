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
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int M = 1e4;

// TODO
// double-check correctness
// read limits carefully
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int T;
	cin >> T;
	while(T--) {
		int a, b, c;
		cin >> a >> b >> c;
		tuple<int,int,int> res;
		int best = INF;
		for(int i=-a+1; a+i<=M; i++) {
			int A = a+i;
			int fb = b/A;
			for(int j=-fb+1; (fb+j)*A<=2*M; j++) {
				int B = (fb+j)*A;
				int fc = max(1, c/B);
				int C = (abs(fc*B - c) < abs((fc+1)*B - c) ? fc*B : (fc+1)*B);
				int cur = abs(A-a) + abs(B-b) + abs(C-c);
				if(cur < best) {
					best = cur;
					res = make_tuple(A, B, C);
				}
			}
		}
		auto [A, B, C] = res;
		cout << best << nl;
		cout << A << " " << B << " " << C << nl;
	}

	return 0;
}