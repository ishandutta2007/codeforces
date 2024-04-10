#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for(int i = (a); i >= (b); --i)
#define RI(i,n) FOR(i,1,(n))
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define sz(w) (int) w.size()
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 1e6 + 5;

int t[nax];
bool vis[nax];

int main() {
	int n;
	scanf("%d", &n);
	RI(i, n) {
		scanf("%d", &t[i]);
		if(t[i] == i) {
			puts("YES");
			RI(a, n) if(a != i) printf("%d %d\n", a, i);
			return 0;
		}
	}
	vector<pii> res;
	RI(x, n) if(t[t[x]] == x) {
		int y = t[x];
		vis[x] = vis[y] = true;
		RI(a, n) if(!vis[a]) {
			vi w;
			do {
				w.pb(a);
				vis[a] = true;
				a = t[a];
			} while(!vis[a]);
			if(sz(w) % 2) {
				puts("NO");
				return 0;
			}
			REP(i, sz(w)) {
				res.pb(mp(x, w[i++]));
				res.pb(mp(y, w[i]));
			}
		}
		res.pb(mp(x, y));
		assert(sz(res) == n - 1);
		puts("YES");
		for(pii p : res) printf("%d %d\n", p.st, p.nd);
		return 0;
	}
	puts("NO");
	return 0;
}