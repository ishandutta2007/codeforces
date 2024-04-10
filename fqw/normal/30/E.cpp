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
    VI ans(sz(s));
    int p=-1, r=-1;
    repn(i, sz(s)) {
        int cur=1;
        if(r>i) {
            cur=min(ans[p*2-i], r-i);
        }
        while(i-cur>=0 && i+cur<sz(s) && s[i-cur]==s[i+cur]) {
            ++cur;
        }
        ans[i]=cur;
        if(setmax(r, i+cur)) {
            p=i;
        }
    }
    return ans;
}

VI kmp(const string& s) {
    string t=s; reverse(all(t));

    VI fail(sz(t)+1);
    int j=fail[0]=-1;
    repn(i, sz(t)) {
        while(j>=0 && t[j]!=t[i]) j=fail[j];
        fail[i+1]=++j;
    }

    VI ans(sz(s));
    j=0;
    repn(i, sz(s)) {
        while(j>=0 && t[j]!=s[i]) j=fail[j];
        ans[i]=++j;
    }
    return ans;
}

int main() {
    string s; cin>>s;
    const int n=sz(s);

    VI palin=manacher(s);
    VI matches=kmp(s);

    VPI mx(n+1);
    repn(i, n) {
        mx[i+1]=max(mx[i], mp(matches[i], i));
    }
    pair<int, VPI> ans;
    repn(p, n) {
        const int w=palin[p];
        int len=mx[p-w+1].fi, i=mx[p-w+1].se-len+1;
        setmin(len, n-(p+w));
        if(len>0) {
            setmax(ans, mp(w*2-1+len*2, VPI{{i,i+len}, {p-w+1,p+w}, {n-len,n}}));
        } else {
            setmax(ans, mp(w*2-1, VPI{{p-w+1,p+w}}));
        }
    }
    cout<<sz(ans.se)<<endl;
    for(const auto p: ans.se) {
        cout<<p.fi+1<<" "<<p.se-p.fi<<endl;
    }

    return 0;
}