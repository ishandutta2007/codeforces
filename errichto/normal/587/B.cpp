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
const int mod = 1e9 + 7;

void add(int & a, int b) {
	a += b;
	if(a >= mod) a -= mod;
}

/*int pw(int a, int b) {
	int r = 1;
	while(b) {
		if(b&1) r = (ll) r * a % mod;
		a = (ll) a * a % mod;
		b /= 2;
	}
	return r;
}*/

int n, lim;
ll total;
int t[nax];

void read() {
	scanf("%d%lld%d", &n, &total, &lim);
	set<int> s;
	REP(i, n) {
		scanf("%d", &t[i]);
		s.insert(t[i]);
	}
	map<int,int> m;
	int i = 0;
	for(int a : s) m[a] = i++;
	REP(i, n) t[i] = m[t[i]];
}

vector<vi> dp;
int pre[nax];
int s[nax], s2[nax];

int main() {
	read();
	// n * lim <= 10^6
	vi single = vi(n, 0);
	dp = vector<vi>(lim + 1, single);
	dp[0][0] = 1;
	RI(row, lim) {
		REP(i, n) {
			pre[i] = dp[row-1][i];
			if(i) add(pre[i], pre[i-1]);
		}
		REP(i, n) {
			add(dp[row][t[i]], pre[t[i]]);
			add(s[row], pre[t[i]]);
		}
	}
	RI(row, lim) {
		REP(i, n) {
			pre[i] = dp[row-1][i];
			if(i) add(pre[i], pre[i-1]);
		}
		int pom = total % n;
		REP(i, pom)
			add(s2[row], pre[t[i]]);
	}
	int res = 0;
	ll full = total / n;
	//ll bin = 1;
	RI(row, lim) {
		ll x = (row <= full + 1);
		//if(x < 0) x = 0;
		add(res, x * s2[row] % mod);
		//bin = bin * ((full - row + 1) % mod) % mod * pw(row, mod-2) % mod;
		x = (full - row + 1) % mod;
		if(x < 0) x = 0;
		add(res, x * s[row] % mod);
	}
	printf("%d\n", res);
	return 0;
}