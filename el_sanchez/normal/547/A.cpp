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

using namespace std;

typedef long long ll;
typedef long double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const int INF = 1E9;        
const int MAXN = 1000500;
      
ll m, h[2], a[2], x[2], y[2], cur;
ll X1, Y1;
ll len;
ll ans;
int step[MAXN];

int main() {

	cin >> m;
	cin >> h[0] >> a[0];
	cin >> x[0] >> y[0];
	cin >> h[1] >> a[1];
	cin >> x[1] >> y[1];

	step[h[0]] = 1;
	ans = 0;
	for (int i = 1; i < 2 * MAXN; i++) {
    	h[0] = (h[0] * x[0] + y[0]) % m;
		h[1] = (h[1] * x[1] + y[1]) % m;
		ans++;
		if (h[0] == a[0] && h[1] == a[1]) {
			cout << ans;
			return 0;
		}
		if (h[0] == a[0] && step[h[0]] != 0) {
			len = ans - step[h[0]] + 1;
			break;
		}		
		step[h[0]] = ans + 1;
	}
	
	if (h[0] != a[0]) {
		cout << -1;
		return 0;	
	}
		
	X1 = 1;
	forn(i, len)
		X1 = (X1 * x[1]) % m;
	Y1 = 0;
	forn(i, len)
		Y1 = (x[1] * Y1 + y[1]) % m;
		
	for (int i = 1; i < 2 * MAXN; i++) {
        h[1] = (h[1] * X1 + Y1) % m;
		
        ans += len;
		if (h[0] == a[0] && h[1] == a[1]) {
			cout << ans;
			return 0;
		}
	}
	
	cout << -1;
		return 0;
}