#include <cassert>
#include <functional>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <set>
#include <string>
#include <vector>
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
typedef vector<PLL> VPL;
typedef vector<string> VS;
template<class T> bool setmax(T &_a, T _b) { if(_b>_a) { _a=_b; return true; } return false; }
template<class T> bool setmin(T &_a, T _b) { if(_b<_a) { _a=_b; return true; } return false; }
template<class T> T gcd(T _a, T _b) { return _b==0?_a:gcd(_b,_a%_b); }

const int N=555;

bool g[N][N]; int d[N];
int n;

int main() {
    fillchar(d, 0);
    fillchar(g, false);
    int m; cin>>n>>m;
    rep(i, 1, m) {
        int u, v; cin>>u>>v;
        g[u][v]=g[v][u]=true;
        d[u]++, d[v]++;
    }
    if(m==n*(n-1)/2) {
        cout<<"Yes"<<endl<<string(n, 'a')<<endl;
        return 0;
    }
    string r(n, ' ');
    function<bool(int,char)> dfs=[&](int i, char c) {
        if(r[i-1]!=' ') return r[i-1]==c;
        r[i-1]=c;
        rep(j, 1, n) if(j!=i && !g[i][j]) {
            if(!dfs(j, c=='a'?'c':'a')) return false;
        }
        return true;
    };
    rep(i, 1, n) if(r[i-1]==' ') {
        if(d[i]==n-1) r[i-1]='b';
        else {
            if(!dfs(i, 'a')) { cout<<"No"<<endl; return 0; }
        }
    }
    rep(i, 1, n) rep(j, 1, n) if(r[i-1]=='a' && r[j-1]=='c' && g[i][j]) {
        cout<<"No"<<endl;
        return 0;
    }
    cout<<"Yes"<<endl<<r<<endl;
    return 0;
}