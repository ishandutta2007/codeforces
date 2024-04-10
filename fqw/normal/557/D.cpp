#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
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
typedef vector<string> VS;
template<class T> bool setmax(T &_a, T _b) { if(_b>_a) { _a=_b; return true; } return false; }
template<class T> bool setmin(T &_a, T _b) { if(_b<_a) { _a=_b; return true; } return false; }
template<class T> T gcd(T _a, T _b) { return _b==0?_a:gcd(_b,_a%_b); }

const int MAXN=100010;

VI es[MAXN];
int n;

int color[MAXN];
bool dfs(int x, int fa, int c) {
    color[x]=c;
    for(int y: es[x]) if(y!=fa) {
        if(color[y]<0) {
            if(dfs(y, x, c^1)) return true;
        } else {
            if(color[y]==color[x]) return true;
        }
    }
    return false;
}
VI lst;
void dfs2(int x, int fa, int c) {
    color[x]=c; lst.pb(x);
    for(int y: es[x]) if(y!=fa && color[y]<0)
        dfs2(y, x, c^1);
}

int main() {
    int m; scanf("%d%d", &n,&m);
    rep(i, 1, n) es[i].clear();
    rep(i, 1, m) {
        int a, b; scanf("%d%d", &a,&b);
        es[a].pb(b);
        es[b].pb(a);
    }

    fillchar(color, 0xff);
    bool found=false;
    rep(i, 1, n) if(color[i]<0) if(dfs(i, 0, 0)) found=true;
    if(found) printf("0 1\n");
    else {
        LL ans=0;
        fillchar(color, 0xff);
        rep(i, 1, n) if(color[i]<0) {
            lst.clear();
            dfs2(i, 0, 0);
            int c0=0, c1=0;
            for(int x: lst) if(color[x]==0) ++c0; else ++c1;
            ans+=LL(c0)*LL(c0-1)/2;
            ans+=LL(c1)*LL(c1-1)/2;
        }
        if(ans>0) cout<<"1 "<<ans<<endl;
        else {
            if(m>0) {
                ans=LL(m)*LL(n-2);
                cout<<"2 "<<ans<<endl;
            } else {
                ans=LL(n)*LL(n-1)*LL(n-2)/6;
                cout<<"3 "<<ans<<endl;
            }
        }
    }

    return 0;
}