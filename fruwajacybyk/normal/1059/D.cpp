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
#define jeb() fflush(stdout);

using namespace std;

int n;
vector<PII> v;
double ansR;

bool ok(double R) {
    double mini = 4e7, maxi = -4e7;
    FOR(i,0,n) {
        if (2.*R <= (double) v[i].nd) return false;
        double x = v[i].st, y = v[i].nd;
        double move = sqrt(y*(2*R-y));
        mini = min(mini, x + move);
        maxi = max(maxi, x - move);
        if (maxi > mini) return false;
    }
    ansR = R;
    return true;
}

int main() {
    read(n);
    int sgn = 1;
    FOR(i,0,n) {
        make2(a, b);
        if (i == 0 && b<0) {
            sgn = -1;
        }
        v.pb({a, sgn * b});
    }
    double left = 0., right = 1e14;
    FOR(i,0,n) {
        if (v[i].nd < 0) {
            printf("-1\n");
            return 0;
        }
    }
    double mid;
    FOR(i,0,100) {
        mid = (left + right) * 0.5;
        if (ok(mid)) {
            right = mid; 
        } else {
            left = mid;
        }
    }
    printf("%.17lf\n", ansR);
}