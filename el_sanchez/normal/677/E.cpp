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
typedef long double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const int INF = 1E9;	
const int MAXN = 1111;

const pii d[8] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1},
                  {-1, -1}, {1, -1}, {-1, 1}, {1, 1}};

pii operator+(pii a, pii b) {
	return {a.X + b.X, a.Y + b.Y};
}

pii operator*(pii a, int k) {
	return {a.X * k, a.Y * k};
}

struct prod {
	int p2, p3;

	prod(int _p2 = 0, int _p3 = 0) {
		p2 = _p2;
		p3 = _p3;
	}
	
	void print() {
		const int MOD = (int)1E9 + 7;

		if (p2 == -1) {
			cout << 0 << ' ';
		} else {
			ll res = 1;
			forn(i, p2)
				res = (res * 2) % MOD;
			forn(i, p3)
				res = (res * 3) % MOD;
			cout << res << ' ';
		}
	}
};

prod calc(int x) {
	if (x == 0)
		return prod(-1, -1);
	if (x == 1)
		return prod(0, 0);
	if (x == 2)
		return prod(1, 0);
	return prod(0, 1);
}

prod operator*(prod a, prod b) {
	if (a.p2 == -1 || b.p2 == -1)
		return prod(-1, -1);
	return prod(a.p2 + b.p2, a.p3 + b.p3);	
}

prod operator/(prod a, prod b) {
	if (b.p2 == -1)
		return a;
		
	prod c = prod(a.p2 - b.p2, a.p3 - b.p3);
	assert(c.p2 >= 0 && c.p3 >= 0);
	return c;	
}             

bool operator<(prod a, prod b) {
	if (b.p2 == -1)
		return 0;
	if (a.p2 == -1)
		return 1;

	prod c(a.p2 - b.p2, b.p3 - a.p3);

	if (c.p2 >= 0 && c.p3 <= 0)
		return 0;          

	if (c.p2 <= 0 && c.p3 >= 0)
		return 1;

	ld f2 = log(2.0) * c.p2;
	ld f3 = log(3.0) * c.p3;
		
	return f2 < f3;
}

int n;
string s[MAXN];
int a[MAXN][MAXN];
prod P[MAXN][MAXN][8];
int dist[MAXN][MAXN][8];                               
vector<pii> g[MAXN][MAXN];

bool correct(pii p) {
	return 0 <= p.X && p.X < n && 0 <= p.Y && p.Y < n;	
}

int main() {
	
	cin >> n;
	forn(i, n)
		cin >> s[i];
	forn(i, n)
		forn(j, n)
			a[i][j] = s[i][j] - '0';
			
	forn(dir, 8) {
		queue<pii> q;

		forn(i, n)
			forn(j, n)
				g[i][j].clear();
				
		pii p;
		for (p.X = 0; p.X < n; p.X++) {
			for (p.Y = 0; p.Y < n; p.Y++) {
				pii np = p + d[dir];
				if (!correct(np)) {
					q.push(p);
					P[p.X][p.Y][dir] = calc(a[p.X][p.Y]);
					dist[p.X][p.Y][dir] = 1;
				} else
					g[np.X][np.Y].pb(p);
			}
		}
		
		while (!q.empty()) {
			p = q.front();
			q.pop();

			for (auto np: g[p.X][p.Y]) {
				q.push(np);
				
				prod cur = calc(a[np.X][np.Y]) * P[p.X][p.Y][dir];
				dist[np.X][np.Y][dir] = dist[p.X][p.Y][dir] + 1;
				if (cur.p2 == -1) {
					cur = calc(a[np.X][np.Y]);
					dist[np.X][np.Y][dir] = 1;
				}                            				
				P[np.X][np.Y][dir] = cur;
			}
		}
	}
	/*
	forn(dir, 8) {
		cout << dir << '\n';
		forn(i, n) {
			forn(j, n)
				P[i][j][dir].print();
			cout << '\n';
		}
	}
	*/
	prod ans(-1, -1);
	
	pii p;
	for (p.X = 0; p.X < n; p.X++) {
		for (p.Y = 0; p.Y < n; p.Y++) {
			if (a[p.X][p.Y] == 0)
				continue;
				
			forn(i, 2) {
				int D = INF;
				forn(j, 4)
					D = min(D, dist[p.X][p.Y][i * 4 + j]);	

				//cout << p.X << ' ' << p.Y << ": " << D << '\n';
					
				prod cur(0, 0);
				forn(j, 4) {
					int dir = i * 4 + j;
					pii np = p + d[dir] * D;
					cur = cur * P[p.X][p.Y][dir];
					if (correct(np))
						cur = cur / P[np.X][np.Y][dir];
					if (j != 0)
						cur = cur / calc(a[p.X][p.Y]);
				}
				
				if (ans < cur)
					ans = cur;
			}
		}
	}

	ans.print();
			
 	return 0;
}