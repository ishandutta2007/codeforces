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

const int max_n = 1e5 + 5;
const int mod = 1e9 + 7;

int m,n;
char s[max_n];
int zab[max_n];
VI dupa[30];

int main() {
	read(m);
	scanf("%s", s);
	int n = strlen(s);
	FOR(i,0,n) dupa[s[i]-'a'].pb(i);
	VI pozycje;
	int juz = -1;
	FOR(i,0,26) {
		FORE(j,dupa[i]) pozycje.pb(*j);
		sort(all(pozycje));
		if (pozycje.size() > 0) {
			bool ok = true;
			if (pozycje[0] >= m) ok = false;
			if (pozycje.back()+m<n) ok = false;
			FOR(j,0,pozycje.size() - 1) {
				if (pozycje[j+1] - pozycje[j] > m) ok = false;
			}
			if (ok) {
				juz = i;
				break;
			}
		}
	}
	pozycje.clear();
	FOR(i,0,juz) FORE(j, dupa[i]) pozycje.pb(*j);
	sort(all(pozycje));
	FOR(j,0,n) zab[j] = 0;
	FOR(j,0,pozycje.size()) {
		int start;
		if (j == 0) start = max(0, pozycje[j]-m+1);
		else start = max(pozycje[j-1] + 1, pozycje[j]-m+1);
		FOR(u,start, pozycje[j]+1) zab[u] = 1;
	}
	int act = 0;
	int ans = 0;
	int ostatni = -1;
	FOR(j,0,n-m+1) {
		if (zab[j] == 1) continue;
		if (ostatni>= j) continue;
		while (dupa[juz][act] < j) act++;
		while (act + 1 < dupa[juz].size() && dupa[juz][act+1]-m<j) act++;
		ostatni = dupa[juz][act];
		ans++;
	}
	FOR(i,0,juz) {
		FOR(j,0,dupa[i].size()) putchar('a'+i);
	}
	FOR(j,0,ans) putchar('a'+juz);
	putchar('\n');
}