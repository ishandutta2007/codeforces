#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <limits>
#include <memory>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) static_cast<int>((a).size())
#define fillchar(a, x) memset(a, x, sizeof(a))
#define rep(i, a, b) for(int i=int(a); i<=int(b); ++i)
#define irep(i, a, b) for(int i=int(a); i>=int(b); --i)
#define replr(i, a, b) rep(i, a, (b)-1)
#define reprl(i, a, b) irep(i, (b)-1, a)
#define repn(i, n) rep(i, 0, (n)-1)
#define irepn(i, n) irep(i, (n)-1, 0)
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
template<class T, class S> ostream& operator<<(ostream& os, const pair<T, S>& v) { return os<<"("<<v.first<<", "<<v.second<<")"; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& v) { os<<"["; repn(i, sz(v)) { if(i) os<<", "; os<<v[i]; } return os<<"]"; }
template<class T> bool setmax(T &_a, T _b) { if(_b>_a) { _a=_b; return true; } return false; }
template<class T> bool setmin(T &_a, T _b) { if(_b<_a) { _a=_b; return true; } return false; }
template<class T> T gcd(T _a, T _b) { return _b==0?_a:gcd(_b,_a%_b); }

const int N=400000;

LL tr[N*4], buf[N*4];
int n;

void release(int x) {
    if(buf[x]!=0) {
        tr[x*2+1]+=buf[x], buf[x*2+1]+=buf[x];
        tr[x*2+2]+=buf[x], buf[x*2+2]+=buf[x];
        buf[x]=0;
    }
}

void add(int x, int l, int r, int s, int t, LL v) {
    if(s<=l && r<=t) {
        buf[x]+=v, tr[x]+=v;
        return;
    }
    release(x);
    const int m=(l+r)/2;
    if(s<m) add(x*2+1, l, m, s, t, v);
    if(m<t) add(x*2+2, m, r, s, t, v);
    tr[x]=min(tr[x*2+1], tr[x*2+2]);
}

LL getmin(int x, int l, int r, int s, int t) {
    if(s<=l && r<=t) {
        return tr[x];
    }
    release(x);
    const int m=(l+r)/2;
    LL ans=1LL<<55;
    if(s<m) setmin(ans, getmin(x*2+1, l, m, s, t));
    if(m<t) setmin(ans, getmin(x*2+2, m, r, s, t));
    return ans;
}

int main() {
    scanf("%d", &n);
    fillchar(tr, 0); fillchar(buf, 0);
    repn(i, n) {
        int x; scanf("%d", &x);
        add(0, 0, n*2, i, i+1, x);
        add(0, 0, n*2, n+i, n+i+1, x);
    }
    int m; scanf("%d", &m);
    char str[512]; gets(str);
    while(m--) {
        const auto parse=[](const char* begin, const char* end) {
            int x=0; bool neg=false;
            if(*begin=='-') {
                neg=true; ++begin;
            }
            for(const char* c=begin; c!=end; ++c) {
                x=x*10+int(*c-'0');
            }
            if(neg) x=-x;
            return x;
        };
        gets(str); const int len=(int)strlen(str);
        char* sp1=find(str, str+len, ' ');
        char* sp2=find(sp1+1, str+len, ' ');
        int l=parse(str, sp1), r=parse(sp1+1, sp2);
        if(r<l) r+=n; ++r;
        if(sp2==str+len) {
            printf("%lld\n", getmin(0, 0, n*2, l, r));
        } else {
            int val=parse(sp2+1, str+len);
            rep(d, -1, 1) {
                int l0=max(0, l+d*n), r0=min(n*2, r+d*n);
                if(l0<r0) add(0, 0, n*2, l0, r0, val);
            }
        }

    }
    return 0;
}