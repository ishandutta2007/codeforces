// 6:57
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define _ (int)
#define all(a) a.begin(), a.end()
#define rep(i, a, b) for(int i=int(a); i<=int(b); ++i)
#define irep(i, a, b) for(int i=int(a); i>=int(b); --i)
#define repn(i, n) rep(i, 0, (n)-1)
#define irepn(i, n) irep(i, (n)-1, 0)
#define fillchar(a, x) memset(a, x, sizeof(a))
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef vector<LL> VL;
typedef vector<int> VI;
typedef vector<PII> VPI;
typedef vector<string> VS;
template<class T> bool setmax(T &_a, T _b) { if(_b>_a) { _a=_b; return true; } return false; }
template<class T> bool setmin(T &_a, T _b) { if(_b<_a) { _a=_b; return true; } return false; }
template<class T> T gcd(T _a, T _b) { return _b==0?_a:gcd(_b,_a%_b); }

int n, a[5010][3], s[5010][3], s2[5010][8];

int solve(PII c0, PII c1, PII c2) {
    auto cal_score=[](int base_score, int t) {
        if(t==0) return 0;
        if(t<0) t=-t;
        return base_score*(250-t)/250;
    };
    rep(i, 1, n) {
        s[i][0]=cal_score(c0.fi, a[i][0]);
        s[i][1]=cal_score(c1.fi, a[i][1]);
        s[i][2]=cal_score(c2.fi, a[i][2]);
        repn(m, 8) {
            s2[i][m]=0;
            repn(p, 3) if((m&(1<<p))==0 || a[i][p]>0) s2[i][m]+=s[i][p];
        }
    }
    int my_score=s2[1][0]+(c0.se+c1.se+c2.se)*100;
    int threats=0;
    static int f[99][99][99]; fillchar(f, 0);
    rep(i, 2, n) {
        if(s2[i][0]<=my_score) continue;
        ++threats;
        if(s2[i][7]>my_score) continue;
        irep(u0, c0.se, 0) irep(u1, c1.se, 0) irep(u2, c2.se, 0) {
            rep(m, 1, 7) if(s2[i][m]<=my_score) {
                setmax(f[u0+!!(m&1)][u1+!!(m&2)][u2+!!(m&4)], f[u0][u1][u2]+1);
            }
        }
    }

    int max_f=0;
    rep(u0, 0, c0.se) rep(u1, 0, c1.se) rep(u2, 0, c2.se) {
        setmax(max_f, f[u0][u1][u2]);
    }
    return threats-max_f+1;
}

int main() {
    scanf("%d", &n);
    rep(i, 1, n) repn(p, 3) scanf("%d", &a[i][p]);

    int possible_hacks=0;
    rep(i, 1, n) repn(p, 3) if(a[i][p]<0) ++possible_hacks;
    if(possible_hacks>90) { printf("1\n"); return 0; }

    VPI schema[3];
    repn(p, 3) {
        int lo=0, hi=0;
        rep(i, 1, n) {
            if(a[i][p]>0) lo++, hi++;
            if(a[i][p]<0) hi++;
        }
        auto base_score=[](int k) {
            if(n<2*k && 2*k<=2*n) return 500;
            if(n<4*k && 4*k<=2*n) return 1000;
            if(n<8*k && 8*k<=2*n) return 1500;
            if(n<16*k && 16*k<=2*n) return 2000;
            if(n<32*k && 32*k<=2*n) return 2500;
            return 3000;
        };
        int la=-1;
        rep(k, lo, hi) {
            int bs=base_score(k);
            if(bs!=la) {
                la=bs;
                schema[p].pb(mp(bs, hi-k));
            }
        }
    }

    int ans=1<<30;
    for(const auto& c0: schema[0])
        for(const auto& c1: schema[1])
            for(const auto& c2: schema[2])
                setmin(ans, solve(c0, c1, c2));
    printf("%d\n", ans);

    return 0;
}