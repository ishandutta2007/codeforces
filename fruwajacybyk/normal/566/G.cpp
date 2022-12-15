#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cstring>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)

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

#define all(v) (v).begin(), (v).end()

#define make( x) int (x); scanf("%d",&(x));
#define make2( x, y) int (x), (y); scanf("%d%d",&(x),&(y));
#define make3(x, y, z) int (x), (y), (z); scanf("%d%d%d",&(x),&(y),&(z));
#define make4(x, y, z, t) int (x), (y), (z), (t); scanf("%d%d%d%d",&(x),&(y),&(z),&(t));
#define IOS ios_base::sync_with_stdio(0)
#define HEAP priority_queue

#define read( x) scanf("%d",&(x));
#define read2( x, y) scanf("%d%d",&(x),&(y));
#define read3(x, y, z) scanf("%d%d%d",&(x),&(y),&(z));
#define read4(x, y, z, t) scanf("%d%d%d%d",&(x),&(y),&(z),&(t));

using namespace std;
#define max_n 100005

inline bool left(PII& a,PII& b, PII&c ){
  return (b.st-a.st)*1LL*(c.nd-a.nd) - (c.st-a.st)*1LL*(b.nd-a.nd) <=0 ;
}

inline void add_point(vector<PII>& hull, PII pt, int limit){
  while(hull.size() > limit && left(hull[hull.size()-2],hull[hull.size()-1],pt)) hull.pop_back();
  hull.pb(pt);
}


lint cpr(PII& a, PII& b, PII& c){
  return (b.st-a.st)*1LL*(c.nd-a.nd) - (c.st-a.st)*1LL*(b.nd-a.nd)  ;
}

int main(){
  make2(n,m);
  make2(x,y);
  vector<PII> v1,v2;
  FOR(i,0,n){
    make2(a,b); v1.pb(mp(a,b));
  }
  int m1 = 0, m2 = 0;
  FOR(j,0,m){
    make2(c,d); v2.pb(mp(c,d));
    m1 = max(c,m1);
    m2 = max(d,m2);
  } 
  v2.pb(mp(m1,0));
  v2.pb(mp(0,m2));
  v2.pb(mp(0,0));
  sort(all(v2));
  v2.resize(unique(all(v2))-v2.begin());
  vector<PII> hull;
  if(v2.size()>1){
    FOR(i,0,v2.size()) add_point(hull,v2[i],1);
    int cursize = hull.size();
    FORD(i,v2.size()-1,0) add_point(hull,v2[i],cursize);
    hull.pop_back();
  }
  else hull = v2;
  sort(all(hull));
  sort(all(v1));
  int j = 0;
  bool ans = true;
  swap(hull[hull.size()-1],hull[hull.size()-2]);
  FOR(i,0,v1.size()){
    if(v1[i]>=hull.back()){
      printf("Max\n");
      return 0;
    }
    while(v1[i]>hull[j+1]) j++;
    if(cpr(hull[j],hull[j+1],v1[i])>=0){
        debug(cpr(hull[j],hull[j+1],v1[i]));
       printf("Max\n");
       return 0;
    }
  }
  printf("Min\n");
  

}