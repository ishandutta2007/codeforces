#include <bits/stdc++.h>


#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
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

lint dp[123456][5];
char s[123456];

int main() {
    make(n);
    scanf("%s", s);
    makev(v, n);
    dp[0][0] = 0;
    dp[0][1] = dp[0][2] = dp[0][3] = 0;
    FOR(i,1,n+1) {
        FOR(j,0,4) dp[i][j] = dp[i-1][j];
        if (s[i-1] == 'h') {
            dp[i][0] = dp[i-1][0] + v[i-1];
        } 
        if (s[i-1] == 'a') {
            dp[i][1] = dp[i-1][1] + v[i-1];
        }
        if (s[i-1] == 'r') {
            dp[i][2] = dp[i-1][2] + v[i-1];
        }
        if (s[i-1] == 'd') {
            dp[i][3] = dp[i-1][3] + v[i-1];
        }
        FOR(j,1,4) dp[i][j] = min(dp[i][j], dp[i][j-1]);
    }
    printf("%lld\n", dp[n][3]);
}