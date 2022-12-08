// 8:01 - 8:27
//      - 8:38 - pass sample - wa
//      - 8:42 - wa
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <limits>
#include <memory>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) static_cast<int>((a).size())
#define fillchar(a, x) memset(a, x, sizeof(a))
#define rep(i, a, b) for(int i=int(a); i<=int(b); ++i)
#define irep(i, a, b) for(int i=int(a); i>=int(b); --i)
#define replr(i, a, b) rep(i, a, (b)-1)
#define reprl(i, a, b) irep(i, (b)-1, a)
#define repn(i, n) rep(i, 0, (n)-1)
#define irepn(i, n) irep(i, (n)-1, 0)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef vector<LL> VL;
typedef vector<int> VI;
typedef vector<PII> VPI;
typedef vector<string> VS;
template<class T, class S> ostream& operator<<(ostream& os, const pair<T, S>& v) { return os<<"("<<v.first<<", "<<v.second<<")"; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& v) { os<<"["; repn(i, sz(v)) { if(i) os<<", "; os<<v[i]; } return os<<"]"; }
template<class T> bool setmax(T &_a, T _b) { if(_b>_a) { _a=_b; return true; } return false; }
template<class T> bool setmin(T &_a, T _b) { if(_b<_a) { _a=_b; return true; } return false; }
template<class T> T gcd(T _a, T _b) { return _b==0?_a:gcd(_b,_a%_b); }

const LL MOD=LL(1e9)+7;

struct Hash {
    static constexpr LL M=LL(1e9)+7;
    LL v1; ULL v2;
    Hash(int v=0) : v1(v), v2(v) {}
    Hash(LL _v1, ULL _v2) : v1(_v1), v2(_v2) {}
    bool operator==(const Hash& b) const { return v1==b.v1 && v2==b.v2; }
    bool operator!=(const Hash& b) const { return !(*this==b); }
    Hash operator+(const Hash& b) const { return Hash((v1+b.v1)%M, v2+b.v2); }
    Hash operator-(const Hash& b) const { return Hash((v1-b.v1+M)%M, v2-b.v2); }
    Hash operator*(const Hash& b) const { return Hash((v1*b.v1)%M, v2*b.v2); }
    static Hash P() { return Hash(1023, 911); }
};

vector<Hash> hash_prefices(string s) {
    vector<Hash> h(sz(s)+1);
    repn(i, sz(s)) {
        h[i+1]=h[i]*Hash::P()+Hash(s[i]);
    }
    return h;
}

vector<Hash> hash_suffices(string s) {
    vector<Hash> h(sz(s)+1);
    Hash p(1);
    repn(i, sz(s)) {
        h[i+1]=h[i]+Hash(s[sz(s)-i-1])*p;
        p=p*Hash::P();
    }
    return h;
}

vector<int> lengths;
vector<Hash> suffices_odd, suffices_even, prefices;

void init() {
    string a="a", b="b";
    bool a_is_odd=true;
    lengths.pb(1);
    while(sz(a)<100000) {
        string c=b+a;
        lengths.pb(sz(c));
        a=b, b=c;
        a_is_odd=false;
    }

    prefices=hash_prefices(b);
    if(a_is_odd) {
        suffices_odd=hash_suffices(a);
        suffices_even=hash_suffices(b);
    } else {
        suffices_odd=hash_suffices(b);
        suffices_even=hash_suffices(a);
    }
}

int first_contains_suffix(Hash h, int len) {
    bool is_odd;
    if(suffices_odd[len]==h) {
        is_odd=true;
    } else if(suffices_even[len]==h) {
        is_odd=false;
    } else {
        return -1;
    }
    int i=int(lower_bound(all(lengths), len)-lengths.begin())+2;
    if(is_odd!=(i%2==1)) {
        ++i;
    }
    return i;
}

int first_contains_prefix(Hash h, int len) {
    if(prefices[len]!=h) {
        return -1;
    }
    return int(lower_bound(all(lengths), len)-lengths.begin())+2;
}

struct Mat {
    LL a[4][4];
    Mat(LL diag=0) {
        fillchar(a, 0);
        repn(i, 4) a[i][i]=diag;
    }
    Mat operator*(const Mat& b) const {
        Mat c;
        repn(i, 4) repn(j, 4) repn(k, 4) {
            (c.a[i][j]+=a[i][k]*b.a[k][j])%=MOD;
        }
        return c;
    }
    Mat pow(LL n) const {
        Mat b=*this, c(1);
        for(; n>0; n>>=1, b=b*b) {
            if(n&1) c=c*b;
        }
        return c;
    }
};

LL f(LL n) {
    if(n<=0) return 0;
    Mat a;
    a.a[0][0]=a.a[0][1]=a.a[1][0]=1;
    a=a.pow(n-1);
    return (a.a[0][0]-a.a[0][1]+MOD)%MOD;
}

LL g(LL n) {
    if(n<=0) return 0;
    Mat a;
    a.a[0][0]=a.a[0][1]=a.a[0][2]=a.a[1][0]=1;
    a.a[2][3]=a.a[3][2]=1;
    a=a.pow(n);
    return a.a[0][2];
}

LL solve(LL n, string s) {
    if(s=="a") return f(n);
    if(s=="b") return f(n+1);
    if(s=="ba") {
        if(n<3) return 0;
        return f(n);
    }
    const auto s_prefices=hash_prefices(s);
    const auto s_suffices=hash_suffices(s);
    LL ans=0;
    rep(len, 1, sz(s)-1) {
        int i=first_contains_suffix(s_prefices[len], len);
        int j=first_contains_prefix(s_suffices[sz(s)-len], sz(s)-len);
        //printf("%d %d %d\n",len,i,j);
        if(i<0 || j<0) continue;
        i=i+1, j=j+2;
        if(i%2!=j%2) ++j;
        (ans+=g(n-max(i, j)+1))%=MOD;
    }
    return ans;
}

int main() {
    //rep(i, 1, 10) cout<<i<<": "<<f(i)<<endl; return 0;
    init();
    LL n; scanf("%lld", &n);
    int num; scanf("%d", &num);
    while(num--) {
        static char buf[100010];
        scanf("%s", buf);
        LL ans=solve(n, string(buf));
        printf("%lld\n", ans);
    }
    return 0;
}