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

const int N=400020;
const LL MOD=LL(1e9)+7;

int tr[N];
int l[N], r[N]; VI pos;
int n, k, m;

void add(int x, int v) {
    for(; x<=m; x+=x&-x) tr[x]+=v;
}

int get(int x) {
    int a=0;
    for(; x>=1; x-=x&-x) a+=tr[x];
    return a;
}

LL fac[N], inv_fac[N];
void pre() {
    auto pow=[](LL a, LL b, LL mod) {
        LL c=1;
        for(; b>0; b>>=1, a=a*a%mod)
            if(b&1) c=c*a%mod;
        return c;
    };
    fac[0]=1;
    rep(i, 1, N-1) fac[i]=fac[i-1]*i%MOD;
    inv_fac[N-1]=pow(fac[N-1], MOD-2, MOD);
    irep(i, N-1, 1) inv_fac[i-1]=inv_fac[i]*i%MOD;
}

int main() {
    pre();
    scanf("%d%d", &n, &k);
    pos.clear();
    rep(i, 1, n) {
        scanf("%d%d", &l[i], &r[i]); ++r[i];
        pos.pb(l[i]);
        pos.pb(r[i]);
    }
    sort(all(pos)); pos.erase(unique(all(pos)), pos.end());
    m=sz(pos)-1;
    fillchar(tr, 0);
    rep(i, 1, n) {
        l[i]=int(lower_bound(all(pos), l[i])-pos.begin()+1);
        r[i]=int(lower_bound(all(pos), r[i])-pos.begin());
        add(l[i], 1);
        add(r[i]+1, -1);
    }

    LL ans=0;
    rep(i, 1, m) {
        int c=get(i); if(c<k) continue;
        LL cur=fac[c]*inv_fac[k]%MOD*inv_fac[c-k]%MOD;
        (ans+=cur*(pos[i]-pos[i-1]))%=MOD;
    }
    cout<<ans<<endl;

    return 0;
}