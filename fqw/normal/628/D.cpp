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

int main() {
    int m, d; cin>>m>>d;
    string a, b; cin>>a>>b;
    int n=(int)a.size();

    constexpr LL MOD=LL(1e9)+7;
    static LL f[2010][4][2010];
    fillchar(f, 0);
    f[0][3][0]=1;
    repn(i, n) repn(t, 4) repn(r, m) if(f[i][t][r]>0) {
        int lbound=0; if(t&1) lbound=int(a[i]-'0');
        int rbound=9; if(t&2) rbound=int(b[i]-'0');
        rep(x, lbound, rbound) if((i%2==0) != (x==d)) {
            int t2=t&((x==lbound?1:0)|(x==rbound?2:0));
            (f[i+1][t2][(r*10+x)%m]+=f[i][t][r])%=MOD;
        }
    }
    LL ans=0;
    repn(t, 4) (ans+=f[n][t][0])%=MOD;
    cout<<ans<<endl;
    return 0;
}