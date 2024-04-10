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
const int nax = 30123;
int mod;
map<int,int> mapka;
int value[nax];
int t[nax];
int fib[nax];
int c[nax];
int low[nax], high[nax];
ll ans[nax];
int ktory[nax];

int main() {
	int n;
	scanf("%d%d", &n, &mod);
	set<int> s;
	REP(i, n) {
		scanf("%d", &t[i]);
		s.insert(t[i]);
	}
	int T = 0;
	for(int x : s) {
		++T;
		mapka[x] = T;
		value[T] = x;
	}
	fib[1] = 1 % mod;
	fib[2] = 1 % mod;
	FOR(i,3,nax-1) fib[i] = (fib[i-1] + fib[i-2]) % mod;
	int q;
	scanf("%d", &q);
	REP(i, q) {
		scanf("%d%d", &low[i], &high[i]);
		--low[i];
		--high[i];
	}
	vector<pii> w;
	REP(i, n) w.pb(mp(t[i], i));
	sort(w.begin(), w.end());
	for(pii para : w) {
		int val = para.first;
		int lol = mapka[val];
		int i = para.second;
		val %= mod;
		REP(j, q) if(low[j] <= i && i <= high[j] && c[j] < lol) {
			c[j] = lol;
			ktory[j]++;
			ans[j] += fib[ktory[j]] * val;
		}
	}
	REP(i, q) printf("%lld\n", ans[i] % mod);
	return 0;
}