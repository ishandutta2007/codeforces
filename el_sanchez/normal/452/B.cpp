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
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 100500;

int C = 4;
int n, m, sz;
pii a[MAXN];
int used[MAXN];
ld len;
pii cur[4], ans[4];    

void getAns(int id) {
	if (id == 4) {
		ld res = 0;
		forn(j, 3)
			res += sqrt(0.0 + sqr(cur[j].X - cur[j + 1].X) + sqr(cur[j].Y - cur[j + 1].Y));
		if (res > len) {
			len = res;
			forn(j, 4)
				ans[j] = cur[j];	
		}
		return;
	}
		
	for (int j = 0; j < sz; j++) {
		if (!used[j]) {
			used[j] = 1;
			cur[id] = a[j];
			getAns(id + 1);	
			used[j] = 0;
		}
	}
}

int main() {

	cin >> n >> m;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			if (i + j <= C || n - i + j <= C || i + m - j <= C || n - i + m - j <= C)
				a[sz++] = {i, j};

	len = 0;
	getAns(0);

	forn(i, 4)
		cout << ans[i].X << ' ' << ans[i].Y << '\n';
			 	
	return 0;	
}