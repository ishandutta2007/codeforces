#include <set>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define sz(a) static_cast<int>(a.size())
#define all(a) a.begin(), a.end()
#define rep(i, a, b) for(int i=int(a); i<=int(b); ++i)
#define irep(i, a, b) for(int i=int(a); i>=int(b); --i)
#define repn(i, n) rep(i, 0, (n)-1)
#define irepn(i, n) irep(i, (n)-1, 0)
#define fillchar(a, x) memset(a, x, sizeof(a))
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
template<class T> bool setmax(T &_a, T _b) { if(_b>_a) { _a=_b; return true; } return false; }
template<class T> bool setmin(T &_a, T _b) { if(_b<_a) { _a=_b; return true; } return false; }
template<class T> T gcd(T _a, T _b) { return _b==0?_a:gcd(_b,_a%_b); }

int main() {
    int n, q; scanf("%d%d", &n,&q);
    static VI app[300030];
    set<int> ns;
    int cnt=0;
    while(q--) {
        int t, x; scanf("%d%d", &t,&x);
        if(t==1) {
            ++cnt;
            app[x].pb(cnt);
            ns.insert(cnt);
        } else if(t==2) {
            while(!app[x].empty()) {
                ns.erase(app[x].back());
                app[x].pop_back();
            }
        } else {
            while(!ns.empty() && *ns.begin()<=x) {
                ns.erase(ns.begin());
            }
        }
        printf("%d\n", sz(ns));
    }
    return 0;
}