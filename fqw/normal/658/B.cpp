#include <cassert>
#include <algorithm>
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

const int N=150010;

int t[N];
int n, k, q;

int main() {
    cin>>n>>k>>q;
    rep(i, 1, n) cin>>t[i];

    VPI r;
    while(q--) {
        int type, i; cin>>type>>i;
        if(type==1) {
            r.pb(mp(t[i], i));
            if(sz(r)>k) {
                sort(all(r), greater<PII>());
                r.pop_back();
            }
        } else {
            bool yes=any_of(all(r), [i](const PII& p) { return p.se==i; });
            cout<<(yes?"YES":"NO")<<endl;
        }
    }

    return 0;
}