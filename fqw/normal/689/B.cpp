#include <queue>
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

int a[N], n, f[N];

int main() {
    scanf("%d", &n);
    rep(i, 1, n) scanf("%d", &a[i]);
    fillchar(f, 50); const int inf=f[0];
    f[1]=0;
    queue<int> que; que.push(1);
    while(!que.empty()) {
        int x=que.front(); que.pop();
        for(int y: {x+1, x-1, a[x]})
            if(y>=1 && y<=n && f[y]==inf) {
                f[y]=f[x]+1;
                que.push(y);
            }
    }
    rep(i, 1, n) printf("%d ", f[i]);
    printf("\n");
    return 0;
}