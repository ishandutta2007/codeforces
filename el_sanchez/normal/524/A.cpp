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
const int MAXN = 1111;
                        
int m, k, v, w, sz;  
vector<pii> g;
set<int> a;
set<int> men;
vi ans;

int main() { 

	cin >> m >> k;
	sz = 0;
	forn(i, m) {
		cin >> v >> w;
		if (a.find(v) == a.end()) {
			a.insert(v);	
		}
		if (a.find(w) == a.end()) {
			a.insert(w);	
		}
		g.pb({v, w});
		g.pb({w, v});		
	}

	for (auto v: a) {
		ans.clear();
		men.clear();
		for (auto w: a) {
			if (v == w)
				continue;
				
			bool f = 1;
			for (auto e: g) {
				if (e.X == v) {
			        if (e.Y == w) {
			        	f = 0;
			        	break;
			        }
					men.insert(e.Y);
				}
			}	
			
			if (!f)
				continue;
				
			int num = 0;
			for (auto e: g) {
				if (e.X == w && men.find(e.Y) != men.end())
					num++;       	
			}
			
			if (num * 100 >= k * (int)men.size())
				ans.pb(w);		
		}
		
		printf("%d: %d", v, ans.size());
		forn(i, ans.size())
			printf(" %d", ans[i]);
		cout << '\n';
	}
		
	return 0;
}