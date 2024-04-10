#include <bits/stdc++.h>
using namespace std;
//{
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define VAR(v, i) __typeof(i) v=(i)
#define all(v) (v).begin(),(v).end()

#define PII pair<int,int>
#define st first
#define nd second
#define pb push_back
#define lint long long int
#define VI vector<int>

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
	*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
};
//{
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

#define make( x) int (x); scanf("%d",&(x));
#define make2( x, y) int (x), (y); scanf("%d%d",&(x),&(y));
#define make3(x, y, z) int (x), (y), (z); scanf("%d%d%d",&(x),&(y),&(z));
#define make4(x, y, z, t) int (x), (y), (z), (t); scanf("%d%d%d%d",&(x),&(y),&(z),&(t));
#define makev(v,n) VI (v); FOR(i,0,(n)) { make(a); (v).pb(a);} 
#define IOS ios_base::sync_with_stdio(0)
#define HEAP priority_queue

#define read( x) scanf("%d",&(x));
#define read2( x, y) scanf("%d%d",&(x),&(y));
#define read3(x, y, z) scanf("%d%d%d",&(x),&(y),&(z));
#define read4(x, y, z, t) scanf("%d%d%d%d",&(x),&(y),&(z),&(t));
#define readv(v,n) FOR(i,0,(n)) { make(a); (v).pb(a);}
#define jeb() fflush(stdout);
//}

char s[55][55];

int n, m;

int diff(int i, int j) {
		int ans = 0;
		FOR(k,0,m) if (s[i][k]!=s[j][k]) ans++;
		return ans;
}

void build(int i, int j, int k) {
	FOR(u,0,m) s[n][u] = s[i][u];
	s[n][k] = s[j][k];
	s[n][m] = '\0';
}

bool check() {
	FOR(i,0,n) {
		if (diff(i,n) > 1) return false;
	}
	return true;
}

void solve() {
	read2(n, m);
	FOR(i,0,n) {
		scanf("%s", s[i]);
	}
	FOR(i,0,n) FOR(j,0,n) FOR(k,0,m) {
		build(i,j,k);
		if (check()) {
			printf("%s\n", s[n]);
			return;
		}
	}
	printf("-1\n");
	

}


int main() {

	make(z);
	while (z--) {
		solve();
	}
}