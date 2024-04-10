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

int x1,yz1,x2,y2;
int v,t;
int vx,vy;
int wx, wy;

bool check(double time) {
    double t1 = min(t*1.,time);
    double t2 = max(0., time-t*1.);
    
    double x11 = x1*1.+vx*1.*t1 + wx*1.*t2;
    double y11 = yz1*1.+vy*1.*t1 + wy*1.*t2;

    double dist = sqrt((x2*1.-x11)*(x2*1.-x11) + (y2*1.-y11)*(y2*1.-y11));
    if ( dist/(v*1.) <= time) return true;
  return false;
}

int main(){
  read4(x1,yz1,x2,y2);
  read2(v,t);
  read2(vx,vy);
  read2(wx,wy);
  double lewy = 0., prawy = t*1.;
  if (check(t*1.)) {
    lewy = 0.; prawy = t*1.;
  } else {
    lewy = t*1.; prawy = 1e15;
  }
  while ( prawy - lewy > 1e-8) {
    double mid = (prawy+lewy)/2.;
    if (check(mid)) prawy = mid;
    else lewy = mid;
  }
  printf("%.17lf\n",prawy);

}