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
int mod = 1e9 + 7;

int gcd(int a, int b) {
    return a == 0 ? b : gcd(b%a, a);
}

int inv[1234567];

lint n;
vector<lint> divs;
vector<lint> rec[300005];

int pr[53][53][10005];



int main() {
    lint n; scanf("%lld", &n);
    make(k);
    lint nn = n;
    vector<pair<lint, int> > rozklad;
    for (lint i = 2; i * 1LL * i <= nn; i++) {
        if (nn%i == 0) {
            lint p = i;
            int ile = 0;
            while (nn%p == 0) {
                nn = nn/p;
                ile++;
            }
            rozklad.pb({p,ile});
        }
    }
    if (nn!=1) rozklad.pb({nn, 1});
    inv[1] = 1;
    FOR(i,2,100) {
        int q = mod/i; int r = mod % i;
        inv[i] = ((mod -q) * 1LL * inv[r])%mod;
    }
    FOR(j,0,k+1) pr[0][0][j] = 1;
    FOR(i,1,53) {
        pr[i][i][0] = 1;
        FOR(j,1,k+1) {
            FOR(i2,0,i+1) {
                FOR(i3,0,i2+1) {
                    pr[i][i3][j] = (pr[i][i3][j] + pr[i][i2][j-1]*1LL*inv[i2+1])%mod;
                }
            }
        }
    }
    int ans = 0;
    vector<lint> divs;
    for (lint i = 1; i*1LL*i <= n; i++) {
        if (n%i == 0) {
            divs.pb(i);
            if (i!=n/i) divs.pb(n/i);
        }
    }
    FOR(i,0,divs.size()) {
        lint d = divs[i];
        int m = rozklad.size();
        int pop = d % mod;
        FOR(j,0,m) {
            lint p = rozklad[j].st;
            int e = rozklad[j].nd;
            int xxx = 0;
            while (d%p == 0) {
                xxx++;
                d = d/p;
            }
            pop = (pop * 1LL * pr[e][xxx][k])%mod;
        }
        ans += pop;
        ans %= mod;
    }
    printf("%d\n", ans);
}