#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = (a-1); i >= (b); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int t;
	cin >> t;
	while (t--) {
		ll n, m;
		cin >> n >> m;
		ll x = 0;
		rrep(i,31,0) {
			if (n&(1LL<<i)) {
				if (m&(1LL<<i)) {
				} else {
					break;
				}
			} else {
				if (m&(1LL<<i)) {
					x |= (1LL<<i);
				} else {
					if ((m&((1LL<<i)-1)) == (1LL<<i)-1) {
						x |= (1LL<<i);
						break;
					}
				}
			}
		}
		cout << x << endl;
	}
}