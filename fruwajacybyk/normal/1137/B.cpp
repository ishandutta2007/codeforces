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

#define debug(x) {cout <<#x <<" = " <<x <<endl; }
#define debug2(x,y) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y <<endl; } 
#define debug3(x,y,z) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y << ", " << #z << " = " << z <<endl; } 
#define debugv(x) {{cout <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<endl; }}
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
#define jeb() fflush(stdout);

using namespace std;
const int max_n = 2e6 + 5;

char s[max_n], t[max_n];
int ile[2];
int kmp[max_n];
int basic[2];
int need[2];

int main() {
	scanf("%s", s);
	scanf("%s", t);
	int n = strlen(s);
	FOR(i,0,n) {
		ile[s[i] - '0']++;
	}
	int m = strlen(t);
	kmp[0] = 0;
	FOR(i,1,m) {
		kmp[i] = kmp[i-1];
		while (kmp[i] > 0 && t[i] != t[kmp[i]]) kmp[i] = kmp[kmp[i] - 1];
		if (t[i] == t[kmp[i]]) kmp[i]++;
	}

	int alef = kmp[m-1];
	FOR(i,0,m) {
		basic[t[i]-'0']++;
		if (i >= alef) 
			need[t[i]-'0']++;
	}
	if (ile[0] >= basic[0] && ile[1] >= basic[1]) {
		ile[0] -= basic[0]; ile[1] -= basic[1];
		printf("%s", t);
		while (ile[0] >= need[0] && ile[1] >= need[1]) {
			ile[0] -= need[0]; ile[1] -= need[1];
			FOR(i,alef,m) putchar(t[i]);
		}
		FOR(i,0,ile[0]) putchar('0');
		FOR(i,0,ile[1]) putchar('1');
		putchar('\n');
	} else {
		printf("%s\n", s);
	}
}