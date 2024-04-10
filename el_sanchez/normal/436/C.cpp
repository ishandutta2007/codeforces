#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <ctime>
#include <cmath>
#include <iomanip>
#include <cassert>
                   
using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++) 
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define forab(i, a, b) for (int i = int(a); i < int(b); i++)

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define X first
#define Y second

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;
typedef long double ld;

const int INF = 1E9;   
const ld eps = 1e-6;
const ld pi = acos(-1.0);
const int MAXN = 1111;
const int MAXM = 11;   
const ll MOD = 1E9 + 7;

int n, m, k, w;
string s[MAXN][MAXM];
int diff[MAXN][MAXN], t[MAXN][MAXN], dist[MAXN], used[MAXN], par[MAXN], cost[MAXN];
vector<pii> g;
int ans;

void dijkstra() {
	forn(i, k) {
		used[i] = 0;
		dist[i] = INF;
	}            
	dist[0] = 0;
	par[0] = -1;
	g.clear();
	ans = n * m;

	forn(i, k) {
	    //forn(j, k)
	    //	cout << j << ' ' << dist[j] << endl;
		
		int id = -1;
		forn(j, k)
			if (!used[j] && (id == -1 || dist[j] < dist[id]))
				id = j;    

	    used[id] = 1;
	    ans += dist[id];
	    g.pb(mp(id, par[id]));
	                
	    forn(j, k)
	    	if (!used[j]) {
	    		if (dist[j] > diff[id][j]) {
	    			dist[j] = diff[id][j];
	    			par[j] = t[id][j] == 0 ? -1 : id;
	    		}
	    	}


	}	
}

int main() {

	cin >> n >> m >> k >> w;        
    forn(i, k) {
    	forn(j, n)
    		cin >> s[i][j];

    }

  	forn(i, k)
  		forn(j, k) {
  			diff[i][j] = 0;
  			forn(a, n)
  				forn(b, m)
  					diff[i][j] += s[i][a][b] != s[j][a][b];
  		}	

                  
  	forn(i, k)
  		forn(j, k)
  			if (diff[i][j] * w > n * m) {
  				diff[i][j] = n * m;
  				t[i][j] = 0;
  			} else {
  				diff[i][j] *= w;
  				t[i][j] = 1;
  		    }
             
  	forn(i, k)
  		diff[i][i] = INF;

   	ans = 0;
   	dijkstra();

   	cout << ans << '\n';
   	forn(i, g.size())
   		cout << g[i].X + 1 << ' ' << g[i].Y + 1 << '\n';

	return 0;
}