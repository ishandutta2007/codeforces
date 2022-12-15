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

const int max_n = 150;

int n;
int tab[max_n][5];
int solved[6];

int chuj[6][6][5005];

int mini = 1e9 + 8;

int moge(VI& pkty) {
	int moje = 0;
	int jego = 0;
	FOR(i,0,5) {
		if (tab[0][i] != -1) {
			moje += (pkty[i]+1)*(500-2*tab[0][i]);
		}
		if (tab[1][i] != -1) {
			jego += (pkty[i]+1)*(500-2*tab[1][i]);
		}
	}
	if (moje <= jego) return 1e9+8;
	FOR(dupa,0,min(5000,mini)) {
		bool ok = true;
		FOR(i,0,5) {
			if (chuj[i][pkty[i]][dupa]==0) ok = false;
		}
		if (ok) return dupa;
	}
	return 1e9+8;
}

void wypelnij() {
	FOR(i,0,5) {
		FOR(j,0,6) {
			int x = solved[i];
			FOR(u,0,5000) {
				chuj[i][j][u] = 0;
				if (x*(1<<j)<= u+n ) {
					if (j != 5) {
						if (x*(1<<(j+1)) > u+n) {
							chuj[i][j][u] = 1;
						}
					}
					else chuj[i][j][u] = 1;
				}
			}
			FOR(u,0,5000) {
				if (tab[0][i]!=-1 && chuj[i][j][u] == 0) {
					FOR(w,1,u+1) {
						if ((x+w)*(1<<j) <= u+n) {
							if (j!=5) {
								if ((x+w+u)*(1<<(j+1)) > u+n) 
									chuj[i][j][u] = 1;
							}
							else chuj[i][j][u] = 1;
							if (chuj[i][j][u] == 1) break;
						} else break;
					}
				}
			}
		}
	}
}

int main() {
	read(n);
	FOR(i,0,n) {
		FOR(u,0, 5) {
			make(a);
			tab[i][u] = a;
			if (a != -1) solved[u]++;
		}
	}
	wypelnij();
	FOR(a,0,6) {
		FOR(b,0,6) {
			FOR(c,0,6) {
				FOR(d,0,6) {
					FOR(e,0,6) {
						VI pkty = {a,b,c,d,e};
						mini = min(mini, moge(pkty));
					}
				}
			}
		}
	}
	if (mini == 1e9 + 8) {
		printf("-1\n");
	}
	else printf("%d\n", mini);
}