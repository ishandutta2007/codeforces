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

#define max_n 500

int n;
VI v;
set<PII> poss[35][8];

int dx[] = {0, 0,1,-1,1, 1,-1,-1};
int dy[] = {1,-1,0, 0,1,-1, 1,-1};

map<PII, int> name;
int nxt[8][2];

PII sum(PII a, PII b) {
	return mp(a.st + b.st, a.nd+b.nd);
}

PII mul(PII a, int k) {
	return mp(a.st*k, a.nd*k);
}

int main() {
	read(n);
	readv(v, n);
	FOR(i,0,8) name[mp(dx[i], dy[i])] = i;
	FOR(i,0,8) {
		if (dx[i] == 0) {
			nxt[i][0] = name[mp(1,dy[i])];
			nxt[i][1] = name[mp(-1,dy[i])];
		}
		else if (dy[i] == 0) {
			nxt[i][0] = name[mp(dx[i], 1)];
			nxt[i][1] = name[mp(dx[i], -1)];
		}
		else {
			nxt[i][0] = name[mp(dx[i],0)];
			nxt[i][1] = name[mp(0, dy[i])];
		}
	}
	FOR(kier,0,8) {
		FOR(z,1,v[n-1]+1) {
			poss[n-1][kier].insert(mul(mp(dx[kier], dy[kier]),z));
		}
	}
	FORD(i,n-2,0) {
		FOR(kier, 0, 8) {
			FOR(z,1,v[i]+1) {
				poss[i][kier].insert(mul(mp(dx[kier], dy[kier]),z));
			}
			PII start = mul(mp(dx[kier], dy[kier]), v[i]);
			FOR(j,0,2) {
				FORE(u, poss[i+1][nxt[kier][j]]) {
					poss[i][kier].insert(sum(start, *u));
				}
			}
		}
	}
	printf("%d\n", poss[0][0].size());
}