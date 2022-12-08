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

const int N=1010;

int f[2][N][N][2];
char s[N], t[N];
int n, m, k;

int main() {
    scanf("%d%d%d", &n,&m,&k);
    scanf("%s%s", s+1, t+1);
    fillchar(f, 0xff);
    int ans=0;
    int o1=0, o2=1;
    f[o1][0][0][0]=0;
    repn(z, k+1) {
        fillchar(f[o2], 0xff);
        rep(i, 0, n) rep(j, 0, m) repn(cont, 2) {
            const int val=f[o1][i][j][cont];
            setmax(ans, val);
            if(val<0) continue;
            if(i<n && j<m && s[i+1]==t[j+1]) {
                if(cont) 
                    setmax(f[o1][i+1][j+1][1], val+1);
                else
                    setmax(f[o2][i+1][j+1][1], val+1);
            }
            if(i<n) {
                setmax(f[o1][i+1][j][0], val);
            }
            if(j<m) {
                setmax(f[o1][i][j+1][0], val);
            }
        }
        swap(o1, o2);
    }
    printf("%d\n", ans);
    return 0;
}