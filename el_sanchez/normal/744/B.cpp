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
const int MAXN = 1111;

int n, k, s;
vi queries[MAXN];
int valid[MAXN][33];
int ans[MAXN];

int main() {
	
	cin >> n;
	forn(i, n) {
		ans[i] = INF;
	}
	
	k = 10;
	int M = 1 << k;
	
	for (int step = 1; step < M; step *= 2) {
		int ptr = s, mem = 0;
		forn(i, M) {
			if (mem == step) {
				mem = 0;
				ptr ^= 1;
			}
			
			if (i < n) {
				queries[ptr].pb(i);
			}
			
			mem++;
		}
		s += 2;
	}
	
	assert(s == 20);
		
	forn(j, s) {
		if (queries[j].empty()) {
			queries[j].pb(0);
		}
	}
	
	forn(i, n) {
		forn(j, s) {
			valid[i][j] = 1;
		}
	}
	
	forn(j, s) {
		for (auto x: queries[j]) {
			valid[x][j] = 0;
		}
	}
	
	forn(i, s) {
		printf("%d\n", queries[i].size());
		for (auto x: queries[i]) {
			printf("%d ", x + 1);
		}
		cout << '\n';
		cout.flush();
		
		forn(j, n) {
			int res;
			scanf("%d", &res);
			if (valid[j][i]) {
				ans[j] = min(ans[j], res);
			}
		}
	}
	
	cout << -1 << '\n';
	forn(i, n) {
		cout << ans[i] << " \n"[i == n - 1];
	}
	cout.flush();
	
    return 0;
}