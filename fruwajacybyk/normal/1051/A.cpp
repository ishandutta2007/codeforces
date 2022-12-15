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
#define jeb fflush(stdout)

using namespace std;

const int max_n = 100005;

char s[105];
char t[105];
char dla[105];
int n;

bool check() {
	int x = 0;
	FOR(i,0,n) {
		if (s[i] >= '0' && s[i]<='9') x |= 1;
		if (s[i] >= 'a' && s[i]<='z') x |= 2;
		if (s[i] >= 'A' && s[i]<='Z') x |= 4;
	}
	if (x == 7) return true;
	return false;
}


int main() {
	make(tt);
	vector<char> v;
	FOR(i,0,9) v.pb('0'+i);
	FOR(i,0,26) v.pb('a'+i);
	FOR(i,0,26) v.pb('A'+i);
	while (tt--) {
		scanf("%s", s);
		n = strlen(s);
		FOR(j,0,n+1) t[j] = s[j];
		if (check()) {
			printf("%s\n", s);
			continue;
		}
		int best = 4;
		FOR(j,0,n+1) dla[j] = s[j];
		FOR(i,0,62) FOR(j,0,62) FOR(k,0,62) {
			s[0] = v[i];
			s[1] = v[j];
			s[2] = v[k];
			if (check()) {
				int l = 100, r = -1;
				FOR(u,0,3) {
					if (s[u] != t[u]) {
						l = min(l, u);
						r = max(r, u);
					}
				}
				if (r-l+1 < best) {
					best = r-l+1;
					FOR(jj,0,n+1) dla[jj] = s[jj];
				}
			}
		}
		printf("%s\n", dla);
	}
}