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
const ld eps = 1e-14;
const int INF = 1E9;		                    
const int MAXN = 1050;
const ll MC = 1E9 + 22;
const char cdir[] = {'L', 'R', 'D', 'U'};
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int n, k;
pii p[MAXN]; 
char cd;
ll coords[2][3 * MAXN + 10];
int csz[2], cur[2], ncur[2];
bool g[3 * MAXN + 10][3 * MAXN + 10][4];
int used[3 * MAXN + 10][3 * MAXN + 10];
vector<pair<pii, pii> > segs[2];
queue<pii> q;
ll AREA;

void bfs(pii p) {
	q.push(p);
	used[p.X][p.Y] = 1;
		
	while (!q.empty()) {
		p = q.front();
		q.pop();

		cur[0] = p.X, cur[1] = p.Y;
		forn(i, 4) {
			if (g[cur[0]][cur[1]][i]) {
				ncur[0] = cur[0] + dx[i];
				ncur[1] = cur[1] + dy[i];
				if (used[ncur[0]][ncur[1]] == 0) {
					used[ncur[0]][ncur[1]] = 1;
					q.push({ncur[0], ncur[1]});
				}
			}		
		}
	}
}

bool cmp0(pair<pii, pii> A, pair<pii, pii> B) {
	return A.X.Y < B.X.Y;
}
int main() { 

	scanf("%d\n", &n);
	
	p[0] = {0, 0};
	forn(i, n) {
		scanf("%c %d\n", &cd, &k);
		forn(j, 4)
			if (cd == cdir[j]) {
				p[i + 1] = {p[i].X + k * dx[j], p[i].Y + k * dy[j]};
				if (j <= 1) {
					segs[0].pb({p[i], p[i + 1]});
					if (p[i].X > p[i + 1].X)
						swap(segs[0].back().X, segs[0].back().Y); 	
				} else {
					segs[1].pb({p[i], p[i + 1]}); 	
					if (p[i].Y > p[i + 1].Y)
						swap(segs[1].back().X, segs[1].back().Y); 	
				}
				break;  
			}
	}   
	
	//forn(i, n + 1)
	//	cout << p[i].X << ' ' << p[i].Y << '\n';
	forn(i, n + 1) {
		cur[0] = p[i].X;
		cur[1] = p[i].Y;
		
		forn(j, 2)
			for (int k = -1; k <= 1; k++)
				coords[j][csz[j]++] = cur[j] + k;	
	}	
	forn(i, 2) {
		coords[i][csz[i]++] = MC;
		coords[i][csz[i]++] = -MC;
		sort(coords[i], coords[i] + csz[i]);
		csz[i] = unique(coords[i], coords[i] + csz[i]) - coords[i];
	}
	/*	
	forn(i, 2)
		forn(j, csz[i])
			cout << coords[i][j] << '\n';
	*/

	sort(all(segs[0]), cmp0);
	sort(all(segs[1]));
		
	forn(j, segs[0].size()) {
		pii L = segs[0][j].X;
		pii R = segs[0][j].Y;
		int i1 = lower_bound(coords[0], coords[0] + csz[0], L.X) - coords[0];
		int i2 = lower_bound(coords[0], coords[0] + csz[0], R.X) - coords[0];
		int j0 = lower_bound(coords[1], coords[1] + csz[1], L.Y) - coords[1];
		for (int j = i1; j <= i2; j++)
			used[j][j0] = -1;
	}
	forn(j, segs[1].size()) {
		pii L = segs[1][j].X;
		pii R = segs[1][j].Y;
		int i1 = lower_bound(coords[1], coords[1] + csz[1], L.Y) - coords[1];
		int i2 = lower_bound(coords[1], coords[1] + csz[1], R.Y) - coords[1];
		int j0 = lower_bound(coords[0], coords[0] + csz[0], L.X) - coords[0];
		for (int j = i1; j <= i2; j++)
			used[j0][j] = -1;
	}
	
	int ptr;
	for (int i = 0; i < csz[0]; i++) {
		ptr = 0;
		for (int j = 0; j < csz[1] - 1; j++) {
			bool f = 1;
			if (used[i][j] == -1)
				f = 0;
			while (ptr < segs[0].size() && segs[0][ptr].X.Y < coords[1][j])
				ptr++;
			while (ptr < segs[0].size() && segs[0][ptr].X.Y <= coords[1][j + 1]) {
				if (segs[0][ptr].X.X <= coords[0][i] && coords[0][i] <= segs[0][ptr].Y.X)
					f = 0; 
				ptr++;
			}
			if (f) {
				g[i][j][3] = 1;
				g[i][j + 1][2] = 1;	
			}						
		}
	}	
	for (int i = 0; i < csz[1]; i++) {
		ptr = 0;
		for (int j = 0; j < csz[0] - 1; j++) {
			bool f = 1;
			if (used[j][i] == -1)
				f = 0;
			while (ptr < segs[1].size() && segs[1][ptr].X.X < coords[0][j])
				ptr++;
			while (ptr < segs[1].size() && segs[1][ptr].X.X <= coords[0][j + 1]) {
				if (segs[1][ptr].X.Y <= coords[1][i] && coords[1][i] <= segs[1][ptr].Y.Y)
					f = 0; 
				ptr++;
			}
			if (f) {
				g[j][i][1] = 1;
				g[j + 1][i][0] = 1;	
			}						
		}
	}	
	
	bfs({0, 0});

	forn(i, csz[0])
		forn(j, csz[1]) {
			if (used[i][j] == -1)
				used[i][j] = 0;
			//cout << (used[i][j]) << " \n"[j == csz[1] - 1];
		}  
			
	AREA = (MC + MC + 1) * (MC + MC + 1);
	
	forn(i, csz[0])
		forn(j, csz[1])
			AREA -= used[i][j];
	forn(i, csz[0])
		forn(j, csz[1] - 1)
			if (used[i][j] && used[i][j + 1])
				AREA -= coords[1][j + 1] - coords[1][j] - 1;
	forn(i, csz[0] - 1)
		forn(j, csz[1])
			if (used[i][j] && used[i + 1][j])
				AREA -= coords[0][i + 1] - coords[0][i] - 1;
				
	forn(i, csz[0] - 1)
		forn(j, csz[1] - 1) {
			if (used[i][j] && used[i + 1][j] && used[i][j + 1] && used[i + 1][j + 1]) {
				AREA -= max(coords[0][i + 1] - coords[0][i] - 1, 0ll) * 
						max(coords[1][j + 1] - coords[1][j] - 1, 0ll);
			}
			
		}
	cout << AREA;
		
	return 0;       
}