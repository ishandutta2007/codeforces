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
const int M=200010;
const int Q=200010;

int u[M], v[M], l[Q], r[Q], s[Q], t[Q];
VI qs[M];
int n, m, q;

int f[N][N];
bool ans[M];

int main() {
    scanf("%d%d%d", &n,&m,&q);
    rep(i, 1, m) scanf("%d%d", &u[i],&v[i]);
    rep(i, 1, q) scanf("%d%d%d%d", &l[i],&r[i],&s[i],&t[i]);
    rep(i, 1, q) qs[r[i]].pb(i);

    rep(time, 1, m) {
        int x=u[time], y=v[time];
        rep(i, 1, n) {
            if(f[x][i]>f[y][i]) {
                f[y][i]=f[x][i];
            } else {
                f[x][i]=f[y][i];
            }
        }
        f[x][y]=f[y][x]=time;
        for(int i: qs[time]) {
            ans[i]=(f[t[i]][s[i]]>=l[i]);
        }
    }
    rep(i, 1, q) printf("%s\n", ans[i]?"Yes":"No");
    return 0;
}