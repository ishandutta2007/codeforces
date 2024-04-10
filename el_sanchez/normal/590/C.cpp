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
const int INF = 1E7;		
const int MAXN = 1010;
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};    

int n, m;
string s;
int a[MAXN][MAXN]; //-1 -> block, 0 -> free, 1..3 -> obvious
pii belong[3][MAXN * MAXN];
int sz[3];
int distFrom[3][MAXN][MAXN];
int minDist[3][3];
deque<pii> d;

bool correct(pii p) {
	return 0 <= p.X && p.X < n && 0 <= p.Y && p.Y < m;	
}
                 
void bfs(int id) {
	forn(i, n)
		forn(j, m)
			distFrom[id][i][j] = INF;

	d.clear();
	forn(i, sz[id])	{
		distFrom[id][belong[id][i].X][belong[id][i].Y] = 0;
		d.push_back(belong[id][i]);
	}
	
	pii p, q;
	int curDist;
	while (!d.empty()) {
		p = d.front();
		d.pop_front();
		curDist = distFrom[id][p.X][p.Y];
		//cout << p.X << ' ' << p.Y << '\n';		
		
		forn(t, 4) {
			q = {p.X + dx[t], p.Y + dy[t]};
			if (correct(q) && a[q.X][q.Y] != -1) {
				if (distFrom[id][q.X][q.Y] == INF) {
					if (a[q.X][q.Y] > 0) {
						distFrom[id][q.X][q.Y] = curDist;
						d.push_front(q);
					} else {
						distFrom[id][q.X][q.Y] = curDist + 1;
						d.push_back(q);
					}
				}
			}
		}
	}
}

int main() {

	cin >> n >> m;
	forn(i, n) {
		cin >> s;
		forn(j, m)
			if (s[j] == '#')
				a[i][j] = -1;
			else if (s[j] == '.')
				a[i][j] = 0;
			else
				a[i][j] = s[j] - '0';	
	}
	
	forn(i, 3)
		sz[i] = 0;
		
	forn(i, n)
		forn(j, m)
			if (a[i][j] > 0) {
				int c = a[i][j] - 1;
				belong[c][sz[c]++] = {i, j};
			}
			
	forn(i, 3)
		bfs(i);
		
	int ans = INF;
	
	forn(i, 3)
		forn(j, 3)
			if (i == j)
				minDist[i][j] = 0;
			else {
				minDist[i][j] = INF;
				forn(k, sz[j])
					minDist[i][j] = min(minDist[i][j], distFrom[i][belong[j][k].X][belong[j][k].Y]);	
			}

	forn(i, 3)
		forn(j, 3)
			assert(minDist[i][j] == minDist[j][i]);
			
	forn(i, 3)
		forn(j, 3)
			if (i != j && minDist[i][j] == 0) {
				int k = 3 - i - j;
				ans = minDist[i][k];
				cout << (ans == INF ? -1 : ans) << '\n';
				return 0;	
			}
			
	int cur;		
	forn(i, 3) {
		cur = 0;
		forn(j, 3)
			cur += minDist[i][j];
		ans = min(ans, cur);	
	}

	forn(i, n)
		forn(j, m) {
			if (a[i][j] != 0)
				continue;
				
			cur = 0;
			forn(k, 3)
				cur += distFrom[k][i][j];
			cur -= 2;
			if (cur < ans) {
				ans = cur;
				//cout << i << ' ' << j << '\n';	
			}
		}
		
	cout << (ans == INF ? -1 : ans) << '\n';
	
	return 0;
}