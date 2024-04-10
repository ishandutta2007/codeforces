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
const int MAXN = 2222;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const char c[] = {'v', '^', '>', '<'};

int n, m;
string s[MAXN];
int deg[MAXN][MAXN];
int used[MAXN][MAXN];
pii p, p2;
queue<pii> q;

void decDeg(pii P) {
	//cout << p.X << ' ' << p.Y << '\n';
		
	forn(d, 4) {
		pii P2 = {P.X + dx[d], P.Y + dy[d]};
		if (!(0 <= P2.X && P2.X < n && 0 <= P2.Y && P2.Y < m))
			continue;
		if (s[P2.X][P2.Y] == '.') {
			deg[P2.X][P2.Y]--;
			if (deg[P2.X][P2.Y] == 1) {
				q.push(P2);
				used[P2.X][P2.Y] = 1;
			}
		}		
	}
}

int main() {

	cin >> n >> m;
	forn(i, n)
		cin >> s[i];
		
	forn(i, n)
		forn(j, m) {
			if (s[i][j] == '.') {
				deg[i][j] = 0;
				used[i][j] = 0;
				forn(d, 4) {
					int ii = i + dx[d], jj = j + dy[d];
					if (!(0 <= ii && ii < n && 0 <= jj && jj < m))
						continue;
					if (s[ii][jj] == '.')
						deg[i][j]++;	
				}
				if (deg[i][j] == 1) {
					q.push({i, j});
					used[i][j] = 1;
				}
			}
		}

	while (!q.empty()) {
		p = q.front();
		q.pop();
		
		if (used[p.X][p.Y] == 2)
			continue;
		/*
		cout << p.X << ' ' << p.Y << '\n';
		cout << "!!!\n";
		*/	
		forn(d, 4) {
			p2 = {p.X + dx[d], p.Y + dy[d]};
			if (!(0 <= p2.X && p2.X < n && 0 <= p2.Y && p2.Y < m))
				continue;
				
			//cout << n << ' ' << m << '\n';
			
			if (s[p2.X][p2.Y] == '.') { //found successfully
				//cout << p2.X << ' ' << p2.Y << '\n';
		    
				used[p.X][p.Y] = 2;
				used[p2.X][p2.Y] = 2;
				s[p.X][p.Y] = c[d];
				s[p2.X][p2.Y] = c[d ^ 1];
				decDeg(p);
				decDeg(p2);
				break;
			}
		}

		if (s[p.X][p.Y] == '.')
			break;	
	}
	/*	
	forn(i, n)
		forn(j, m)
			cout << deg[i][j] << " \n"[j == m - 1];
	*/		
	forn(i, n)
		forn(j, m) 
			if (s[i][j] == '.') {
				cout << "Not unique";
				return 0;
			}
			
	forn(i, n) {
		forn(j, m)
cout << s[i][j];
cout << '\n';
}
		
	return 0;
}