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

vector<PII> v;


inline bool left(PII& a, PII& b, PII& c) { //dla slabej otoczki zmienic na ostra nierownosc
  return (b.st - a.st) *1LL* (c.nd - a.nd) - (c.st - a.st) *1LL* (b.nd - a.nd) <= 0; // LL !
}

inline void add_point(vector<PII>& hull, PII pt, int limit) {

while(hull.size() > limit && left(hull[hull.size()-2], hull[hull.size()-1], pt))
  hull.pop_back();
  hull.pb(pt);
}

// IN: punkty (uwaga: sa sortowane)
// OUT: ich otoczka wypukla
// UWAGA: gdy wszystkie punkty na wejsciu sa wspolliniowe dla SLABEJ OTOCZKI
// kazdy punkt wewnetrzny jest zwrocony i w gornej i w dolnej polotoczce
// w kolejnosci obejscia

vector<PII> compute_hull(vector<PII>& in) {
  sort(all(in));
  in.resize(unique(all(in)) - in.begin()); //zakomentuj jak nie ma powtorzonych punktow
  if (in.size() <= 1) return in;
  vector<PII> out;
  FOR(i, 0, in.size()) add_point(out, in[i], 1);
  int cursize = out.size();
  FORD(i, in.size()-1, 0) add_point(out, in[i], cursize);
  out.pop_back();
  return out;
}


int main() {
  make3(n,p,q);
  int maxa = 0, maxb = 0;
  FOR(i,0,n) {
    make2(a,b); v.pb(mp(a,b));
    maxa = max(maxa, a);
    maxb = max(maxb, b);
  }
  v.pb(mp(0,0));
  v.pb(mp(0,maxb));
  v.pb(mp(maxa, 0));

  vector<PII> w = compute_hull(v);
  FOR(i,0,w.size()-1) {
    if(w[i] == mp(0,0)) continue;
    double alpha = (w[i+1].nd*1LL*p - w[i+1].st*1LL*q)*1./(1.*( (w[i].st-w[i+1].st)*1LL*q+(w[i+1].nd-w[i].nd)*1LL*p));
    if( alpha >= -1e-7 && alpha <= 1. + 1e-7) {
      printf("%.17lf\n", p*1./(alpha*w[i].st + (1.-alpha)*w[i+1].st));
      return 0;
    }
  }
}