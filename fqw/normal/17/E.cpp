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

const int MOD=51123987;

VI manacher(string s) {
    VI r(sz(s));
    int k=-1, p=-1;
    repn(i, sz(s)) {
        int cur=(p>=i ? min(r[k*2-i],p-i) : 0);
        while(i-cur-1>=0 && i+cur+1<sz(s) && s[i-cur-1]==s[i+cur+1]) {
            ++cur;
        }
        if(setmax(p, i+cur)) {
            k=i;
        }
        r[i]=cur;
    }
    //cout<<s<<" "<<r<<endl;
    return r;
}

int main() {
    int n; string s;
    cin>>n>>s;

    string t;
    for(char c: s) { t+=c; t+='*'; }
    VI lens=manacher(t);
    vector<pair<PII, int>> palindromes;
    repn(i, n) {
        palindromes.pb(mp(mp(i, i), lens[i*2]/2));
    }
    repn(i, n-1) {
        if(s[i]==s[i+1]) {
            palindromes.pb(mp(mp(i, i+1), (lens[i*2+1]-1)/2));
        }
    }
    //cout<<palindromes<<endl;

    LL tot=0;
    for(const auto& kv: palindromes) {
        (tot+=kv.se+1)%=MOD;
    }
    //cout<<tot<<endl;

    tot=tot*(tot-1)/2%MOD;
    VL a(n+1);
    for(const auto& kv: palindromes) {
        int r1=kv.fi.se, r2=r1+kv.se;
        //cout<<r1<<" "<<r2<<endl;
        a[r1]++, a[r2+1]--;
    }
    repn(i, n) a[i+1]=(a[i+1]+a[i])%MOD;
    repn(i, n) a[i+1]=(a[i+1]+a[i])%MOD;
    repn(i, n) a[i+1]=(a[i+1]+a[i])%MOD;
    for(const auto& kv: palindromes) {
        int l2=kv.fi.fi-1, l1=l2-kv.se;
        if(l2>=0) tot=(tot-a[l2])%MOD;
        if(l1>0) tot=(tot+a[l1-1])%MOD;
    }
    tot=(tot%MOD+MOD)%MOD;
    cout<<tot<<endl;
    return 0;
}