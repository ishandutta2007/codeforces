#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = a; i <= (b); ++i)
#define FORD(i,a,b) for(int i = a; i >= (b); --i)
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
const int nax = 5e5 + 5;

int p[nax];
char sl[nax];
vi w[nax];
vi odw[nax];
pii tt[nax];
vi zapy[nax];
int v[nax];

int T = 0;

void dfs(int a, int h) {
	tt[a].st = T;
	w[h].pb(a);
	T++;
	for(int b : odw[a])
		dfs(b, h+1);
	tt[a].nd = T;
	T++;
}

int pref[nax][26];
bool res[nax];

int bin(int tajm, vi & vec) {
	assert(!vec.empty());
	if(tt[vec.back()].st < tajm) return sz(vec);
	int low = 0, high = sz(vec) - 1;
	while(low < high) {
		int med = (low + high) / 2;
		if(tt[vec[med]].st < tajm) low = med + 1;
		else high = med;
	}
	return low;
}

int main()
{
	int n, q;
	scanf("%d%d", &n, &q);
	FOR(i,2,n) {
		scanf("%d", &p[i]);
		odw[p[i]].pb(i);
	}
	dfs(1,1);
	scanf("%s", sl);
	REP(i, q) {
		scanf("%d", &v[i]);
		int h;
		scanf("%d", &h);
		zapy[h].pb(i);
	}
	RI(h, n) {
		int d = sz(w[h]);
		REP(i, d) {
			REP(j, 26) {
				if(i) pref[i][j] = pref[i-1][j];
				else pref[i][j] = 0;
			}
			pref[i][sl[w[h][i]-1]-'a']++;
		}
		for(int i : zapy[h]) {
			if(w[h].empty()) {
				res[i] = true;
				continue;
			}
			int who = v[i];
			int L = bin(tt[who].st, w[h]), R = bin(tt[who].nd, w[h]);
			int c = 0;
			REP(j, 26) {
				int a = 0;
				if(R) a += pref[R-1][j];
				if(L) a -= pref[L-1][j];
				assert(a >= 0);
				//if(i == 4) printf("%d ", a);
				c += a % 2;
			}
			//if(i == 4) puts("");
			//printf("%d - %d\n", i, c);
			if(c <= 1) res[i] = true;
		}
	}
	REP(i, q) puts(res[i] ? "Yes" : "No");
	return 0;
}