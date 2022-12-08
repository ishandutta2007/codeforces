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

const int N=200020;

int n, a[N];
int vis[N];

int main() {
    scanf("%d", &n);
    rep(i, 1, n) scanf("%d", &a[i]);
    fillchar(vis, 0);
    VI heads;
    rep(i, 1, n) if(vis[i]==0) {
        int x=i;
        while(vis[x]==0) {
            vis[x]=i; x=a[x];
        }
        if(vis[x]==i) {
            heads.pb(x);
        }
    }

    int center=heads[0];
    for(int h: heads) if(a[h]==h) center=h;
    int ans=0;
    for(int h: heads) if(h!=center || a[h]!=h) {
        a[h]=center;
        ++ans;
    }
    printf("%d\n", ans);
    rep(i, 1, n) printf("%d ", a[i]); printf("\n");

    return 0;
}