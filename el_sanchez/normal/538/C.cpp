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
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 100500;

int n, m;
ll ans, id, h, pid, ph, a, b, delta;

int main() {

	ans = 0;
	
	cin >> n >> m;
	forn(i, m) {
		cin >> id >> h;
		if (i == 0) {
			ans = max(ans, h + id - 1);
		} else {
			if (id - pid < abs(h - ph)) {
				cout << "IMPOSSIBLE";
				return 0;
			}
			
			ans = max(ans, h);
			a = min(ph, h);
			b = max(ph, h);
			delta = id - pid - 1;
			delta -= (b - a);
			if (delta >= 0) {
				ans = max(ans, b + (delta + 1) / 2);	
			}
		}
		
		if (i == m - 1)
			ans = max(ans, h + (n - id));
			
		ph = h;
		pid = id;
	}
	
	cout << ans;
	
	return 0;
}