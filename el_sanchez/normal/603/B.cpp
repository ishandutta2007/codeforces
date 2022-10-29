#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define db(x) cout << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 100500;
const ll MOD = 1E9 + 7;
  
ll p, k, q;
ll ans;

int main() {

	cin >> p >> k;

	if (k == 0) {
		ans = 1;
		forn(i, p - 1)
			ans = (ans * p) % MOD;
	} else {
		q = 0;
		ll t = 1;
		while (true) {
			t = (t * k) % p;
			q++;
			if (t == 1)
				break;	
		}

		assert((p - 1) % q == 0);
		t = (p - 1) / q;

		ans = 1;
		forn(i, t)
			ans = (ans * p) % MOD;

		if (k == 1)
			ans = (ans * p) % MOD;
	}
	
	cout << ans << '\n';
	
	return 0;
}