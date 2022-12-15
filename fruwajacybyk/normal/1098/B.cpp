#include <bits/stdc++.h>
#include <unistd.h>

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

int n, m;

char ss[300005];
vector<char> s[300005];

vector<pair<char, char> > w =  {{'A','T'}, {'A','C'}, {'A','G'}, {'T', 'C'}, {'T', 'G'}, {'C','G'}};
vector<pair<char, char> > rw = {{'C','G'}, {'T','G'}, {'C','T'}, {'A', 'G'}, {'A', 'C'}, {'T','A'}};
int co[300005];


int main () {
	read2(n, m);
	FOR(i,0,n) {
		scanf("%s", ss);
		FOR(j,0,m) s[i].pb(ss[j]);
	}
	int best = 0;
	int czyW = 1;
	int xxx = 0;
	FOR(ii,0,6) {
		int ile = 0;
		FOR(i,0,n) {
			char L1 = w[ii].st, L2 = w[ii].nd;
			if (i%2 == 1) {
				L1 = rw[ii].st, L2 = rw[ii].nd;
			}
			int x[2]; x[0] = x[1] = 0;
			FOR(j,0,m) {
				if (s[i][j] == L1) x[j%2]++;
				if (s[i][j] == L2) x[1-(j%2)]++;
			}
			ile += max(x[0], x[1]);
		}
		if (ile > best) {
			best = ile;
			xxx = ii;
		}
	}
	
	FOR(ii,0,6) {
		int ile = 0;
		FOR(i,0,m) {
			char L1 = w[ii].st, L2 = w[ii].nd;
			if (i%2 == 1) {
				L1 = rw[ii].st, L2 = rw[ii].nd;
			}
			int x[2]; x[0] = x[1] = 0;
			FOR(j,0,n) {
				if (s[j][i] == L1) x[j%2]++;
				if (s[j][i] == L2) x[1-(j%2)]++;
			}
			ile += max(x[0], x[1]);
		}
		if (ile > best) {
			best = ile;
			xxx = ii;
			czyW = 0;
		}
	}
	
	if (czyW == 1) {
		int ii = xxx;
		FOR(i,0,n) {
			char L1 = w[ii].st, L2 = w[ii].nd;
			if (i%2 == 1) {
				L1 = rw[ii].st, L2 = rw[ii].nd;
			}
			int x[2]; x[0] = x[1] = 0;
			FOR(j,0,m) {
				if (s[i][j] == L1) x[j%2]++;
				if (s[i][j] == L2) x[1-(j%2)]++;
			}
			if (x[0] >= x[1]) {
				FOR(j,0,m) {
					if (j%2) s[i][j] = L2;
					else s[i][j] = L1;
				}
			} else {
				FOR(j,0,m) {
					if (j%2) s[i][j] = L1;
					else s[i][j] = L2;
				}
			}
		}
	} else {
		int ii = xxx;
		FOR(i,0,m) {
			char L1 = w[ii].st, L2 = w[ii].nd;
			if (i%2 == 1) {
				L1 = rw[ii].st, L2 = rw[ii].nd;
			}
			int x[2]; x[0] = x[1] = 0;
			FOR(j,0,n) {
				if (s[j][i] == L1) x[j%2]++;
				if (s[j][i] == L2) x[1-(j%2)]++;
			}
			if (x[0] >= x[1]) {
				FOR(j,0,n) {
					if (j%2) s[j][i] = L2;
					else s[j][i] = L1;
				}
			} else {
				FOR(j,0,n) {
					if (j%2) s[j][i] = L1;
					else s[j][i] = L2;
				}
			}
		}
	}
	FOR(i,0,n) {
		FOR(j,0,m) {
			putchar(s[i][j]);
		}
		putchar('\n');
	}
}