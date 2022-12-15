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
#define REP(i,n) FOR(i,0,(n))
 
using namespace std;

const int max_n = 1e5+5;

double S[max_n], p[max_n], q[max_n];
double Sp[max_n];
double prefS[max_n];


int main() {
	make(n);
	vector<double> mn, mx;
	FOR(i,0,n) {
		double f; scanf("%lf", &f);
		mx.pb(f);
	}
	FOR(i,0,n) {
		double f; scanf("%lf", &f);
		mn.pb(f);
	}
	FOR(i,0,n) S[i] = mx[i] + mn[i];
	prefS[0] = S[0];
	FOR(i,1,n) prefS[i] = prefS[i-1] + S[i];
	FOR(i,0,n) {
		double a = 1.;
		double b = - (S[i] + (i==0 ? 0 : prefS[i-1]-2.*Sp[i-1]));
		double c = -S[i]*1.*(i==0 ? 0 : Sp[i-1])+mx[i];
//		debug3(a, b, c);
		double delta = max(b*b-4.*a*c,0.);
	//	debug(delta);
		double ps = 0.5*(-b-sqrt(delta));
		Sp[i] = (i==0 ? ps : Sp[i-1]+ps);
		p[i] = ps;
		q[i] = S[i]-ps;
	}
	FOR(i,0,n) printf("%.17lf ",p[i]);
	printf("\n");
	FOR(i,0,n) printf("%.17lf ",q[i]);
	printf("\n");
}