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

void solve() {
	int n, k;
	cin >> n >> k;
	//n = 4<<(rand()%15);
	//k = rand()%n;
	vector<int> a, b;
	rep(i,0,n/2) {
		a.push_back(i);
		b.push_back(n-1-i);
	}
	int x = n/2;
	while (x) {
		if (k&x) {
			bool ok = false;
			rep(i,0,min(1, sz(a))) {
				rep(j,0,sz(b)) {
					if (ok)
						break;
					int pre = (a[i]&b[i])+(a[j]&b[j]);
					swap(a[i], a[j]);
					int after = (a[i]&b[i])+(a[j]&b[j]);
					if (after-pre == x) {
						ok = true;
						break;
					}
					swap(a[i], a[j]);
				}
			}
			rep(i,0,min(1, sz(a))) {
				rep(j,0,sz(b)) {
					if (ok)
						break;
					int pre = (a[i]&b[i])+(a[j]&b[j]);
					swap(a[i], b[j]);
					int after = (a[i]&b[i])+(a[j]&b[j]);
					if (after-pre == x) {
						ok = true;
						break;
					}
					swap(a[i], b[j]);
				}
			}
			if (!ok) {
				cout << "-1" << endl;
				assert(n == 4);
				return;
			}
		}
		x /= 2;
	}
	int res = 0;
	rep(i,0,n/2) {
		cout << a[i] << " " << b[i] << endl;
		res += (a[i]&b[i]);
	}
	assert(res == k);
	/*int x = 1;
	while (k) {
		if (k%2) {
			swap(a[0], a[x]);
		}
		k /= 2;
		x *= 2;
	}
	rep(i,0,n/2) {
	}*/
}

int main() {
	//while (true) solve();
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int t;
	cin >> t;
	while (t--)
		solve();
}