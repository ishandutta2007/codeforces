//#define _GLIBCXX_DEBUG
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
const ld eps = 1e-9;
const int INF = 1E9;		
const int MAXN = 800500;
const int ALPH = 26;
    
int n, take;
int root = 0, sz;
int nxt[MAXN][ALPH], num[MAXN][ALPH], pos[MAXN][2], ans;
vi ids[MAXN][2];
vector<pii> bij;
string s;

void dfs0(int v) {
	forn(i, 2) {
		int ptake = pos[take][i];
		for (auto z: ids[v][i])
			ids[ptake][i].pb(z);
		ids[v][i].clear();
	}
	
	forn(i, ALPH)
		if (nxt[v][i] != -1) {
			int w = nxt[v][i];
			dfs0(w);
		}	
}

void dfs(int v, int h) {
	forn(i, ALPH)
		if (nxt[v][i] != -1) {
			int w = nxt[v][i];	
			if (num[w][0] >= 1 && num[w][1] >= 1) {
				dfs(w, h + 1);
				
				//up w to v (merge vectors)
				forn(id, 2) {
					int pv = pos[v][id], pw = pos[w][id];
					if (ids[pv][id].size() > ids[pw][id].size()) {
						for (auto z: ids[pw][id])
							ids[pv][id].pb(z);
						ids[pw][id].clear();
						pos[w][id] = pv;
					} else {
						for (auto z: ids[pv][id])
							ids[pw][id].pb(z);
						ids[pv][id].clear();
						pos[v][id] = pw;
					}
				}
			} else {
				take = v;
				dfs0(w);		
			}
		}
		
	int pv[2];
	pv[0] = pos[v][0];
	pv[1] = pos[v][1];
	
	while (!(ids[pv[0]][0].empty() || ids[pv[1]][1].empty())) {
		ans += h;
		bij.pb({ids[pv[0]][0].back(), ids[pv[1]][1].back()});
		ids[pv[0]][0].pop_back();
		ids[pv[1]][1].pop_back();
	}
}

int main() {

	forn(i, ALPH)
		nxt[root][i] = -1;
	sz = 1;
	
    cin >> n;
    forn(i, 2) {
    	forn(j, n) {
    		cin >> s;
    		
    		//add s
    		int v = root;
    		num[v][i]++;
    		forn(k, s.size()) {
    			if (nxt[v][s[k] - 'a'] == -1) {
    				nxt[v][s[k] - 'a'] = sz;
    				forn(l, ALPH)
    					nxt[sz][l] = -1;
    				sz++;
    			}
    			v = nxt[v][s[k] - 'a'];
    			num[v][i]++;
    		}
    		
    		ids[v][i].pb(j);
    	}
    }
    
    forn(i, sz)
    	forn(id, 2)
    		pos[i][id] = i;
    	
    ans = 0;
    dfs(root, 0);
    cout << ans << '\n';
    
    forn(i, bij.size())
    	printf("%d %d\n", bij[i].X + 1, bij[i].Y + 1);
    	
    
	return 0;
}