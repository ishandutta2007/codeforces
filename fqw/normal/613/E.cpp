// 1:30
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

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
#ifdef DEBUG
    #define _debug(args...) { fprintf(stderr, args); fflush(stderr); }
#else
    #define _debug(args...) {}
#endif
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

const int N=2010;
const LL M=LL(1e9)+7;

char field[2][N], word[N];
int n, k;

int inside(int i) { return i>=1 && i<=n; }

class HashManager {
    static const LL MOD=(1LL<<30)-1, P=911;
    LL f[2][2][N], w[N], p[N];
public:
    void prepare() {
        p[0]=1; rep(i, 1, N-1) p[i]=p[i-1]*P%MOD;
        
        w[0]=0;
        rep(i, 1, k) w[i]=(w[i-1]*P+int(word[i]))%MOD;

        repn(r, 2) {
            f[0][r][0]=0;
            rep(i, 1, n) f[0][r][i]=(f[0][r][i-1]*P+int(field[r][i]))%MOD;
        }
        repn(r, 2) {
            f[1][r][n+1]=0;
            irep(i, n, 1) f[1][r][i]=(f[1][r][i+1]*P+int(field[r][i]))%MOD;
        }
    }

    LL hash_w(int i, int j) {
        assert(i<=j);
        LL h=w[j]-w[i-1]*p[j-i+1];
        return (h%MOD+MOD)%MOD;
    }

    LL hash_f(int r, int i, int j) {
        LL h;
        if(i<=j) {
            h=(f[0][r][j]-f[0][r][i-1]*p[j-i+1])%MOD;
        } else {
            h=(f[1][r][j]-f[1][r][i+1]*p[i-j+1])%MOD;
        }
        return (h%MOD+MOD)%MOD;
    }
} h;

bool match(int r, int i1, int i2, int j) {
    int len=abs(i1-i2)+1, j2=j+len-1;
    assert(j2<=k);
    return h.hash_w(j, j2)==h.hash_f(r, i1, i2);
}

LL mem[2][N][2][2][N];

LL cal(int r, int i, int space, int dir, int j) {
    if(j==k) return 1;
    LL& ans=mem[r][i][space][(dir+1)/2][j];
    if(ans>=0) return ans;
    ans=0;
    if(space==1 && field[r^1][i]==word[j+1])
        (ans+=cal(r^1, i, 0, dir, j+1)) %=M;
    if(inside(i+dir) && field[r][i+dir]==word[j+1])
        (ans+=cal(r, i+dir, 1, dir, j+1)) %=M;
    if((k-j+1)%2==0 && space==1) {
        int len=(k-j+1)/2, i2=i+dir*(len-1);
        if(len>=2 && inside(i2) && match(r, i, i2, j) && match(r^1, i2, i, j+len))
            (ans+=1) %=M;
    }
    return ans;
}

LL solve() {
    if(k==1) {
        int ans=0; repn(r, 2) rep(i, 1, n) if(field[r][i]==word[1]) ++ans;
        return ans;
    }

    h.prepare();
    LL ans=0;
    fillchar(mem, -1);
    repn(r, 2) rep(i, 1, n) if(field[r][i]==word[1]) {
        (ans+=cal(r, i, 1, 1, 1)) %=M;
        (ans+=cal(r, i, 1, -1, 1)) %=M;
        if(k==2 && word[2]==field[r^1][i]) --ans;
        for(int dir: {-1, 1}) {
            rep(len, 2, (k-1)/2) {
                int i2=i+dir*(len-1);
                if(!inside(i2)) break;
                if(match(r, i, i2, 1) && match(r^1, i2, i, 1+len))
                    (ans+=cal(r^1, i, 0, -dir, len*2)) %=M;
            }
        }
    }
    ans=(ans%M+M)%M;
    return ans;
}

int main() {
    scanf("%s%s%s", field[0]+1, field[1]+1, word+1);
    n=(int)strlen(field[0]+1);
    k=(int)strlen(word+1);
    LL ans=solve();
    cout<<ans<<endl;
    
    return 0;
}