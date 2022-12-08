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

const int N=200010;
const LL LIM=LL(2e9);

int a[N]; int n, k; 

bool check(int i) {
    LL r=0;
    rep(j, 1, i) {
        assert(r%2==0);
        r=r/2+a[j];
    }
    LL t=0;
    irep(j, n, i+1) {
        t=(t+a[j])*2;
        if(t>LIM || t<-LIM) return false;
    }
    LL delta=-(r+t);
    return a[i]+delta<=k && a[i]+delta>=-k && (i!=n || a[i]+delta!=0);
}

int main() {
    scanf("%d%d", &n,&k); ++n;
    rep(i, 1, n) scanf("%d", &a[i]);

    LL r=0;
    rep(i, 1, n) {
        r+=a[i];
        if(i==n || r%2!=0) {
            int ans=0;
            rep(j, max(1, i-33), i) {
                if(check(j)) ++ans;
            }
            printf("%d\n", ans);
            break;
        }
        r/=2;
    }


    return 0;
}