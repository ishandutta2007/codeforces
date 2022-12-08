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

const LL MOD=LL(1e9)+7;
const int N=2000010;

char s[N]; int la[33];
LL f[N], sf[N];
int n, m, k;

int main() {
    scanf("%d%d%s", &n,&k,s+1);
    m=int(strlen(s+1));

    f[0]=sf[0]=1; fillchar(la, 0);
    rep(i, 1, m+n) {
        int ch=0;
        if(i<=m) ch=int(s[i]-'a');
        else {
            repn(c, k) if(la[c]<la[ch]) ch=c;
        }
        int j=la[ch]; la[ch]=i;
        f[i]=(sf[i-1]-(j==0?0:sf[j-1])+MOD)%MOD;
        sf[i]=(sf[i-1]+f[i])%MOD;
    }
    cout<<sf[m+n]<<endl;
    return 0;
}