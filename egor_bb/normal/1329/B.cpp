#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(x) (int) ((x).size())
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define forab(i, a, b) for (int i = (a); (i) < (b); ++i)
#define all(c) (c).begin(), (c).end()
 
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		ll d, m;
		cin >> d >> m;
		ll cur = 1;
		for(ll maxD = 1; maxD <= d; maxD *= 2) {
			ll got = min(maxD, d - maxD + 1);
			cur = (cur + cur * 1ll * got) % m;
		}
		cur = (cur - 1 + m) % m;
		cout << cur << '\n';
	}
	
    return 0;
}