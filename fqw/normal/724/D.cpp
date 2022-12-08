#include <set>
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

int main() {
    int m; string s;
    cin>>m>>s;
    const int n=sz(s);

    set<int> is;
    repn(i, n) is.insert(i);
    is.insert(-1);
    is.insert(n);

    vector<pair<char, int> > ps;
    repn(i, n) ps.emplace_back(s[i], i);
    sort(all(ps));
    string ans;
    irepn(k, n) {
        if(!ans.empty() && ps[k].fi!=ans[0]) {
            ans.pb(ps[k].fi);
            continue;
        }
        const int i=ps[k].se;
        is.erase(i);
        int i1=*(--is.upper_bound(i));
        int i2=*is.lower_bound(i);
        if(i2-i1>m) {
            ans.pb(ps[k].fi);
            is.insert(i);
        }
    }
    reverse(all(ans));
    cout<<ans<<endl;

    return 0;
}