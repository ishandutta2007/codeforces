// 22:56 - 22:17 - fail sample
//       - 22:29 - pass samples
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>
using namespace std;

#define _ (size_t)
#define all(a) a.begin(), a.end()
#define forint(i, a, b) for(int i=int(a); i<=int(b); ++i)
#define forintdown(i, a, b) for(int i=int(a); i>=int(b); --i)
#define forn(i, n) forint(i, 0, (n)-1)
#define forndown(i, n) forintdown(i, (n)-1, 0)
#define fillchar(a, x) memset(a, x, sizeof(a))
#define fi first
#define se second
#define PB push_back
#define MP make_pair
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

const int MAXN=2020;
const int MAXE=100010;

int ea[MAXE], eb[MAXE], ec[MAXE];
int start_point[2];
int val[MAXN];
int n, m;

void init() {
    scanf("%d%d", &n,&m);
    forn(i, 2) scanf("%d", &start_point[i]);
    forint(i, 1, n) scanf("%d", &val[i]);
    forint(i, 1, m) 
        scanf("%d%d%d", &ea[i], &eb[i], &ec[i]);
}

int ind[2][MAXN], pos[2][MAXN]; LL dis[2][MAXN];
bool v[2][MAXN][MAXN], v2[2][MAXN][MAXN];
LL s[2][MAXN][MAXN];

void preprocess() {
    forn(t, 2) {
        fillchar(dis[t], 50);
        dis[t][start_point[t]]=0;
        forn(times, n) {
            forint(i, 1, m) setmin(dis[t][eb[i]], dis[t][ea[i]]+(LL)ec[i]);
            forint(i, 1, m) setmin(dis[t][ea[i]], dis[t][eb[i]]+(LL)ec[i]);
        }
        vector<pair<LL,int>> tmp;
        forint(i, 1, n) tmp.PB(MP(dis[t][i], i));
        sort(all(tmp));
        forint(i, 1, n) ind[t][i]=tmp[i-1].se, pos[t][ind[t][i]]=i;
    }
    forn(t, 2) {
        forint(x, 0, n) {
            static bool ok[MAXN];
            fillchar(ok, true);
            forint(i, 1, x) ok[ind[t][i]]=false;

            fillchar(v[t][x], false);
            fillchar(v2[t][x], false);
            LL la=1LL<<60;
            forintdown(i, n, 1) {
                if(ok[ind[t^1][i]]) {
                    LL d=dis[t^1][ind[t^1][i]];
                    if(d<la) {
                        v[t][x][i]=true;
                        la=d;
                    }
                }
                v2[t][x][i]=(v[t][x][i]||v2[t][x][i+1]);
            }

            s[t][x][0]=0;
            forint(i, 1, n) {
                LL c=val[ind[t^1][i]];
                if(!ok[ind[t^1][i]]) c=0;
                s[t][x][i]=s[t][x][i-1]+c;
            }
        }
    }
}


LL f[2][MAXN][MAXN];
LL g[2][MAXN][MAXN];
bool bf[2][MAXN][MAXN];
bool bg[2][MAXN][MAXN];
LL cal_g(int, int, int);
LL cal_f(int, int, int);

LL cal_g(int t, int x, int y) {
    if(bg[t][x][y]) return g[t][x][y];
    bg[t][x][y]=true;
    LL &ans=g[t][x][y];
    ans=-1LL<<60;
    if(y<n) 
        setmax(ans, cal_g(t, x, y+1));
    if(v[t][x][y])
        setmax(ans, s[t][x][y]-cal_f(t, x, y));
    return ans;
}

LL cal_f(int t, int x, int y) {
    if(bf[t][x][y]) return f[t][x][y];
    bf[t][x][y]=true;
    LL &ans=f[t][x][y];
    if(!v2[t^1][y][x+1])
        return ans=0;
    ans=cal_g(t^1, y, x+1)-s[t^1][y][x];
    return ans;
}

void solve() {
    fillchar(bg, false);
    fillchar(bf, false);
    LL ans=cal_f(0, 0, 0);

    if(ans==0) cout<<"Flowers"<<endl;
    else {
        if(ans<0) cout<<"Cry"<<endl;
        else cout<<"Break a heart"<<endl;
    }
}

int main() {
    init();
    preprocess();
    solve();
    return 0;
}