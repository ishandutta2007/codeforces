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

LL parse(string s) {
    LL cents=0;
    if(sz(s)>=3 && s[sz(s)-3]=='.') {
        cents=int(s[sz(s)-2]-'0')*10+int(s.back()-'0');
        s=s.substr(0, sz(s)-3);
    }
    LL r=0;
    for(char c: s) {
        if(c>='0' && c<='9') {
            r=r*10+int(c-'0');
        }
    }
    return r*100+cents;
}

string to_str(LL x) {
    ostringstream os;
    os<<x;
    return os.str();
}

string format(LL x) {
    string cents;
    if(x%100!=0) {
        cents=to_str(x%100);
        if(sz(cents)==1) cents="0"+cents;
        cents="."+cents;
    }
    x/=100;
    string tmp=to_str(x);
    string ans;
    repn(i, sz(tmp)) {
        if(i>0 && i%3==0) ans="."+ans;
        ans=tmp[sz(tmp)-i-1]+ans;
    }
    return ans+cents;
}

int main() {
    string s; cin>>s;
    string cur;
    s+='a';
    LL ans=0;
    for(char c: s) {
        if(c>='a' && c<='z') {
            if(!cur.empty()) ans+=parse(cur);
            cur="";
        } else {
            cur+=c;
        }
    }
    cout<<format(ans)<<endl;
    return 0;
}