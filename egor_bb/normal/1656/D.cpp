#include <bits/stdc++.h> 
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(x) (int) ((x).size()) 
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define forab(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end() 
 
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) {
		ll n;
		cin >> n;
		if (n % 2 == 1) {
			cout << 2 << '\n';
		} else {
			ll left = 1;
			while(n % 2 == 0) {
				n /= 2;
				left *= 2;
			}
			if (n != 1 && (n + 1) / 2  <= left) {
				cout << n << '\n';
			} else if (n != 1 && left * 2 + 1 <= n) {
				cout << left * 2 << '\n';
			} else {
				cout << -1 << '\n';
			}
		}
	}
	return 0;
}