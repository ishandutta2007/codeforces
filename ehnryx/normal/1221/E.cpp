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
	while (T--) {
		int a,b;
		cin >> a >> b;
		string s;
		cin >> s;
		s.push_back('X');
		int pre = -1;
		vector<int> vals;
		int small = 0;
		int med = 0;
		int large = 0;
		for(int i=0;i<s.size();i++) {
			if(s[i] == 'X') {
				int len = i-pre-1;
				assert(len >= 0);
				if(len >= b) {
					vals.push_back(len);
					if(len<a) small++;
					else if(len<2*b) med++;
					else large++;
				}
				pre = i;
			}
		}

		bool win = false;
		for(int it:vals) {
			for(int i=0;i+a<=it;i++) {
				int left = i;
				int right = it - (i+a);
				int nsmall = small + (b<=left && left<a) + (b<=right && right<a) - (b<=it && it<a);
				int nmed = med + (a<=left && left<2*b) + (a<=right && right<2*b) - (a<=it && it<2*b);
				int nlarge = large + (2*b<=left) + (2*b<=right) - (2*b<=it);
				if(nsmall || nlarge || nmed%2) {
					// bob wins
				} else {
					win = true;
				}
			}
		}
		if(win) cout << "YES" << nl;
		else cout << "NO" << nl;
	}

	return 0;
}