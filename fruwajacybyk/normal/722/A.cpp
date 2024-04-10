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
 
 
using namespace std;

const int max_n = 2e5 + 5;

char s[10][100000];
char t[10];

int main() {
	make(n);
	int ile = 0;
	int lewo = 0, prawo = 24;
	if (n==12) lewo = 1, prawo = 13;
	FOR(i,lewo,prawo) {
		FOR(j,0,60) {
			s[0][ile] = (i/10)+'0';
			s[1][ile] = (i%10)+'0';
			s[2][ile] = ':';
			s[3][ile] = (j/10)+'0';
			s[4][ile] = (j%10)+'0';
			ile++;
		}
	}
	int best = 10;
	int dla = 0;
	scanf("%s", t);
	FOR(i,0,ile) {
		int licz = 0;
		FOR(j,0,5) {
			if (s[j][i] != t[j]) licz++;
		}
		if (licz < best) {
			best = licz;
			dla = i;
		}
	}
	FOR(i,0,5) {
		putchar(s[i][dla]);
	}
	putchar('\n');
	return 0;
}