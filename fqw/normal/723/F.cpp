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

VPI solve() {
    int n, m; scanf("%d%d", &n,&m);
    VPI es(m);
    for(auto& e: es) {
        scanf("%d%d", &e.fi, &e.se);
        --e.fi, --e.se;
    }
    int s, t, ds, dt; scanf("%d%d%d%d", &s,&t,&ds,&dt);
    --s, --t;
    VPI ans;

    VI f(n, -1);
    const function<int(int)> get=[&](int x) { return f[x]<0 ? x : f[x]=get(f[x]); };
    for(const auto& e: es) {
        if(e.fi!=s && e.se!=s && e.fi!=t && e.se!=t && get(e.fi)!=get(e.se)) {
            ans.pb(e);
            f[get(e.fi)]=e.se;
        }
    }
    int num=0;
    VI belong(n);
    repn(i, n) if(i!=s && i!=t && f[i]<0) belong[i]=num++;
    repn(i, n) if(i!=s && i!=t && f[i]>=0) belong[i]=belong[get(i)];


    VI e2s(num, -1), e2t(num, -1);
    bool has_bridge=false;
    for(const auto& e: es) {
        if(e==mp(s,t) || e==mp(t,s)) {
            has_bridge=true;
            continue;
        }
        if(e.fi==s || e.se==s) {
            int x=(e.fi+e.se-s);
            e2s[belong[x]]=x;
        }
        if(e.fi==t || e.se==t) {
            int x=(e.fi+e.se-t);
            e2t[belong[x]]=x;
        }
    }
    VI sonly, tonly, both;
    repn(i, num) {
        if(e2s[i]<0 && e2t[i]<0) return VPI();
        if(e2s[i]>=0 && e2t[i]>=0) {
            both.pb(i);
        } else  {
            if(e2s[i]>=0) {
                sonly.pb(i);
            } else {
                tonly.pb(i);
            }
        }
    }
    if(sz(both)>0) {
        int i=both.back(); both.pop_back();
        ans.pb(mp(e2s[i], s));
        ans.pb(mp(e2t[i], t));
        --ds, --dt;
    } else if(has_bridge) {
        ans.pb(mp(s, t));
        --ds, --dt;
    } else {
        return VPI();
    }
    for(int i: sonly) {
        if(ds==0) return VPI();
        --ds;
        ans.pb(mp(e2s[i], s));
    }
    for(int i: tonly) {
        if(dt==0) return VPI();
        --dt;
        ans.pb(mp(e2t[i], t));
    }
    for(int i: both) {
        if(ds>0) {
            --ds, ans.pb(mp(e2s[i], s));
        } else if(dt>0) {
            --dt, ans.pb(mp(e2t[i], t));
        } else {
            return VPI();
        }
    }
    return ans;
}

int main() {
    VPI r=solve();
    if(r.empty()) {
        printf("No\n");
    } else {
        printf("Yes\n");
        for(const auto& e: r) printf("%d %d\n", e.fi+1,e.se+1);
    }
    return 0;
}