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

const int max_n = 1e6+5;

char s[max_n];

const int mod = 1e9 + 7;

int powmod(int a, int n) {
	if (n == 0) return 1;
	int sq  = powmod(a, n/2);
	sq = (sq * 1LL * sq) % mod;
	if (n%2==0) return sq;
	return (sq * 1LL * a) % mod;
}

int main() {
	scanf("%s", s);
	int n = strlen(s);
	int ans = 0;
	VI v;
	int ile = 0;
	int pos = 0;
	char C = 'a';
	while (pos < n) {
		while (pos < n && s[pos]==C) {
			ile++;
			pos++;
		} 
		if (pos == n) {
			v.pb(ile);
		}
		else {
			v.pb(ile);
			ile = 0;
			C = 'a'+'b'-C;
		}
	}
	int suma = 0;
	for (int i = 0; i < v.size(); i+=2) {
		int hb = 0;
		if (i+1 < v.size()) hb = v[i+1];
		suma += v[i];
		int ksi = (powmod(2, suma) + mod - 1)%mod; 
		ans += (ksi * 1LL * hb) % mod;
		ans %= mod;
	}
	printf("%d\n", ans);
}