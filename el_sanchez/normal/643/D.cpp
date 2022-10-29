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
const int MAXN = 100500;

int n, q;
ll t[MAXN], S[MAXN];
int par[MAXN], sz[MAXN];
set<pair<ll, int>> rel[MAXN];
set<pair<ll, int>> Q;

ll getAns(int i) {
	ll ans = S[i];
	ans += t[par[i]] / (sz[par[i]] + 2);
	return ans;				
}

void insertRel(int i) {
	if (!rel[i].empty()) {
		pair<ll, int> c, d;

		c = *rel[i].begin();
		d = *rel[i].rbegin();
		
		Q.insert({getAns(c.Y), c.Y});
		Q.insert({getAns(d.Y), d.Y});
	}	
}

void eraseRel(int i) {
	if (!rel[i].empty()) {
		pair<ll, int> c, d;

		c = *rel[i].begin();
		d = *rel[i].rbegin();
		
		Q.erase({getAns(c.Y), c.Y});
		Q.erase({getAns(d.Y), d.Y});
	}	
}

int main() {

	scanf("%d%d", &n, &q);
	forn(i, n)
		scanf("%I64d", &t[i]);
    
	forn(i, n) {
		int v;
		scanf("%d", &v);
		v--;

		par[i] = v;
		sz[i]++;
		sz[v]++;	
	}
	
	forn(i, n)
		sz[i]--;
	
	forn(i, n)
		S[i] = t[i] - 1ll * (sz[i] + 1) * (t[i] / (sz[i] + 2));
	
	forn(i, n) {
		int v = par[i];
		//add to v:
		S[v] += t[i] / (sz[i] + 2);
	}
	
	forn(i, n) {
		int v = par[i];
        rel[v].insert({S[i], i});	
	}
	
	forn(i, n)
		insertRel(i);
	
	forn(ii, q) {
		int tq, i, j;
		scanf("%d", &tq);
		if (tq == 1) {
			scanf("%d%d", &i, &j);
			i--, j--;
			
			int k = par[i];
			
			int v[2];
			v[0] = k;
			v[1] = j;
			forn(i, 2)
				forn(j, 3) {
					eraseRel(v[i]);
					v[i] = par[v[i]];	
				}                    			
			
			rel[par[par[k]]].erase({S[par[k]], par[k]});
			rel[par[par[j]]].erase({S[par[j]], par[j]});
			rel[par[k]].erase({S[k], k});
			rel[par[j]].erase({S[j], j});
			
			S[par[k]] -= t[k] / (sz[k] + 2);
			S[par[k]] += t[k] / (sz[k] + 1);
			
			S[par[j]] -= t[j] / (sz[j] + 2);
			S[par[j]] += t[j] / (sz[j] + 3);
			
			S[k] -= t[i] / (sz[i] + 2);
			S[k] -= t[k] - 1ll * (sz[k] + 1) * (t[k] / (sz[k] + 2));
			sz[k]--;
			S[k] += t[k] - 1ll * (sz[k] + 1) * (t[k] / (sz[k] + 2));
			
			S[j] += t[i] / (sz[i] + 2);
			S[j] -= t[j] - 1ll * (sz[j] + 1) * (t[j] / (sz[j] + 2));
			sz[j]++;
			S[j] += t[j] - 1ll * (sz[j] + 1) * (t[j] / (sz[j] + 2));
			
			rel[k].erase({S[i], i});
			rel[j].insert({S[i], i});
			
			rel[par[par[k]]].insert({S[par[k]], par[k]});
			rel[par[par[j]]].insert({S[par[j]], par[j]});
			rel[par[k]].insert({S[k], k});
			rel[par[j]].insert({S[j], j});
			
			par[i] = j;
			
			v[0] = k;
			v[1] = j;
			forn(i, 2)
				forn(j, 3) {
					insertRel(v[i]);
					v[i] = par[v[i]];	
				}
        } else if (tq == 2) {
			scanf("%d", &i);
			i--;

			printf("%I64d\n", getAns(i));	
		} else {
			pair<ll, int> c, d;

			c = *Q.begin();
			d = *Q.rbegin();
			
			printf("%I64d %I64d\n", c.X, d.X);
		}
	}
	
	return 0;
}