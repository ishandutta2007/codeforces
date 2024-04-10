// 11:04
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

string solve(string a, string b) {
    VI fail(sz(b)+1);
    int j=fail[0]=-1;
    repn(i, sz(b)) {
        while(j>=0 && b[i]!=b[j]) j=fail[j];
        fail[i+1]=++j;
    }
    j=0;
    repn(i, sz(a)) {
        while(j>=0 && a[i]!=b[j]) j=fail[j];
        ++j;
        if(j==sz(b)) {
            return a;
        }
    }
    return a+b.substr(j);
}

int main() {
    string s[3]; cin>>s[0]>>s[1]>>s[2];
    VI p={0, 1, 2};
    int ans=1<<30;
    do {
        setmin(ans, sz(solve(solve(s[p[0]], s[p[1]]), s[p[2]])));
    } while(next_permutation(all(p)));
    cout<<ans<<endl;
    return 0;
}