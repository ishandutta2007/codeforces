#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define db(x) cout << #x << " = " << x << endl

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const int INF = 1e9;
const int MAXN = 111;

int n;
int a[MAXN], used[MAXN];
ll LCM;

int main() {

	cin >> n;
	forn(i, n) {
		cin >> a[i];
		a[i]--;	
	}
	
	LCM = 1;
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			int S = i;
			used[S] = 1;
			
			int v = a[S];
			int len = 1;
		    while (!used[v]) {
		    	used[v] = 1;
		    	v = a[v];	
		    	len++;
		    }
		    
		    if (v != S) {
		    	cout << -1 << '\n';
		    	return 0;	
		    }
		    
		    ll x = len;
		    if (!(x & 1)) {
		    	x /= 2;
		    }
		    
    		ll g = __gcd(LCM, x);
			LCM /= g;
			LCM *= x; 
		}
	}
	
	cout << LCM << '\n';
	
    return 0;
}