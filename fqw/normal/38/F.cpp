#include <set>
#include <map>
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
template<class T> bool setmax(T &_a, T _b) { if(_a<_b) { _a=_b; return true; } return false; }
template<class T> bool setmin(T &_a, T _b) { if(_b<_a) { _a=_b; return true; } return false; }
template<class T> T gcd(T _a, T _b) { return _b==0?_a:gcd(_b,_a%_b); }

int score(string s, int num) {
    int sumv=0, maxv=0;
    for(char c: s) {
        int cur=int(c-'a'+1);
        sumv+=cur;
        setmax(maxv, cur);
    }
    return sumv*maxv+num;
}

int main() {
    int n; cin>>n;
    VS ws(n);
    for(string& w: ws) cin>>w;

    map<string, int> substrings={{"", 0}};
    for(const auto& w: ws) {
        set<string> tmp;
        repn(i, sz(w)) replr(j, i, sz(w)) {
            tmp.insert(w.substr(i, j-i+1));
        }
        for(const auto& s: tmp) {
            substrings[s]++;
        }
    }
    VS ss;
    for(const auto& kv: substrings) {
        ss.pb(kv.fi);
    }
    sort(all(ss), [](const string& a, const string& b) { return sz(a)<sz(b); });

    vector<VI> es(sz(ss));
    VI scores(sz(ss));
    repn(i, sz(ss)) {
        scores[i]=score(ss[i], substrings[ss[i]]);
        replr(j, i+1, sz(ss)) {
            if(sz(ss[j])>sz(ss[i])+1) {
                break;
            }
            if(sz(ss[j])==sz(ss[i])+1) {
                if(ss[j].substr(0, sz(ss[i]))==ss[i] || ss[j].substr(1, sz(ss[i]))==ss[i]) {
                    es[i].pb(j);
                }
            }
        }
    }
    struct State {
        bool win=false;
        int sx=0, sy=0;
        bool operator<(const State& o) const {
            if(win!=o.win) return !win;
            if(sx!=o.sx) return sx<o.sx;
            if(sy!=o.sy) return sy>o.sy;
            return false;
        }
    };
    vector<State> states(sz(ss));
    irepn(i, sz(ss)) {
        for(int j: es[i]) {
            State tmp=states[j];
            tmp.win=!tmp.win, swap(tmp.sx, tmp.sy);
            tmp.sx+=scores[j];
            setmax(states[i], tmp);
        }
    }
    printf("%s\n%d %d\n", states[0].win?"First":"Second", states[0].sx, states[0].sy);
    return 0;
}