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
const int MAXN = 311;
const int MAXDIST = 611;
const int C = 303;
const pii dd[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

pii operator+(pii a, pii b) {
	return {a.X + b.X, a.Y + b.Y};	
}

int n, m, p;
pii s, f;
int a[MAXN][MAXN], d[MAXN][MAXN];
int used[MAXN][MAXN], localD[MAXN][MAXN];
int minDist;
vector<pii> blocks[MAXN * MAXN];
queue<pii> q[MAXDIST];

int dist(pii a, pii b) {
	return abs(a.X - b.X) + abs(a.Y - b.Y);	
}

bool correct(pii p) {
	return 0 <= p.X && p.X < n && 0 <= p.Y && p.Y < m;	
}

int main() {
	
	cin >> n >> m >> p;
	forn(i, n)
		forn(j, m) {
			scanf("%d", &a[i][j]);
			blocks[a[i][j]].pb({i, j});
		}

	s = {0, 0};

	forn(i, n)
		forn(j, m)
			d[i][j] = INF;			
		
	for (auto p: blocks[1]) {
		d[p.X][p.Y] = dist(s, p);
	}        
	
	for (int id = 1; id < p; id++) {
		/*
		forn(i, n)
			forn(j, m)
				cout << d[i + j + 1][i - j + C + 1] << " \n"[j == m - 1];
		*/
		int sz = blocks[id].size();

		if (sz < C) {
			for (auto p: blocks[id + 1]) {
				for (auto qq: blocks[id])
					d[p.X][p.Y] = min(d[p.X][p.Y], d[qq.X][qq.Y] + dist(p, qq));
			}					
		} else {
			minDist = INF;
			
			for (auto p: blocks[id])
				minDist = min(minDist, d[p.X][p.Y]);
			forn(i, MAXN)
				forn(j, MAXN)
					localD[i][j] = INF;	
			assert(minDist < INF);
			
			forn(i, MAXDIST)
				while (!q[i].empty())
					q[i].pop();

			for (auto p: blocks[id])
				if (d[p.X][p.Y] - minDist < MAXDIST) {
					localD[p.X][p.Y] = d[p.X][p.Y] - minDist;
					q[d[p.X][p.Y] - minDist].push(p);
				}
				
			for (int ptr = 0; ptr < MAXDIST; ptr++) {
				while (!q[ptr].empty()) {
					pii p = q[ptr].front();
					q[ptr].pop();
					
					if (used[p.X][p.Y] == id)
						continue;
					used[p.X][p.Y] = id;
					
					forn(dir, 4) {
						pii np = p + dd[dir];
						if (correct(np)) {
							int nDist = localD[p.X][p.Y] + 1;
							if (localD[np.X][np.Y] > nDist) {
								localD[np.X][np.Y] = nDist;
								if (ptr < MAXDIST - 1)
									q[ptr + 1].push(np);
							}
						}
					}
				}
			}

			for (auto p: blocks[id + 1])
				d[p.X][p.Y] = minDist + localD[p.X][p.Y];			
		}
	}

	assert(blocks[p].size() == 1);
	f = blocks[p][0];
	cout << d[f.X][f.Y] << '\n';
	
 	return 0;
}