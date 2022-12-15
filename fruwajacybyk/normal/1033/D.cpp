#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define all(v) (v).begin(),(v).end()

#define PII pair<int,int>
#define mp make_pair
#define st first
#define nd second
#define pb push_back
#define lint long long int
#define VI vector<int>

#define debug(x) {cerr <<#x <<" = " <<x <<endl; }
#define debug2(x,y) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y <<endl; } 
#define debug3(x,y,z) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y << ", " << #z << " = " << z <<endl; } 
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<endl; }}
#define debugt(t,n) {{cerr <<#t <<" = "; FOR(it,0,(n)) cerr <<t[it] <<", "; cerr <<endl; }}

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
#define jeb() fflush(0);

using namespace std;

const int max_n = 2e5+5;

int n;
vector<lint> v;
map<lint, int> roz;

lint gcd(lint a, lint b) {
	return a == 0 ? b : gcd(b%a, a);
}

lint sq(lint a) {
		lint tr = sqrt(a);
		for (lint j = max(tr-3,0LL);j<=tr+3;j++) {
			if (j*j == a) {
				return j;		
			}
		}
		return -1;
}

lint crr(lint a) {
		lint tr = pow(a*1.,1./3.);
		for (lint j = max(tr-3,0LL);j<=tr+3;j++) {
			if (j*j*j == a) {
				return j;		
			}
		}
		return -1;
}

int mod = 998244353;

int main() {
	make(n);
	FOR(i,0,n) {
		lint u;
		scanf("%lld",&u);
		v.pb(u);
	}
	int ans = 1;
	sort(all(v));
	map<lint, int> dupa;
	FOR(j,0,v.size()) dupa[v[j]]++;
	FORE(j, dupa) {
		lint u = j->st;
		int ile = j->nd;
		lint uu = sq(u);
		lint uuu = crr(u);
		if (uu == -1 && uuu == -1) {
			bool ok = false;
			FOR(j,0,n) {
				lint d = gcd(u, v[j]) ;
				if (d == 1 || d == u) continue;
				else {
					ok = true;
					roz[d] += ile;
					roz[u/d] += ile;
					break;
				}
			}
			if (!ok) {
				ans = (ans * 1LL * (ile+1))%mod;
				ans = (ans * 1LL * (ile+1))%mod;
			}
		} else {
			if (uuu != -1) {
				roz[uuu] += 3*ile;
			} else {
				lint uuww = sq(uu);
				if (uuww == -1) {
					roz[uu]+=2*ile;
				}
				else {
					roz[uuww]+=4*ile;
				}
			}
		}
	}
	FORE(j,roz) {
		ans = (ans * 1LL * (j->nd + 1)) % mod;
	}
	printf("%d\n", ans);
}