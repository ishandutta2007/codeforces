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

struct Point {
    double x, y;
    void read() { scanf("%lf%lf", &x,&y); }
    friend double dis(Point a, Point b) {
        return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
    }
};

Point a, b, t, p[100010];
int n;

int main() {
    a.read(), b.read(), t.read();
    scanf("%d", &n);
    rep(i, 1, n) p[i].read();

    double ans0=0;
    rep(i, 1, n) ans0+=dis(p[i], t)*2;
    double ans=1e50;

    repn(k, 2) {
        swap(a, b);
        pair<double, int> mb(1e50,0), mb2(1e50,0);
        rep(i, 1, n) {
            pair<double, int> cur=mp(dis(p[i], b)-dis(p[i], t), i);
            if(setmin(mb2, cur)) {
                if(mb2<mb) swap(mb, mb2);
            }
        }
        rep(i, 1, n) {
            double cur=dis(p[i], a)-dis(p[i], t);
            double cur2=(mb.se==i?mb2.fi:mb.fi);
            setmin(ans, ans0+cur+min(0.,cur2));
        }
    }
    printf("%.9lf\n", ans);

    return 0;
}