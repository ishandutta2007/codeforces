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
const ld EPS = 1e-11;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 1e6 + 1;

/*
 *  len[2*i] = size of longest odd palindrome around i,
 *  len[2*i+1] = longest even palindrome at i and i+1
 */
int len[2*N];
void find_pals(const string& s) {
  len[0] = 1, len[1] = 0; int d;
  for (int i = 1; i+1 < 2*(int)s.size(); i += d) { int& p = len[i];
    int left = (i - p - 1)/2, right = (i + p + 1)/2;
    while (0 <= left && right < (int)s.size() && s[left] == s[right])
      --left, ++right, p += 2;
    for (d = 1; len[i-d] < p-d; ++d) len[i+d] = len[i-d];
    len[i+d] = p-d; }
}

set<int> st[2*N], fin[2*N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int T;
	cin >> T;
	while(T--) {
		string s;
		cin >> s;
		find_pals(s);
		int n = s.size();
		for(int i=0; i<n; i++) {
			st[i].clear();
			fin[i].clear();
		}

		for(int i=0; i<n; i++) {
			st[i - len[2*i]/2].insert(len[2*i]);
			fin[i + len[2*i]/2].insert(len[2*i]);
			if(i+1 < n && len[2*i+1]) {
				st[i - len[2*i+1]/2 + 1].insert(len[2*i+1]);
				fin[i + len[2*i+1]/2].insert(len[2*i+1]);
			}
		}

		bool start = true;
		int best = 1;
		int id = 0;
		for(int i=0; i<n && 2*i<=n; i++) {
			int cur = 2*i;
			int want = n - 2*i;
			bool t = true;
			auto it = st[i].upper_bound(want);
			if(it != st[i].begin()) {
				cur = max(cur, 2*i + *prev(it));
			}
			auto jt = fin[n-1-i].upper_bound(want);
			if(jt != fin[n-1-i].begin()) {
				if(2*i + *prev(jt) > cur) t = false;
				cur = max(cur, 2*i + *prev(jt));
			}
			assert(cur <= n);
			if(cur > best) {
				best = cur;
				id = i;
				start = t;
			}
			if(s[i] != s[n-1-i]) {
				break;
			}
		}

		for(int i=0; i<id; i++) {
			cout << s[i];
		}
		if(start) {
			for(int j=0; j<best-2*id; j++) {
				cout << s[id+j];
			}
		} else {
			for(int j=0; j<best-2*id; j++) {
				cout << s[n-1-id-j];
			}
		}
		for(int i=n-id; i<n; i++) {
			cout << s[i];
		}
		cout << nl;
	}

	return 0;
}