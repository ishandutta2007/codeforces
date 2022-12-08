#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define _ (int)
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

int a[110][4], n, m;

int main() {
    cin>>n>>m;

    int cur=1; fillchar(a, 0);
    rep(i, 1, n) {
        if(cur>m) break;
        a[i][0]=cur++;
        if(cur>m) break;
        a[i][3]=cur++;
    }
    rep(i, 1, n) {
        if(cur>m) break;
        a[i][1]=cur++;
        if(cur>m) break;
        a[i][2]=cur++;
    }

    VI ans;
    rep(i, 1, n) {
        ans.pb(a[i][1]);
        ans.pb(a[i][0]);
        ans.pb(a[i][2]);
        ans.pb(a[i][3]);
    }
    for(int x: ans) if(x>0) cout<<x<<" "; cout<<endl;
    return 0;
}