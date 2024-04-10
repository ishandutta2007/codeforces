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

char s[1005];
int ile[1005][2];

void solve() {
	scanf("%s", s);
	int n = strlen(s);
	int best = n;
	FOR(i,0,n) FOR(j,0,2) ile[i][j]=0;
	ile[0][0] = (s[0]=='0') ? 1 : 0;
	ile[0][1] = (s[0]=='1') ? 1 : 0;
	FOR(i,1,n) {
		FOR(j,0,2) {
			ile[i][j] = ile[i-1][j] + ((s[i]==('0'+j)) ? 1 : 0);
		}
	}
	int c0 = ile[n-1][0];
	int c1 = ile[n-1][1];
	FOR(i,0,n) {
		int wyn = min(ile[i][0], ile[i][1]) + min(c0-ile[i][0], c1-ile[i][1]);
		best = min(best, wyn);
	}
	printf("%d\n", best);
}

int main() {
	make(z);
	while (z--) {
		solve();
	}
}