#include <bits/stdc++.h>                          

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double LD;
typedef unsigned int uint;

const int INF = int(1e9) + 7;
const ll INFll = ll(1e18) + 7;
const int MAXN = int(3e2) + 10;

#define pii pair <int, int>
#define pll pair <ll, ll>
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(x) (int)((x).size()) 
#define forn(i,n) for (int i = 0; (i) < (n); ++i)
#define fornr(i,n) for (int i = (n) - 1; (i) >= 0; --i)
#define forab(i,a,b) for (int i = (a); (i) < (b); ++i)
#define forba(i,a,b) for (int i = (b) - 1; (i) >= (a); --i)
#define forit(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(),(c).end() 
#define problem "test"

const int N = (1e5) + 100;
                     

int main(){ 
//	freopen (problem".in", "r", stdin);
//	freopen (problem".out", "w", stdout);
	ll p, k;
	cin >> p >> k;
	if (k == 0){
		ll ans = 1;
		forn(i, p - 1) ans = (ans * p) % INF;
		cout << ans % INF << '\n';
		return 0;
	}                   
	ll t = k, l = 1;
	while (t != 1) {
		l++;
		t = (k * t) % p;
	}
	int c = (p - 1) / l;
	if (k == 1) c++;
	ll ans = 1;
	forn(i, c) ans = (ans * p) % INF;
	cout << ans % INF << '\n';
	return 0;
}