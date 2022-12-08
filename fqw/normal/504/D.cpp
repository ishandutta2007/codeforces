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
#include <bitset>
#include <map>
using namespace std;

#define all(a) a.begin(), a.end()
#define rep(i, a, b) for(int i=int(a); i<=int(b); ++i)
#define irep(i, a, b) for(int i=int(a); i>=int(b); --i)
#define rep2(i, n) rep(i, 0, (n)-1)
#define irep2(i, n) irep(i, (n)-1, 0)
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

struct Base {
    bitset<2000> a, id;
    int first;
    void make_first() {
        assert(a.any());
        first=0;
        while(a[first]==0) ++first;
    }
};
vector<Base> bases;

bitset<2000> translate(string s) {
    VI xs;
    reverse(all(s));
    for(char c: s) xs.pb(int(c-'0'));
    bitset<2000> ans;
    for(int i=0; i<2000; i+=20) {
        int r=0;
        irep2(j, xs.size()) {
            xs[j]+=r*10;
            r=xs[j]&((1<<20)-1);
            xs[j]>>=20;
        }
        for(int j=i; r>0; ++j, r>>=1)
            ans[j]=r&1;
        while(xs.size()>0 && xs.back()==0)
            xs.pop_back();
        if(xs.empty())
            break;
    }
    return ans;
}

void reduce(Base &y, const Base &x) {
    if(y.a.test(x.first)) {
        y.a^=x.a;
        y.id^=x.id;
    }
}

void go(bitset<2000> bits, int id) {
    Base cur;
    cur.a=bits;
    cur.id[id]=1;
    for(Base &b: bases)
        reduce(cur, b);
    if(cur.a.any()) {
        printf("0\n");

        cur.make_first();
        for(Base &b: bases)
            reduce(b, cur);
        bases.pb(cur);
    }
    else {
        cur.id[id]=0;
        VI ans; rep2(i, 2000) if(cur.id.test(i)) ans.pb(i);
        printf("%d", (int)ans.size());
        for(int x: ans) printf(" %d", x);
        printf("\n");
    }
}

int main() {

    int n;
    scanf("%d", &n);
    bases.clear();
    rep2(i, n) {
        char buf[999];
        scanf("%s", buf);
        bitset<2000> cur=translate(buf);
        go(cur, i);
    }
    return 0;
}