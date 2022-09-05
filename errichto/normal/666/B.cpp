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
const int inf = 1e7 + 5;
const int nax = 3005;

int d[nax][nax];
bool vis[nax];
vi w[nax];
set<pair<int,int>> one[nax], two[nax];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	REP(_, m) {
		int a, b;
		scanf("%d%d", &a, &b);
		w[a].pb(b);
	}
	RI(a, n) {
		REP(b, n + 2) vis[b] = false;
		RI(b, n) d[a][b] = inf;
		d[a][a] = 0;
		vi kol;
		kol.pb(a);
		vis[a] = true;
		for(int i = 0; i < sz(kol); ++i) {
			int b = kol[i];
			for(int c : w[b]) if(!vis[c]) {
				d[a][c] = d[a][b] + 1;
				kol.pb(c);
				vis[c] = true;
			}
		}
	}
	RI(a,n)RI(b,n) if(d[a][b] == inf) d[a][b] = -inf;
	/*RI(i, n) {
		RI(j, n) printf("%d ", d[i][j]);
		puts("");
	}*/
	RI(b, n) {
		RI(a, n) if(a != b && d[a][b] >= 0) {
			one[b].insert(mp(d[a][b], a));
			while(sz(one[b]) > 4)
				one[b].erase(one[b].begin());
		}
	}
	RI(c, n) RI(dd, n) if(c != dd && d[c][dd] >= 0) {
		two[c].insert(mp(d[c][dd], dd));
		while(sz(two[c]) > 4)
			two[c].erase(two[c].begin());
	}
	int answer = -1;
	vi ple;
	RI(b, n) RI(c, n) if(b != c && d[b][c] >= 0) {
		for(const pii & p1 : one[b]) {
			int a = p1.second;
			if(a == c) continue;
			for(const pii & p2 : two[c]) {
				int dd = p2.second;
				if(a == dd || b == dd || c == dd) continue;
				int maybe = d[a][b] + d[b][c] + d[c][dd];
				if(maybe > answer) {
					answer = maybe;
					ple = vi{a,b,c,dd};
				}
				//maxi(answer, d[a][b] + d[b][c] + d[c][dd]);
			}
		}
	}
	assert(answer != -1);
	//printf("%d\n", answer);
	for(int x : ple) printf("%d ", x);
	puts("");
	return 0;
}