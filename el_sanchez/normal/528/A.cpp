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
const int MAXN = 500500;                                
const char cc[2] = {'H', 'V'};

int n, m, q, p;
char c;
set<pii> mx[2];
set<pii> coords[2];
ll ans;

int main() {
                                                            
    scanf("%d%d%d\n", &n, &m, &q);
    mx[0].insert({-m, 0});
    mx[1].insert({-n, 0});
    coords[0].insert({0, m});
    coords[1].insert({0, n});
      
    forn(i, q) {
    	scanf("%c %d\n", &c, &p);
    
    	forn(d, 2)
    		if (cc[d] == c) {
    			auto f = coords[d].lower_bound({p, 0});
				f--;
				pii cur = *f;
				
				//cout << cur.X << ' ' << cur.Y << '\n';
				
				coords[d].erase(cur);
				coords[d].insert({cur.X, p - cur.X});
				coords[d].insert({p, cur.Y - p + cur.X});
				
				mx[d].erase({-cur.Y, cur.X});
				mx[d].insert({-(p - cur.X), cur.X});
				mx[d].insert({-(cur.Y - p + cur.X), p});      		
    		}	
    	
    	ans = 1ll * (mx[0].begin()->X) * (mx[1].begin()->X);
    	cout << ans << '\n';
    }
	        	
	return 0;	
}