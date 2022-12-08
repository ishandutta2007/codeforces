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

int n, q, cur;
VI swaps;

int main() {
    scanf("%d%d", &n,&q);
    cur=0; swaps.clear();
    rep(i, 1, q) {
        int t; scanf("%d", &t);
        if(t==1) {
            int x; scanf("%d", &x);
            cur=(cur+x+n)%n;
        } else {
            int z=cur%2;
            if(swaps.empty()) swaps.pb(z);
            else {
                if(swaps.back()==z) swaps.pop_back();
                else swaps.pb(z);
            }
        }
    }
    static int r[1000010];
    int v0=swaps.empty()?0:swaps[0];
    rep(i, 1, n) {
        int j;
        if(v0^(i&1)) {
            j=i+sz(swaps);
        } else {
            j=i-sz(swaps);
        }
        j=((j-1)%n+n)%n+1;
        r[j]=i;
    }
    rep(i, n-cur+1, n) printf("%d ", r[i]);
    rep(i, 1, n-cur) printf("%d ", r[i]);
    printf("\n");
    return 0;
}