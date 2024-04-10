#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define all(v) (v).begin(),(v).end()

#define VI vector<int>
#define PII pair<int,int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define lint long long int

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

#define REP(i,n) FOR(i,0,n)

using namespace std;

const int max_n = 1e6+5;

int minp[100005];

void sito() {
	FOR(i,0,40000) minp[i] = i;
	for( int i =2 ; i < 40000; i++) {
		if (minp[i]==i) for(int j = i*i ; j<40000; j+=i) minp[j] = i;
	}
}

int dupa[max_n];
lint cost[max_n][3];

lint INF = 1e16;

int main() {
	sito();
	make(n);
	lint A, B;
	cin >> A >> B;
	makev(v, n);
	lint ans = INF;
	

	FOR(uu,0,2) {
		int x = v[0];
		VI pos;
		FOR(ux,x-1,x+2) {
			VI pos2;
			for (int i = 2; i*i<=ux; i++) {
					if (ux%i==0 && minp[i]==i) pos.pb(i), pos2.pb(i);
			}
			int zz = ux;
			FORE(i, pos2) zz = zz/(*i);
			if (zz > 1) pos.pb(zz);
		}
		FORE(i, pos) {
			int p = *i;
			cost[0][0] = (v[0]%p==0) ? 0 : B;
			cost[0][1] = INF;
			cost[0][2] = INF;
			FOR(j,1,n) {
				if (v[j] % p == 0 ) {
					cost[j][0] = cost[j-1][0];
					cost[j][1] = min(cost[j-1][0]+A, cost[j-1][1]+A);
					cost[j][2] = min(cost[j-1][1], cost[j-1][2]);
				} else if ( (v[j]-1)%p==0 || (v[j]+1)%p==0) {
					cost[j][0] = cost[j-1][0] + B;
					cost[j][1] = min(cost[j-1][0]+A, cost[j-1][1]+A);
					cost[j][2] = min(cost[j-1][2]+B, cost[j-1][1]+B);
				} else {
					cost[j][0] = INF; 
					cost[j][1] = min(cost[j-1][0]+A, cost[j-1][1]+A);
					cost[j][2] = INF;
				}
			}
			ans = min(ans, cost[n-1][0]);
			ans = min(ans, cost[n-1][1]);
			ans = min(ans, cost[n-1][2]);
		}
		for(int i=0; i < n-i-1; i++) swap(v[i], v[n-1-i]);
	}
	printf("%I64d\n", ans);

}