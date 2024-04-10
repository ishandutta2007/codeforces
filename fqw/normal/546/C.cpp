// 17:06
// 17:09 - 17:27 - wa sample
//       - 17:31 - re
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
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

struct State {
    int p[10], m;
};

int n, v[10], k1, k2;

State process(State st) {
    int q[10], len=0;
    if(v[st.p[0]]>v[st.p[st.m]]) {
        rep(i, 1, st.m-1) q[len++]=st.p[i];
        q[len++]=st.p[st.m];
        q[len++]=st.p[0];
        rep(i, st.m+1, n-1) q[len++]=st.p[i];
        st.m++;
    } else {
        rep(i, 1, st.m-1) q[len++]=st.p[i];
        rep(i, st.m+1, n-1) q[len++]=st.p[i];
        q[len++]=st.p[0];
        q[len++]=st.p[st.m];
        st.m--;
    }
    memcpy(st.p, q, sizeof(q));
    return st;
}

int main() {
    scanf("%d", &n);
    scanf("%d", &k1); rep(i, 0, k1-1) scanf("%d", &v[i]);
    scanf("%d", &k2); rep(i, k1, n-1) scanf("%d", &v[i]);
    assert(k1+k2==n);

    State init_st;
    init_st.m=k1;
    repn(i, n) init_st.p[i]=i;

    State cur=init_st;
    bool stopped=false;
    repn(i, 999999) {
        cur=process(cur);
        if(cur.m==0 || cur.m==n) {
            printf("%d %d\n", i+1, cur.m==n?1:2);
            stopped=true;
            break;
        }
    }
    if(!stopped) printf("-1\n");

    return 0;
}