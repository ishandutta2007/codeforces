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

const int N=110;

int a[N][N];
int n, m;

int main() {
    int qn; scanf("%d%d%d", &n,&m,&qn);
    struct Q {
        int t, x, y, c;
        void read() {
            scanf("%d", &t);
            if(t==1 || t==2) scanf("%d", &x);
            else scanf("%d%d%d", &x,&y,&c);
        }
    };
    vector<Q> qs(qn); for(Q& q: qs) q.read();
    irepn(z, qn) {
        int t=qs[z].t;
        if(t==1 || t==2) {
            int i=qs[z].x;
            if(t==1) {
                int tmp=a[i][m];
                irep(j, m-1, 1) a[i][j+1]=a[i][j];
                a[i][1]=tmp;
            } else {
                int tmp=a[n][i];
                irep(j, n-1, 1) a[j+1][i]=a[j][i];
                a[1][i]=tmp;
            }
        } else {
            int x=qs[z].x, y=qs[z].y, c=qs[z].c;
            a[x][y]=c;
        }
    }
    rep(i, 1, n) {
        rep(j, 1, m) printf("%d ", a[i][j]);
        printf("\n");
    }
    return 0;
}