#include <iostream>
#include <cstdio>

#include <vector>
#include <algorithm>

#include <cassert>

using namespace std;

typedef long long ll;
#define tll(x) static_cast<ll>(x)

typedef pair<int, ll> pil;
typedef vector<pil> vp;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

int N;
ll K;

const int MAXN = 1e6 + 100;

vp adj[MAXN];

ll v[MAXN];

void dfsinit(const int& n = 0) {
    //cerr << v[n] << "\n";
    for(int i = 0;i < adj[n].size();i++) {
        v[adj[n][i].ff] ^= v[n] xor adj[n][i].ss;
        dfsinit(adj[n][i].ff);
    }
}

ll P;
struct NOD {
public:
    ll prefix;
    int len;
    int l, m, r;
    
    int upd(const int& dl = 0) {
        len += dl;
        
        int a = l-1, b = r;
        while(b > a + 1) {
            int c = a + ((b-a)>>1);
            if((v[c]>>len)&1) b = c;
            else a = c;
        }
        return m = b;
    }
    int c0() {
        return m - l;
    }
    int c1() {
        return r - m;
    }
    bool operator == (const NOD& o) const {return len == o.len and l == o.l and r == o.r;}
    bool operator != (const NOD& o) const {return !(*this==o);}
};
ll C2(const ll& v) {
    return ((v*(v+1))>>1);
}
typedef pair<NOD, NOD> pnn;
pnn keep[2][MAXN];
int ks[2];

int main() {
    scanf("%d%lld", &N, &K);
    
    for(int i = 1, x;i < N;i++) {
        ll w;
        scanf("%d%lld", &x, &w);
        adj[--x].pb({i, w});
    }
    dfsinit();
    
    P = 0;
    
    sort(v, v + N);
    
    bool cur = 0;
    keep[cur][(ks[cur] = 0)++] = {{0, 62, 0, -1, N}, {0, 62, 0, -1, N}};
    
    for(int i = 61;i >= 0;i--) {
        ks[cur = !cur] = 0;
        
        ll ct0 = 0;
        for(int j = 0;j < ks[!cur];j++) {
            keep[!cur][j].ff.upd(-1);
            keep[!cur][j].ss.upd(-1);
            
            assert(i == keep[!cur][j].ff.len and i == keep[!cur][j].ss.len);
            
            //if(keep[!cur][j].ff != keep[!cur][j].ss) ct0 += C2(tll(keep[!cur][j].ff.c0())) + C2(tll(keep[!cur][j].ff.c1()));
            ct0 += tll(keep[!cur][j].ff.c0())*tll(keep[!cur][j].ss.c0()) + tll(keep[!cur][j].ff.c1())*tll(keep[!cur][j].ss.c1());
        }
        ks[cur] = 0;
        
        //cerr << i << " " << ct0 << "\n";
        
        if(ct0 < K) {
            K -= ct0;
            P += (1LL << i);
            
            for(int j = 0;j < ks[!cur];j++) {
                if(keep[!cur][j].ff.c0() > 0 and keep[!cur][j].ss.c1() > 0) {
                    keep[cur][ks[cur]] = mp(keep[!cur][j].ff, keep[!cur][j].ss);
                    keep[cur][ks[cur]].ff.r = keep[cur][ks[cur]].ff.m;
                    keep[cur][ks[cur]].ss.l = keep[cur][ks[cur]].ss.m;
                    
                    ks[cur]++;
                }
                if(keep[!cur][j].ff.c1() > 0 and keep[!cur][j].ss.c0() > 0) {
                    keep[cur][ks[cur]] = mp(keep[!cur][j].ff, keep[!cur][j].ss);
                    keep[cur][ks[cur]].ff.l = keep[cur][ks[cur]].ff.m;
                    keep[cur][ks[cur]].ss.r = keep[cur][ks[cur]].ss.m;
                    
                    ks[cur]++;
                }
            }
            
        } else {
            for(int j = 0;j < ks[!cur];j++) {
                if(keep[!cur][j].ff.c0() > 0 and keep[!cur][j].ss.c0() > 0) {
                    keep[cur][ks[cur]] = mp(keep[!cur][j].ff, keep[!cur][j].ss);
                    keep[cur][ks[cur]].ff.r = keep[cur][ks[cur]].ff.m;
                    keep[cur][ks[cur]].ss.r = keep[cur][ks[cur]].ss.m;
                    
                    ks[cur]++;
                }
                if(keep[!cur][j].ff.c1() > 0 and keep[!cur][j].ss.c1() > 0) {
                    keep[cur][ks[cur]] = mp(keep[!cur][j].ff, keep[!cur][j].ss);
                    keep[cur][ks[cur]].ff.l = keep[cur][ks[cur]].ff.m;
                    keep[cur][ks[cur]].ss.l = keep[cur][ks[cur]].ss.m;
                    
                    ks[cur]++;
                }
            }
        }
    }
    
    printf("%lld\n", P);
    
    return 0;
}