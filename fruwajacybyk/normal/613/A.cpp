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

using namespace std;

lint dist(int a, int b) {
	return (a*1LL*a +1LL*(b*1LL*b));
}



int main() {
	make(n);
	make2(x,y);
	vector<PII> v;
	FOR(i,0,n) {
		make2(a,b); v.pb(mp(a-x,b-y));
	}
	 
	lint maxd = dist(v[0].st, v[0].nd);
	lint mind = maxd;
	FOR(i,0,n) {
		mind = min(mind, dist(v[i].st, v[i].nd));
		maxd = max(maxd, dist(v[i].st, v[i].nd));
	}
	double d1 = maxd*1.;
	double d2 = mind*1.;
	FOR(i,0,n) {
		int x1 = v[i].st, x2 = v[(i+1)%n].st;
		int y1 = v[i].nd, y2 = v[(i+1)%n].nd;
		double alpha = (x2*1LL*(x2-x1) + y2*1LL*(y2-y1))/(1.*((x1-x2)*1LL*(x1-x2)+(y1-y2)*1LL*(y1-y2)));
		if (alpha > 0. && alpha < 1.) {
			double xx = (x1*alpha + (1.-alpha)*x2);
			double yy = (y1*alpha + (1.-alpha)*y2);
			d1 = max(d1, xx*xx+yy*yy);
			d2 = min(d2, xx*xx+yy*yy);
		}
	}

	printf("%.18lf\n", M_PI*1.*(d1-d2));
}