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
const int nax = 505;

bitset<nax> h[nax];
vi same[nax];
bool vis[nax];
char tab[nax];

void NO() {
	puts("No");
	exit(0);
}

void dfs(int a, int n, vi & w) {
	w.pb(a);
	vis[a] = true;
	RI(b, n) if(!vis[b] && h[a][b])
		dfs(b, n, w);
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	REP(_, m) {
		int a, b;
		scanf("%d%d", &a, &b);
		h[a][b] = true;
		h[b][a] = true;
	}
	RI(i, n) if(!vis[i]) {
		FOR(j, i+1, n) if(h[i][j]) {
			h[i][j] = h[j][i] = false;
			if(h[i] == h[j]) {
				vis[j] = true;
				same[i].pb(j);
			}
			h[i][j] = h[j][i] = true;
		}
	}
	int zyk = 0;
	RI(i, n) if(!vis[i]) {
		vis[i] = true;
		vector<vi> legs;
		RI(j, n) if(!vis[j] && h[i][j]) {
			vi w;
			dfs(j, n, w);
			legs.pb(w);
		}
		while(sz(legs) < 2) legs.pb(vi(0));
		if(sz(legs) > 2) NO();
		int a = sz(legs[0]);
		int b = sz(legs[1]);
		if(zyk + a + 1 + b > 3) NO();
		reverse(legs[0].begin(), legs[0].end());
		legs[0].pb(i);
		for(int c : legs[1]) legs[0].pb(c);
		for(int c : legs[0])
			tab[c] = 'a' + zyk++;
		++zyk;
	}
	RI(i, n) if(tab[i] >= 'a' && tab[i] <= 'c')
		for(int j : same[i]) tab[j] = tab[i];
	RI(i, n) assert(tab[i] >= 'a' && tab[i] <= 'c');
	RI(i, n) FOR(j, i + 1, n)
		if(h[i][j] != (abs(tab[i]-tab[j]) <= 1)) NO();
	puts("Yes");
	RI(i, n) printf("%c", tab[i]);
	puts("");
	return 0;
}