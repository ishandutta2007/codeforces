#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define sz(a) static_cast<int>(a.size())
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

const int N=100010;

LL px[N], py[N], pz[N];
LL rx, ry, rz;
int n;

bool merge(LL* l, LL* r, LL l2, LL r2) {
    if(l2>*l) *l=l2;
    if(r2<*r) *r=r2;
    return *l<=*r;
}

LL up(LL x, int mod2) {
    LL r=((x&1?1:0)==mod2 ? x : x+1);
    //printf("up x=%lld r=%lld\n",x,r);
    return r;
}

LL dn(LL x, int mod2) {
    LL r=((x&1?1:0)==mod2 ? x : x-1);
    //printf("dn x=%lld r=%lld\n",x,r);
    return r;
}

bool p2(LL x) { return x%2==0; }

bool check(LL limit) {
    const LL INF=LL(8e18);
    LL t1=-INF, t2=INF;
    LL u1=-INF, u2=INF;
    LL v1=-INF, v2=INF;
    LL w1=-INF, w2=INF;
    rep(i, 1, n) {
        LL t=px[i]+py[i]+pz[i];
        LL u=-px[i]+py[i]+pz[i];
        LL v=px[i]-py[i]+pz[i];
        LL w=px[i]+py[i]-pz[i];
        if(!merge(&t1, &t2, t-limit, t+limit)) return false;
        if(!merge(&u1, &u2, u-limit, u+limit)) return false;
        if(!merge(&v1, &v2, v-limit, v+limit)) return false;
        if(!merge(&w1, &w2, w-limit, w+limit)) return false;
    }
    repn(mod2, 2) {
        LL cu1=up(u1, mod2), cu2=dn(u2, mod2); if(cu1>cu2) continue;
        LL cv1=up(v1, mod2), cv2=dn(v2, mod2); if(cv1>cv2) continue;
        LL cw1=up(w1, mod2), cw2=dn(w2, mod2); if(cw1>cw2) continue;
        LL ct1=up(t1, mod2), ct2=dn(t2, mod2);
        if(!merge(&ct1, &ct2, cu1+cv1+cw1, cu2+cv2+cw2)) continue;
        LL d=0;
        d=min(cu2-cu1, ct1-(cu1+cv1+cw1)); cu1+=d;
        d=min(cv2-cv1, ct1-(cu1+cv1+cw1)); cv1+=d;
        d=min(cw2-cw1, ct1-(cu1+cv1+cw1)); cw1+=d;
        rx=(cv1+cw1)/2;
        ry=(cu1+cw1)/2;
        rz=(cu1+cv1)/2;
        return true;
    }
    return false;
}

int main() {
    int cases; scanf("%d", &cases);
    while(cases--) {
        scanf("%d", &n);
        rep(i, 1, n) scanf("%lld%lld%lld", &px[i],&py[i],&pz[i]);
        if(n==1) {
            printf("%lld %lld %lld\n", px[1], py[1], pz[1]);
            continue;
        }
        if(n==2) {
            bool f=true;
            auto go=[](LL v1, LL v2, LL* v, bool* first) {
                *v=v1+v2;
                if(*v%2==0) *v/=2;
                else {
                    if(*first ^ (abs(v1)<abs(v2))) *v=*v/2;
                    else *v=*v/2+*v%2;
                    *first=!*first;
                }
            };
            go(px[1], px[2], &rx, &f);
            go(py[1], py[2], &ry, &f);
            go(pz[1], pz[2], &rz, &f);
            printf("%lld %lld %lld\n", rx,ry,rz);
            continue;
        }
        LL le=0, ri=LL(3e18);
        while(le<ri) {
            LL mid=(le+ri)/2;
            if(check(mid)) {
                ri=mid;
            } else {
                le=mid+1;
            }
        }
        check(le);
        printf("%lld %lld %lld\n", rx,ry,rz);
    }
    return 0;
}