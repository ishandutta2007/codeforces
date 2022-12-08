// 2:07
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
typedef unsigned long long ULL;
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

const string IMP="Impossible";

struct HashValue {
    static const LL M=LL(1e9)+7;

    LL x; ULL y;
    HashValue(int v=0) : x(v), y(v) {}
    HashValue(LL _x, ULL _y) : x(_x), y(_y) {}

    static HashValue P() {
        return {911, 1023};
    }
    bool operator==(const HashValue& b) const {
        return x==b.x && y==b.y;
    }
    HashValue operator*(const HashValue& b) const {
        return HashValue(x*b.x%M, y*b.y);
    }
    HashValue operator+(const HashValue& b) const {
        return HashValue((x+b.x)%M, y+b.y);
    }
    HashValue operator-(const HashValue& b) const {
        return HashValue((x-b.x+M)%M, y-b.y);
    }
};

string solve(string s, int d) {
    if(d==1) return IMP;
    {
        int i=sz(s)-1;
        while(i>=0 && s[i]=='z') {
            s[i]='a', --i;
        }
        if(i<0) return IMP;
        s[i]++;
    }
    vector<HashValue> pow(sz(s)+1);
    pow[0]=HashValue(1);
    repn(i, sz(s)) pow[i+1]=pow[i]*HashValue::P();

    string t(sz(s), '.');
    vector<HashValue> h1(sz(s)+1), h2(sz(s)+1);
    const auto is_palin=[&h1,&h2,&pow](int i, int j) {
        HashValue v1=(h1[j]-h1[i]*pow[j-i])*pow[i];
        HashValue v2=h2[j]-h2[i];
        return v1==v2;
    };
    const function<bool(int,bool)> dfs=[&](int i, bool equals_s) {
        if(i>=sz(s)) return true;
        for(char c=equals_s?s[i]:'a'; c<='z'; ++c) {
            t[i]=c;
            h1[i+1]=h1[i]*HashValue::P()+HashValue(t[i]);
            h2[i+1]=h2[i]+HashValue(t[i])*pow[i];
            if(i+1>=d && is_palin(i+1-d, i+1)) continue;
            if(i>=d && is_palin(i-d, i+1)) continue;
            if(dfs(i+1, equals_s && c==s[i])) return true;
        }
        return false;
    };
    if(dfs(0, true)) {
        return t;
    } else {
        return IMP;
    }
}

int main() {
    int d; cin>>d;
    string s; cin>>s;
    cout<<solve(s, d)<<endl;
    return 0;
}