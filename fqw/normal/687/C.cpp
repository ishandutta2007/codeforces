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

const int N=505;

bool f[2][N][N];
int n, k, c[N];

int main() {
    scanf("%d%d", &n,&k);
    rep(i, 1, n) scanf("%d", &c[i]);
    fillchar(f, 0);
    int o1=0, o2=1; f[o1][0][0]=true;
    rep(i, 1, n) {
        fillchar(f[o2], 0);
        rep(s, 0, k) rep(t, 0, s) if(f[o1][s][t]) {
            f[o2][s][t]=true;
            if(s+c[i]<=k) {
                f[o2][s+c[i]][t]=true;
                f[o2][s+c[i]][t+c[i]]=true;
            }
        }
        swap(o1, o2);
    }
    int cnt=0;
    rep(i, 0, k) if(f[o1][k][i]) ++cnt;
    printf("%d\n", cnt);
    rep(i, 0, k) if(f[o1][k][i]) printf("%d ", i);
    printf("\n");

    return 0;
}