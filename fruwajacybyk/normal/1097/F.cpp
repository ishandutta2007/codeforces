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
const int max_n = 1e5 + 5;


bitset<7001> bs[max_n];
bitset<7001> mobius[7005];

int isf[7005];

int main() {
    make(n);
    make(q);
    isf[1] = 1;
    FOR(i,1,7001) {
        int d = i;
        for (int j = 2; j*j <= i; j++) {
            if (i%j==0) {
                d = j;
                break;
            }
        }
        if (d == i) isf[i] = 1;
        else {
            if (i%(d*d) == 0) isf[i] = 0;
            else isf[i] = isf[i/d];
        }
    }
    FOR(i,1,7001) {
        for (int k = i; k < 7001; k+=i) {
            if (isf[k/i]) mobius[i].set(k);
        }
    }

    while (q--) {
        make(type);
        if (type == 1) {
            make2(x, v);
            bs[x].reset();
            for (int i = 1; i * i <= v;i++) if (v%i == 0) {
                bs[x].set(i);
                bs[x].set(v/i);
            }
        }
        if (type == 2) {
            make3(x, y, z);
            bs[x] = (bs[y] ^ bs[z]);
        }
        if (type == 3) {
            make3(x, y, z);
            bs[x] = (bs[y] & bs[z]);
        }
        if (type == 4) {
            make2(x, v);
            bitset<7001> loc = bs[x]&mobius[v];
            int a = loc.count();
            printf("%d", a%2);
        }
    }
    printf("\n");
}