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


int ile[55];
int MAXLOG = 39;
int plusy[55];
int koncowki[45];
int gosci[45];

int mojePlusy[55];

bool czy(int k) {
	FOR(j,0,42) mojePlusy[j] = plusy[j];
	FOR(j,0,42) koncowki[j] = 0;
	FOR(j,0,42) gosci[j] = 0;

	int mam = k;
	koncowki[0] = ile[0] - k;
	gosci[0] = k;
	FOR(j,1,40) {
		if (ile[j] <= mam) {
			mam = ile[j];
			koncowki[j] = 0;
			gosci[j] = ile[j];
		} else {
			int zostalo = ile[j] - mam;
			int dodam = min(mojePlusy[j], zostalo);
			mojePlusy[j+1] += dodam;
			zostalo -= dodam;
			koncowki[j] += zostalo;
			gosci[j] = mam;
		}
	}
	int koncow = 0;
	FORD(j, 39, 0) {
		koncow += koncowki[j];
		if (gosci[j] < koncow) {
			return false;
		}
	}
	return true;
}

int main() {
	make(n);
	map<lint,int> p2;
	FOR(i,0,40) p2.insert(mp(1LL<<i,i));
	int ans = 0;
	FOR(i,0,n) {
		lint a;
		scanf("%lld", &a);
		if (p2.find(a) != p2.end()) ile[p2[a]]++;
		else {
			lint p = 1;
			int log = 0;
			while (2*p<a) {
				if (ile[log]==0) {
					printf("-1\n");
					return 0;
				} 
				ile[log]--;
				p = p+p;
				log++;
			}
			ile[log]--;
			log++;
			plusy[log]++;
			ans++;
		}
	}
	VI goscie;
	FOR(i,0,ile[0]+1) {
		if (czy(i)) goscie.pb(ans+i);
	}
	if (goscie.size() == 0) {
		printf("-1\n");
		return 0;
	} else {
		sort(all(goscie));
		FORE(i, goscie) {
			printf("%d ", *i);
		}
		printf("\n");
	}
}