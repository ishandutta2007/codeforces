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

LL c[500010];
int n; LL k, tot;

int main() {
    scanf("%d", &n); cin>>k;
    tot=0;
    rep(i, 1, n) {
        int x; scanf("%d", &x);
        c[i]=x; tot+=x;
    }
    sort(c+1, c+n+1);

    LL diff=0;
    rep(i, 1, n) {
        LL cur=tot/n; if(n-i<tot%n) ++cur;
        diff+=max(0ll, cur-c[i]);
    }
    if(diff<=k) {
        printf("%d\n", tot%n==0?0:1);
        return 0;
    }

    int j=n; LL r=k; LL maxp=0;
    while(1) {
        LL dis=c[j]-c[j-1], num=n-j+1;
        if(dis*num<r) {
            r-=dis*num; --j;
        } else {
            maxp=c[j]-r/num;
            break;
        }
    }

    int i=1; r=k; LL minp=0;
    while(1) {
        LL dis=c[i+1]-c[i], num=i;
        if(dis*num<r) {
            r-=dis*num; ++i;
        } else {
            minp=c[i]+r/num;
            break;
        }
    }
    //cout<<maxp<<" "<<minp<<endl;
    cout<<(maxp-minp)<<endl;

    return 0;
}