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

const int N=100010;

VI es[N]; int size[N];
int n;

void dfs(int x) {
    size[x]=1;
    for(int y: es[x]) {
        dfs(y);
        size[x]+=size[y];
    }
}

double ans[N];

void dfs2(int x, double pre) {
    pre+=1;
    ans[x]=pre;
    if(!es[x].empty()) {
        //int cnt=sz(es[x]);
        double t=0; for(int y: es[x]) t+=size[y];
        for(int y: es[x]) {
            dfs2(y, pre+(t-size[y])/2);
        }
    }
}

int main() {
    scanf("%d", &n);
    rep(i, 2, n) {
        int j; scanf("%d", &j);
        es[j].pb(i);
    }
    dfs(1);
    dfs2(1, 0);
    rep(i, 1, n) printf("%.9lf ", ans[i]); printf("\n");
    return 0;
}