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

const int max_n = 5e5+5;

int n;
int dp[55][2005];
char col[55];
int ile[55];

int rob(int last, int left) {
    if (dp[last][left] != -1) return dp[last][left];
    if (left <= 0) return 0;
    int best = 1e9;
    FOR(i,0,n) {
        if (col[last] != col[i] && ile[i] > ile[last]) {
            best = min(best, rob(i, left - ile[i]) + max(i-last, last-i));
        }
    }
    dp[last][left] = min(best, (int) 1e9);
    return dp[last][left];
}

int main() {
    int k, s;
   read3(n, s, k); s--;  
    int best = 1e9;
    FOR(i,0,n) {
        make(a);
        ile[i] = a;
    }
    scanf("%s", col);
    FOR(i,0,n) FOR(j,0,k+1) dp[i][j] = -1;
    FOR(i,0,n) {
        best = min(best, rob(i, k - ile[i]) + max(i-s, s-i));
    }
    if (best == 1e9) {
        printf("-1\n");
    } else printf("%d\n", best);
}