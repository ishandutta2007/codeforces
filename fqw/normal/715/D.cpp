#include <algorithm>
#include <set>
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

vector<pair<PII, PII>> ans;
set<pair<PII, PII>> to_erase;

void add_r(int x, int y) { ans.emplace_back(mp(x,y), mp(x,y+1)); }
void add_d(int x, int y) { ans.emplace_back(mp(x,y), mp(x+1,y)); }
void erase_r(int x, int y) { to_erase.emplace(mp(x,y), mp(x,y+1)); }
void erase_d(int x, int y) { to_erase.emplace(mp(x,y), mp(x+1,y)); }

void initial_framework(int v) {
    rep(i, 1, 2) add_d(4, i);
    rep(i, 2, 3) add_r(i, 3);
    add_d(1, 3);
    if(v==1) {
        add_d(1,1), add_d(2,2);
    }
    if(v==2) {
        add_d(1,1), add_d(3,2);
    }
    if(v==3) {
        add_d(1,1);
    }
    if(v==4) {
        add_d(2,1), add_d(3,2);
    }
    if(v==5) {
        add_r(3,1), add_d(3,2);
    }
}

void framework(int x, int y) {
    rep(i, y, y+1) add_d(x+2, i);
    rep(i, x-2, x+1) add_r(i, y+2);
    rep(i, x-3, x-2) add_r(i, y+3);
    rep(i, y+2, y+3) add_d(x-4, i);
    add_d(x-3, y+2);
}

void block(int x, int y, int v) {
    if(v==0) {
        add_d(x-1, y);
    }
    if(v==1) {
        add_d(x, y);
        //erase_r(x+1, y-1);
    }
    if(v==2) {
        add_d(x+1, y);
    }
    if(v==3) {
        add_d(x+1, y+1);
        //add_r(x, y), add_r(x+1, y);
        //erase_r(x, y+1), erase_r(x+1, y+1);
    }
    if(v==4) {
        add_d(x, y+1);
    }
    if(v==5) {
    }
}

int main() {
    LL t; cin>>t;
    VI ts; while(t>0) ts.pb(t%6), t/=6;

    int x=4, y=3;
    initial_framework(ts.back()), ts.pop_back();
    while(!ts.empty()) {
        framework(x, y), block(x-2, y+1, ts.back()), ts.pop_back();
        x+=2, y+=2;
    }
    auto tmp=ans; ans.clear();
    for(const auto& p: tmp) if(p.fi.fi>=1 && p.fi.se>=1 && p.se.fi<=x && p.se.se<=y) {
        if(to_erase.count(p)==0) ans.pb(p);
    }
    printf("%d %d\n", x, y);
    printf("%d\n", sz(ans));
    for(const auto& p: ans) printf("%d %d %d %d\n", p.fi.fi,p.fi.se,p.se.fi,p.se.se);

    return 0;
}