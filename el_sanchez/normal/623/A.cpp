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
typedef long double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 511;

int n, m;
int g[MAXN][MAXN];
int used[MAXN], color[MAXN], sz[3];
string s;

bool dfs(int v, int t) {
	used[v] = t;
	s[v] = (t == 1 ? 'a' : 'c');
	sz[t]++;

	for (int w = 0; w < n; w++)
		if (g[v][w]) {
			if (used[w] == 0) {
				if (!dfs(w, 3 - t))	
					return 0;
			} else if (used[w] != 3 - t)
				return 0;
		}
			
	return 1;
}

int main() {

    cin >> n >> m;
    forn(i, n)
    	s += ' ';
    
    forn(i, n)
    	forn(j, n) {
    		g[i][j] = (i != j);	
    	}
    	
    forn(i, m) {
    	int a, b;
    	cin >> a >> b;
    	a--, b--;
    	g[a][b] = g[b][a] = 0;
    }
    
    m = n * (n - 1) / 2 - m;
    forn(i, n) {
    	int deg = 0;
    	forn(j, n)	
    		deg += g[i][j];
    		
    	if (deg == 0) {
    		used[i] = -1;
    		s[i] = 'b';
    	}
    }

    forn(i, n)
    	if (used[i] == 0) {
    		if (!dfs(i, 1)) {
				cout << "No\n";
				return 0;    			
    		}
    	}
    	
    //cout << sz[1] << ' ' << sz[2] << '\n';
    
    if (m != sz[1] * sz[2]) {
    	cout << "No\n";
    	return 0;
    }
    
    cout << "Yes\n";
    cout << s << '\n';
	return 0;
}