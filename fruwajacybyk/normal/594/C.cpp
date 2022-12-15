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

bool usuniete[100005];

int main() {
  make2(n,k);
  vector<PII> mX;
  vector<PII> mY;
  FOR(i,0,n) {
    make2(x1,y1);
    make2(x2,y2);
    mX.pb(mp(x1+x2,i));
    mY.pb(mp(y1+y2,i));
  }
  sort(all(mX));
  sort(all(mY));
    lint dis1 = max((mY.back().st-mY[0].st)*1LL,1LL);
    lint dis2 = max((mX.back().st-mX[0].st)*1LL,1LL);
  lint best = ((dis1+1)/2LL) * ((dis2+1)/2LL);
  FOR(i,0,n) usuniete[i] = false;

  FOR(a,0,11) FOR(b,0,11) FOR(c,0,11) FOR(d,0,11) {
    if(a+b+c+d>k) continue;
    VI dupa;
    int i = 0, j = 0;
    while(j<a) {
      if(!usuniete[mX[i].nd]) {
        usuniete[mX[i].nd] = 1;
        dupa.pb(mX[i].nd);
        j++;
      }
      i++;
    }
    i = 0, j =0;
    while(j<c) {  
      if(!usuniete[mY[i].nd]) {
        usuniete[mY[i].nd] = 1;
        dupa.pb(mY[i].nd);
        j++;
      }
      i++;
    }
    i = n-1, j = 0;
    while(j<b) {
      if(!usuniete[mX[i].nd]) {
        usuniete[mX[i].nd] = 1;
        dupa.pb(mX[i].nd);
        j++;
      }
      i--;
    }
    i = n-1, j = 0;
    while(j<d) {
      if(!usuniete[mY[i].nd]) {
        usuniete[mY[i].nd] = 1;
        dupa.pb(mY[i].nd);
        j++;
      }
      i--;
    }
    lint x1=0, x2 = mX.back().st;
    lint y1=0, y2 = mY.back().st;
    FOR(i,0,n) {
      if(!usuniete[mX[i].nd]) {
        x1 = mX[i].st;
        break;
      }
    }
    FOR(i,0,n) {
      if(!usuniete[mY[i].nd]) {
        y1 = mY[i].st;
        break;
      }
    }
    FORD(i,n-1,0){
      if(!usuniete[mX[i].nd]) {
        x2 = mX[i].st;
        break;
      }
    }
    FORD(i,n-1,0){
      if(!usuniete[mY[i].nd]) {
        y2 = mY[i].st;
        break;
      }
    }
    dis1 = max(y2-y1,1LL);
    dis2 = max(x2-x1,1LL);
    best = min(best, ((dis1+1LL)/2LL) * ((dis2+1LL)/2LL));
    FOR(i,0,dupa.size()) usuniete[dupa[i]] = false;
  }
  printf("%I64d\n",best);
}