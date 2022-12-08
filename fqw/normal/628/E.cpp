// 9:36 - 9:47
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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

const int N=3030;

bool z[N][N]; int l[N][N], r[N][N];
int n, m;

VI ds[N];
int tr[N];
void inc(int x) { for(; x<N; x+=x&-x) ++tr[x]; }
void dec(int x) { for(; x<N; x+=x&-x) --tr[x]; }
int get(int x) { int ans=0; for(; x>0; x-=x&-x) ans+=tr[x]; return ans; }

LL go(int x, int y) {
    LL ans=0;
    int x0, y0; bool expired=true;
    for(; x<=n && y>=1; ++x, --y) {
        if(!z[x][y]) { expired=true; continue; }
        if(expired) {
            expired=false;
            x0=x, y0=y;
            while(x0<n && y0>1 && z[x0+1][y0-1]) ++x0, --y0;
        }
        ans+=get(y+r[x][y]-1)+1;
        inc(y); ds[max(y0, y-l[x][y]+1)].pb(y);
        for(int y2: ds[y]) dec(y2); ds[y].clear();
    }
    return ans;
}

int main() {
    scanf("%d%d", &n,&m);
    rep(i, 1, n) {
        static char buf[N];
        scanf("%s", buf+1);
        rep(j, 1, m) z[i][j]=(buf[j]=='z');
    }
    fillchar(l, 0); fillchar(r, 0);
    rep(i, 1, n) {
        rep(j, 1, m) if(z[i][j]) l[i][j]=l[i][j-1]+1;
        irep(j, m, 1) if(z[i][j]) r[i][j]=r[i][j+1]+1;
    }
    LL ans=0;
    fillchar(tr, 0); rep(i, 1, m) ds[i].clear();
    rep(j, 1, m) ans+=go(1, j);
    rep(i, 2, n) ans+=go(i, m);
    cout<<ans<<endl;
    return 0;
}