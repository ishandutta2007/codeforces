#include <cassert>
#include <algorithm>
#include <iostream>
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
template<class T> bool setmax(T &_a, T _b) { if(_a<_b) { _a=_b; return true; } return false; }
template<class T> bool setmin(T &_a, T _b) { if(_b<_a) { _a=_b; return true; } return false; }
template<class T> T gcd(T _a, T _b) { return _b==0?_a:gcd(_b,_a%_b); }

const int MAXN=100010;

LL a[MAXN]; PII lst[MAXN];
int n; LL A, cf, cm, m;

void go(int i, int &j, LL &w) {
    while(1) {
        LL dw=m/j;
        if(j+1<i && w+dw>a[j+1]) {
            dw=a[j+1]-w;
            m-=dw*j, w+=dw;
            ++j;
            continue;
        }
        w+=dw, m-=dw*j;
        break;
    }
}

struct Sol {
    LL v; int i, j; LL w;
    Sol() { v=-1; }
    Sol(int _i, int _j, LL _w) : i(_i), j(_j), w(_w) {
        v=(n-i+1)*cf+w*cm;
    }
    bool operator <(const Sol &s) const {
        return v<s.v;
    }
};

void output(Sol ans) {
    static int len[MAXN];
    rep(i, 1, n) len[lst[i].se]=(int)a[i];
    rep(i, 1, ans.j) len[lst[i].se]=(int)ans.w;
    rep(i, ans.i, n) len[lst[i].se]=(int)A;
    cout<<ans.v<<endl;
    rep(i, 1, n) printf("%d ", len[i]); printf("\n");
}

int main() {
    scanf("%d", &n); cin>>A>>cf>>cm>>m;
    rep(i, 1, n) scanf("%d", &lst[i].fi), lst[i].se=i;
    sort(lst+1, lst+n+1);
    rep(i, 1, n) a[i]=lst[i].fi;

    LL max_need=0;
    rep(i, 1, n) max_need+=A-a[i];
    if(max_need<=m) {
        cout<<(n*cf+A*cm)<<endl; 
        rep(i, 1, n) printf("%d ", (int)A); printf("\n");
        return 0;
    }

    int i=n+1; a[i]=1LL<<50;
    while(i>1 && m>=A-a[i-1]) {
        --i; m-=A-a[i];
    }
    int j=1; LL w=a[1];

    Sol ans;
    while(1) {
        go(i, j, w);
        setmax(ans, Sol(i, j, w));
        if(i>n) break;
        m+=A-a[i];
        if(a[i]<w) m+=(w-a[i])*j, w=a[i];
        ++i;
    }

    output(ans);

    return 0;
}