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

int n, m, added, num, u, v;
pair<pii, int> e[MAXN];
pii ans[MAXN];

int main() {
	
	cin >> n >> m;
	forn(i, m) {
		scanf("%d%d", &e[i].X.X, &e[i].X.Y);
		e[i].X.Y ^= 1;	
		e[i].Y = i;
	}
	
	sort(e, e + m);
	
	u = 1;
	v = 2;
	added = 0;
	
	forn(i, m) {
		int id = e[i].Y;
		if (e[i].X.Y == 0) { //good
			added++;
			ans[id] = {0, added};		
		} else {
			if (v > added) {
				cout << -1 << '\n';
				return 0;
			}
			
			ans[id] = {u, v};
			u++;
			if (u == v) {
				u = 1;
				v++;
			}
		}
	}
	
	forn(i, m)
		printf("%d %d\n", ans[i].X + 1, ans[i].Y + 1);
			
	return 0;
}