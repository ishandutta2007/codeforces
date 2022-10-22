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



int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int T;
	cin >> T;
	while(T--) {
		string s, t;
		cin >> s >> t;

		int n = s.size();
		int m = t.size();
		if(m<n) {
			cout << "NO" << nl;
			continue;
		}

		vector<int> scnt(26,0);
		for(char c:s) {
			scnt[c-'a']++;
		}

		vector<int> tcnt(26,0);
		for(int i=0; i<n; i++) {
			tcnt[t[i]-'a']++;
		}
		bool ok = (tcnt == scnt);
		for(int i=n; i<m; i++) {
			tcnt[t[i]-'a']++;
			tcnt[t[i-n]-'a']--;
			ok |= (tcnt == scnt);
		}
		if(ok) cout << "YES" << nl;
		else cout << "NO" << nl;
	}

	return 0;
}