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

const int N=100010;
const int V=100010;

int a[N], cnt[V], n;

int main() {
    scanf("%d", &n);
    rep(i, 1, n) scanf("%d", &a[i]);

    fillchar(cnt, 0);
    int i=1, ans=0;
    rep(j, 1, n) {
        ++cnt[a[j]];
        auto dis=[&]() {
            int x1=a[j], x2=a[j];
            rep(x, max(a[j]-2,1), a[j]+2)
                if(cnt[x]>0) {
                    setmin(x1, x);
                    setmax(x2, x);
                }
            return x2-x1;
        };
        while(dis()>1) --cnt[a[i++]];
        setmax(ans, j-i+1);
    }
    printf("%d\n", ans);

    return 0;
}