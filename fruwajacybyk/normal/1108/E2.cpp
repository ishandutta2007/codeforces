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

#define debug(x) {cout <<#x <<" = " <<x <<endl; }
#define debug2(x,y) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y <<endl; } 
#define debug3(x,y,z) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y << ", " << #z << " = " << z <<endl; } 
#define debugv(x) {{cout <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<endl; }}
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
#define jeb() fflush(stdout);

using namespace std;
const int max_n = 1e6 + 5;

int val[100005];

int main() {
  make2(n, m); 
  makev(v, n);
  vector<PII> ints;
  set<int> bnds;
  bnds.insert(0); bnds.insert(n);
  FOR(i,0,m) {
      make2(a, b);
      a--; b--;
      ints.pb({a,b});
      bnds.insert(a); bnds.insert(b+1);
  }
  VI bnd;
  FORE(i,bnds) bnd.pb(*i);
  VI imp;
  FOR(i,0,bnd.size()-1) {
    int a = bnd[i]; 
    int b = bnd[i+1];
    int mini = a, maxi = a;
    FOR(j,a,b) {
        if (v[j] < v[mini]) {
            mini = j;
        }
        if (v[j] > v[maxi]) {
            maxi = j;
        }
    }
    imp.pb(mini);
    if (maxi != mini) imp.pb(maxi);
  }
  int best = 0;
  VI dla;
  FOR(i,0,imp.size()) {
        int kto = imp[i];       
        FOR(j,0,imp.size()) val[imp[j]] = v[imp[j]];
        VI mdla;
        int loc = 0;
        FOR(u,0,ints.size()) {
            int a= ints[u].st;
            int b = ints[u].nd;
            if (kto >= a && kto <= b) continue;
            mdla.pb(u+1);
            FOR(j,0,imp.size()) {
                if (imp[j] >= a && imp[j] <= b) {
                    val[imp[j]]--;
                }
            }
        }
        FOR(j,0,imp.size()) loc = max(loc, val[kto] - val[imp[j]]);
        if (loc > best) {
            best = loc;
            dla = mdla;
        }
  }
    printf("%d\n", best);
    printf("%d\n", (int) dla.size());
    FORE(i, dla) {
        printf("%d ", *i);
    }
    printf("\n");

}