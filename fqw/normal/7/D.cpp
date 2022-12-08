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

VI manacher(const string& s) {
    const int n=sz(s);
    VI r(n);
    int k=-1, p=-1;
    repn(i, n) {
        int len=0;
        if(p>=i) {
            len=min(r[k*2-i], p-i);
        }
        while(i-len-1>=0 && i+len+1<n && s[i-len-1]==s[i+len+1]) {
            ++len;
        }
        if(i+len>p) {
            p=i+len, k=i;
        }
        r[i]=len;
    }
    return r;
}

int main() {
    static char buf[5000010]; scanf("%s", buf);
    const string s(buf);
    string t;
    for(char c: s) {
        if(!t.empty()) t+='*';
        t+=c;
    }
    VI r=manacher(t);
    VI f(sz(s)+1);
    int ans=0;
    repn(i, sz(s)) {
        if(r[i]==i) {
            f[i+1]=f[(i+1)/2]+1;
            ans+=f[i+1];
        }
    }
    printf("%d\n", ans);

    return 0;
}