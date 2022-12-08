#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <set>
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

int a[N], n;

bool check(int i) {
    if(i<1 || i>=n) return true;
    if(i%2==0) return a[i]>a[i+1];
        else return a[i]<a[i+1];
}

int main() {
    scanf("%d", &n);
    rep(i, 1, n) scanf("%d", &a[i]);
    VI bads;
    rep(i, 1, n-1) if(!check(i)) bads.pb(i);
    if(sz(bads)>4) {
        printf("0\n");
        return 0;
    }
    assert(sz(bads)>0);

    set<PII> ans;
    for(const int i0: bads) repn(i1, 2) {
        const int i=i0+i1;
        rep(j, 1, n) if(j!=i) {
            swap(a[i], a[j]);
            bool ok=true;
            for(int k: bads) if(!check(k)) ok=false;
            if(!check(i-1) || !check(i) || !check(j-1) || !check(j)) ok=false;
            swap(a[i], a[j]);
            if(ok) ans.insert(mp(min(i, j), max(i, j)));
        }
    }
    printf("%d\n", (int)ans.size());

    return 0;
}