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
#define jeb() fflush(0);

using namespace std;

const int max_n = 1e6;

int n, m;
lint score[max_n];
lint moj[max_n][2];

lint rob(int a, int b) {
	return min(moj[a][0]+moj[b][1], moj[a][1] + moj[b][0]);
}

int main() {
	read2(n, m);
	lint sumka = 0;
	FOR(i,0,n) {
		make2(x,y);
		moj[i][0] = x;
		moj[i][1] = y;
		sumka += x + y;
	}
	FOR(i,0,n) score[i] = sumka;
	FOR(i,0,n) {
		score[i] += (n-2)*1LL*(moj[i][0] + moj[i][1]);
	}
	FOR(i,0,m) {
		make2(a, b);
		a--; b--;
		score[a] -= 2*rob(a,b);
		score[b] -= 2*rob(b,a);
	}
	vector<pair<lint,int> > dupa;
	FOR(i,0,n) {
		dupa.pb(mp(moj[i][0] - moj[i][1], i));
	}
	sort(all(dupa));
	lint suf = 0;
	lint pref = 0;
	FOR(i,1,n) suf += dupa[i].st;
	FOR(i,0,n) {
		int kto = dupa[i].nd;
		score[kto] -= (suf-(n-i-1)*1LL*dupa[i].st) + (i*1LL*dupa[i].st-pref);
		pref += dupa[i].st;
		if (i!=n-1) suf -= dupa[i+1].st;
	}
	FOR(i,0,n) {
		printf("%lld ", score[i]/2);
	}
	printf("\n");
}