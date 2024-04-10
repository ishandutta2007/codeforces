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
const ld EPS = 1e-9;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());



int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	string s, t;
	cin >> s >> t;
	int n = s.size();
	multiset<int> S, T;
	for(char c : s) {
		S.insert(c);
	}
	for(char c : t) {
		T.insert(c);
	}

	int half = (n+1)/2;
	while(S.size() > half) {
		S.erase(prev(S.end()));
	}
	while(T.size() > n-half) {
		T.erase(T.begin());
	}

	vector<char> ans(n);
	int f = 0;
	int b = n;
	for(int i=0; i<n; i++) {
		if(i%2 == 0) {
			if(!T.empty() && *S.begin() >= *T.rbegin()) {
				ans[--b] = *S.rbegin();
				S.erase(prev(S.end()));
			} else {
				ans[f++] = *S.begin();
				S.erase(S.begin());
			}
		} else {
			if(!S.empty() && *T.rbegin() <= *S.begin()) {
				ans[--b] = *T.begin();
				T.erase(T.begin());
			} else {
				ans[f++] = *T.rbegin();
				T.erase(prev(T.end()));
			}
		}
	}
	for(int i=0; i<n; i++) {
		cout << ans[i];
	}
	cout << nl;

	return 0;
}