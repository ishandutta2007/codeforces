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

ll a[N], ans = 0;             

int main(){ 
//	freopen (problem".in", "r", stdin);
//	freopen (problem".out", "w", stdout);
	ll n, k;
	cin >> n >> k;
	forn(i, n) cin >> a[i];
	if (k%2==0){
		forn(i, n){   
			if ((a[i] & 1) && a[i] != 1) continue;
			if (a[i] == 2) ans ^= 2;
			else ans ^= 1;
		}
	}  else {
		forn(i, n){
			if ((a[i] & 1) && a[i] != 1 && a[i] != 3) continue;
			if (a[i] == 2) continue;
			if (a[i] == 1 || a[i] == 3) ans ^= 1;
			else {
				int l = 0;
				while (a[i] % 2 == 0){
					a[i] /= 2; l++;
				}
				if (a[i] == 3) l++;
				if (l & 1) ans ^= 1;
				else ans ^= 2;
			}                   
		}
	}
	if (!ans) cout << "Nicky\n";
	else cout << "Kevin\n";       
	return 0;
}