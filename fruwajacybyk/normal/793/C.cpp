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



int main() {
	make(n);
	make2(x1,y1);
	make2(x2,y2);
	bool ok = true;
	if (x1 == x2 || y1 == y2) {
		ok = false;
	}
	double t1 = -1, t2 = -1;
	double cand;
	FOR(i,0,n) {
		make2(x,y);
		make2(vx,vy);
		if (vx == 0) {
			if (x<=x1 || x>=x2) ok = false;
		} 
		else if (vx < 0) {
			if (x <= x1) ok = false;
			if (x > x2) {
				cand = (x-x2)*1./max(vx,-vx);
				if (t1 == -1) t1 = cand;
				else t1 = max(t1, cand);
			}
			cand = (x-x1)*1./max(vx, -vx);
			if (t2==-1) t2 = cand;
			else t2 = min(t2, cand);
		} else {
			if (x >= x2) ok = false;
			if (x < x1) {
				cand = (x1-x)*1./vx;
				if (t1 == -1) t1 = cand;
				else t1 = max(t1, cand);
			} 
			cand = (x2-x)*1./vx;
			if (t2==-1) t2 = cand;
			else t2 = min(t2, cand);
		}
		if (vy == 0) {
			if (y<=y1 || y>=y2) ok = false;
		} 
		else if (vy < 0) {
			if (y <= y1) ok = false;
			if (y > y2) {
				cand = (y-y2)*1./max(vy,-vy);
				if (t1 == -1) t1 = cand;
				else t1 = max(t1, cand);
			}
			cand = (y-y1)*1./max(vy, -vy);
			if (t2==-1) t2 = cand;
			else t2 = min(t2, cand);
		} else {
			if (y >= y2) ok = false;
			if (y < y1) {
				cand = (y1-y)*1./vy;
				if (t1 == -1) t1 = cand;
				else t1 = max(t1, cand);
			} 
			cand = (y2-y)*1./vy;
			if (t2==-1) t2 = cand;
			else t2 = min(t2, cand);
		}
	}
	if (!ok) printf("-1\n");
	else if (t1 == -1 || t2 == -1) {
		if (t1 == -1) printf("0\n");
		else printf("%.17lf\n", t1);
	}
	else {
		if (t2 < t1) printf("-1\n");
		else if (t2 - t1 <= 0) printf("-1\n");
		else printf("%.17lf\n", t1);
	}
}