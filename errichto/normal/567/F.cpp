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
const int nax = 105;

ll dp[nax][nax];
int r[nax][nax];
int n;
const int L = 1, G = 2, E = 3, LE = 4, GE = 5;
int me[7][7];
int odw(int a) {
	if(a == L) return G;
	else if(a == G) return L;
	else if(a == E) return E;
	else if(a == LE) return GE;
	else if(a == GE) return LE;
	if(a == 0) return 0;
	assert(false);
}

void inpu(int a, int b, int what) {
	if(r[a][b] == 0 || r[a][b] == what) {
		r[a][b] = what;
		return;
	}
	r[a][b] = me[r[a][b]][what];
	if(r[a][b] == 0) {
		puts("0");
		exit(0);
	}
}

bool czy(int a, int b, int what) {
	if(a > b) {
		swap(a, b);
		what = odw(what);
	}
	return r[a][b] == what;
}

bool ok(int low, int high, int c, int d) {
	if(r[c][d] == L || r[c][d] == G) return false;
	REP(tries, 2) {
		FOR(i, low + 1, high - 1) {
			int a;
			if(c <= i) a = r[c][i];
			else a = odw(r[i][c]);
			if(a == G || a == GE || a == E) return false;
		}
		swap(c, d);
	}
	return true;
}

int main()
{
	me[L][LE] = me[LE][L] = L;
	me[G][GE] = me[GE][G] = G;
	me[E][LE] = me[LE][E] = E;
	me[E][GE] = me[GE][E] = E;
	int k;
	scanf("%d%d", &n, &k);
	REP(i, k) {
		char sl[5];
		int a, b;
		scanf("%d%s%d", &a, sl, &b);
		int what = 0;
		int d = strlen(sl);
		if(d == 1) {
			if(sl[0] == '>') what = G;
			else if(sl[0] == '<') what = L;
			else if(sl[0] == '=') what = E;
			else assert(false);
		}
		else {
			assert(d == 2);
			if(sl[0] == '>') what = GE;
			else if(sl[0] == '<') what = LE;
			else assert(false);
		}
		if(a <= b) inpu(a, b, what);
		else inpu(b, a, odw(what));
	}
	//printf("%d\n", r[2][3]);
	dp[0][2*n+1] = 1;
	ll res = 0;
	for(int i = 0; i <= 2 * n; ++i)
		for(int j = 2 * n + 1; j >= i + 3; --j) {
			ll me = dp[i][j];
			if(me == 0) continue;
			if(i + 3 == j) {
				if(ok(i+1,j-1,i+1,j-1)) {
					res += me;
					//printf("%d %d\n", i, j);
				}
				continue;
			}
			if(ok(i+2,j,i+1,i+2)) dp[i+2][j] += me;
			if(ok(i,j-2,j-2,j-1)) dp[i][j-2] += me;
			if(ok(i+1,j-1,i+1,j-1)) dp[i+1][j-1] += me;
		}
	printf("%lld\n", res);
	return 0;
}