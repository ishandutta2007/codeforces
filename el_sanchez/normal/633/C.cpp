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
const int MAXN = 10500;
const int MAXV = 1000500;
const int ALPH = 26;

int n, m;
string s;
int dp[MAXN];
int par[MAXN];
int go[MAXV][ALPH];
int id[MAXV];
int root, sz;
string lib[MAXV];
vector<string> ans;

void getAns(int i) {
	if (i == 0)
		return;

	ans.pb(lib[par[i]]);
	getAns(i - lib[par[i]].size());
}

int main() {

    cin >> n;
    cin >> s;

    cin >> m;
    forn(i, m)
    	cin >> lib[i];

    memset(id, -1, sizeof(id));
    
    root = 0;
    forn(i, ALPH)
    	go[root][i] = -1;
    sz = 1;
    
    forn(i, m) {
    	int v = root;
    	for (int j = 0; j < (int)lib[i].size(); j++) {
    		char c = lib[i][j];	
    		if ('A' <= c && c <= 'Z')
    			c += 'a' - 'A';
    		int nxt = c - 'a';
    		
    		if (go[v][nxt] == -1) {
    			go[v][nxt] = sz;
    			forn(k, ALPH)
    				go[sz][k] = -1;
    			sz++;	
    		}
    		
    		v = go[v][nxt];
    	}
    	
    	id[v] = i;
    }
    
    reverse(all(s));
    
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
		if (dp[i] == 1) {
			//cerr << i << '\n';

			int v = root;
			for (int len = 0; v != -1; len++) {
				if (id[v] != -1) {
					dp[i + len] = 1;
					par[i + len] = id[v];
				}
				if (i + len == n)
					break;
				v = go[v][s[i + len] - 'a'];
			}
		}
    }
    
    getAns(n);
    
    forn(i, ans.size())
    	cout << ans[i] << " \n"[i == (int)ans.size() - 1];
    	
    return 0;
}