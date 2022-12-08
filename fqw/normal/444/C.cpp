#include <functional>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>
using namespace std;

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
#ifdef DEBUG
    #define _debug(args...) { fprintf(stderr, args); fflush(stderr); }
#else
    #define _debug(args...) {}
#endif
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

const int BSize=400;

LL absv(LL x) { return x>0?x:-x; }

struct Block {
    bool buf;
    LL bv, bs;
    LL x[BSize], s[BSize], ss;

    void release() {
        if(!buf) return;
        repn(i, BSize) {
            x[i]=bv, s[i]+=bs;
        }
        buf=false;
    }

    void modify(int l, int r, LL val) {
        setmax(l, 0);
        setmin(r, BSize);
        if(l>=r) return;
        if(l==0 && r==BSize) {
            if(!buf) {
                repn(i, BSize) {
                    s[i]+=absv(x[i]-val);
                    ss+=absv(x[i]-val);
                    x[i]=val;
                }
                buf=true;
                bv=val; bs=0;
            }
            else {
                bs+=absv(bv-val);
                ss+=absv(bv-val)*BSize;
                bv=val;
            }
            return;
        }
        release();
        rep(i, l, r-1) {
            s[i]+=absv(x[i]-val);
            ss+=absv(x[i]-val);
            x[i]=val;
        }
    }

    LL query(int l, int r) {
        setmax(l, 0);
        setmin(r, BSize);
        if(l>=r) return 0;
        if(l==0 && r==BSize) {
            return ss;
        }
        release();
        LL ans=0;
        rep(i, l, r-1) {
            ans+=s[i];
        }
        return ans;
    }
};

Block a[400];
int n, num;

void modify(int l, int r, LL val) {
    repn(i, num) {
        a[i].modify(l, r, val);
        l-=BSize, r-=BSize;
    }
}

LL query(int l, int r) {
    LL ans=0;
    repn(i, num) {
        ans+=a[i].query(l, r);
        l-=BSize, r-=BSize;
    }
    return ans;
}

int main() {
    int q;
    scanf("%d%d", &n,&q);
    num=(n-1)/BSize+1;

    fillchar(a, 0);
    repn(i, num) {
        repn(j, BSize) a[i].x[j]=i*BSize+j+1;
    }

    while(q--) {
        int type; scanf("%d", &type);
        int l, r; scanf("%d%d", &l,&r);
        --l;
        if(type==1) {
            int x; scanf("%d", &x);
            modify(l, r, x);
        }
        else {
            LL ans=query(l, r);
            cout<<ans<<endl;
        }
    }

    return 0;
}