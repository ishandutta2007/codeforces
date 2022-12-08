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

bool check(VI a) {
    const int n=sz(a);
    int sa=0, sb=0, b=n-1;
    repn(i, n) {
        sa+=a[i];
        sb+=b;
        b-=2;
        if(sa>sb) return false;
    }
    return true;
}

void process(VI a) {
    const int n=sz(a);
    vector<string> ans(n, string(n, 'X'));
    VPI b;
    repn(i, n) b.pb(mp(a[i], i));
    while(!b.empty()) {
        sort(all(b));
        PII cur=b.back(); b.pop_back();
        assert(cur.fi<=sz(b));
        repn(i, cur.fi) {
            ans[cur.se][b[i].se]='W';
            ans[b[i].se][cur.se]='L';
            ++b[i].fi;
        }
        replr(i, cur.fi, sz(b)) {
            ans[cur.se][b[i].se]='D';
            ans[b[i].se][cur.se]='D';
        }
    }
    cout<<"yes"<<endl;
    repn(i, n) cout<<ans[i]<<endl;
}

bool solve() {
    int n, m; cin>>n>>m;
    VI a(n);
    int rest=0;
    repn(i, m) {
        cin>>a[i]; a[i]-=n-1;
        rest-=a[i];
    }
    if(m<n) {
        int v=rest/(n-m), c=rest-v*(n-m);
        if(c<0) --v, c+=n-m;
        replr(i, m, n) {
            a[i]=v;
            if(i<m+c) ++a[i];
        }
        if(a[m-1]<a[m]) return false;
    } else {
        if(rest!=0) return false;
    }

    if(!check(a)) return false;
    process(a);
    return true;
}

int main() {
    if(!solve()) cout<<"no"<<endl;
    return 0;
}