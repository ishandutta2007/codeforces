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

int query(VI w) {
	printf("? %d", (int) w.size());
	FOR(i,0,w.size()) printf(" %d", w[i]);
	printf("\n"); 
	jeb();
	make(u);
	assert(u!=-1);
	return u;
}

int q2(int a, int b) {
	VI w;
	FOR(i,a,b+1) w.pb(i);
	return query(w);
}

char s[1000];
void ans(VI w) {
	printf("!");
	FOR(i,0,w.size()) printf(" %d", w[i]);
	printf("\n");
	jeb();
	scanf("%s", s);
}

void solve() {
	make2(n, k);
	vector<VI> s;
	FOR(i,0,k) {
		make(sajz); 
		VI loc; FOR(j,0,sajz) {
			make(a);
			loc.pb(a);
		} 
		s.pb(loc);
	}
	int maxi = q2(1,n);
	int a = 1, b = n;
	while (a!=b) {
		int mid = (a+b)/2;
		if (q2(a,mid) == maxi) b = mid;
		else a = mid+1;
	}
	int wew = -1;
	FOR(i,0,k) {
		FOR(j,0,s[i].size()) if (s[i][j]==a) wew = i;
	}
	if (wew == -1) {
		VI loc; FOR(i,0,k) loc.pb(maxi);
		ans(loc);
	} else {
		set<int> kij;
		FOR(i,0,s[wew].size()) kij.insert(s[wew][i]);
		VI poza;
		FOR(i,1,n+1) if (kij.count(i)==0) poza.pb(i);
		int u = query(poza);
		VI loc;
		FOR(i,0,k) loc.pb(maxi);
		loc[wew] = u;
		ans(loc);
	}
}

int main() {
	make(z);
	while (z--) {
		solve();
	}
}