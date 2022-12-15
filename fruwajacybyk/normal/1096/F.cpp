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
const int max_n = 5e5 + 5;

const int mod = 998244353;
int n;
VI v;

int powmod(int a, int b) {
    if (b == 0) return 1;
    if (a == 0) return 0;
    int sq = powmod(a, b/2);
    sq = (sq * 1LL * sq) % mod;
    if (b%2==0) return sq;
    return (sq * 1LL * a) % mod;
}

int bit[max_n];

void add(int x) {
    while (x <= n) {
        bit[x]++;
        x += (x & -x);
    }
}

int ask(int x) {
    int ans = 0;
    while (x!=0) {
        ans += bit[x];
        x -= (x & (-x));
    }
    return ans;
}

int jest[max_n];
int sa_mniejsze[max_n];

int main() {
    read(n);
    readv(v, n);
    int k = 0;

    FOR(i,0,n) if (v[i] == -1) k++;
    FOR(i,0,n) jest[v[i]] = 1;
    sa_mniejsze[1] = 0;
    FOR(i,2,n+1) sa_mniejsze[i] = sa_mniejsze[i-1] + jest[i-1];

    int ans = ((k * 1LL* (k-1))% mod * powmod(4,mod -2))%mod;
    FORD(i,n-1,0) {
        if (v[i] != -1) {
            ans = (ans + ask(v[i]-1)) % mod;
            add(v[i]);
        }
    }
    if (k!=0) {
        int pyt = 0;
        FORD(i,n-1,0) {
            if (v[i] == -1) pyt++;
            else {
                int zle = v[i] - 1 - sa_mniejsze[v[i]];
                ans += ((pyt * 1LL * zle)%mod * 1LL * powmod(k, mod -2))%mod;
                ans %= mod;
                ans += (((k-pyt) * 1LL * (k-zle))%mod * 1LL * powmod(k, mod -2))%mod;
                ans %= mod;
            }
        }
    }
    printf("%d\n", ans);
}