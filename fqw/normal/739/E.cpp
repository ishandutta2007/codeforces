// 10:13 - 10:29 - wa sample
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <limits>
#include <memory>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) static_cast<int>((a).size())
#define fillchar(a, x) memset(a, x, sizeof(a))
#define rep(i, a, b) for(int i=int(a); i<=int(b); ++i)
#define irep(i, a, b) for(int i=int(a); i>=int(b); --i)
#define replr(i, a, b) rep(i, a, (b)-1)
#define reprl(i, a, b) irep(i, (b)-1, a)
#define repn(i, n) rep(i, 0, (n)-1)
#define irepn(i, n) irep(i, (n)-1, 0)
#define p first
#define q second
#define pb push_back
#define mp make_pair
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef vector<LL> VL;
typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<PII> VPI;
typedef vector<PDD> VPD;
typedef vector<string> VS;
template<class T, class S> ostream& operator<<(ostream& os, const pair<T, S>& v) { return os<<"("<<v.first<<", "<<v.second<<")"; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& v) { os<<"["; repn(i, sz(v)) { if(i) os<<", "; os<<v[i]; } return os<<"]"; }
template<class T> bool setmax(T &_a, T _b) { if(_b>_a) { _a=_b; return true; } return false; }
template<class T> bool setmin(T &_a, T _b) { if(_b<_a) { _a=_b; return true; } return false; }
template<class T> T gcd(T _a, T _b) { return _b==0?_a:gcd(_b,_a%_b); }

struct KeepMaxK {
    const int k;
    priority_queue<double> q;
    double s=0;

    KeepMaxK(int _k) : k(_k) {}

    void add(double val) {
        q.push(-val), s+=val;
        if(sz(q)>k) {
            s+=q.top(), q.pop();
        }
    }

    double sum() const { return s; }
};

int main() {
    int n, a, b; scanf("%d%d%d", &n,&a,&b);
    VPD xs(n);
    repn(i, n) scanf("%lf", &xs[i].p);
    repn(i, n) scanf("%lf", &xs[i].q);

    double ans=0;
    sort(all(xs), [](const PDD& u, const PDD& v) { return u.q>v.q; });
    rep(i, b, min(n, a+b)) {
        sort(xs.begin(), xs.begin()+i,
             [](const PDD& u, const PDD& v) { return u.q*(1-u.p)>v.q*(1-v.p); });

        VD mid_val(b+1);
        {
            KeepMaxK keep(i-b);
            double sum=0;
            irepn(k, i) {
                sum+=xs[k].q;
                keep.add(xs[k].p-xs[k].q);
                if(k<=b) {
                    mid_val[k]=sum+keep.sum();
                }
            }
        }

        double sum_b=0;
        KeepMaxK keep(a+b-i);
        replr(k, i, n) keep.add(xs[k].p);
        rep(j, 0, b) {
            if(setmax(ans, mid_val[j]+sum_b+keep.sum())) {
                //
            }
            if(j<b) {
                sum_b+=xs[j].q;
                keep.add(xs[j].p*(1-xs[j].q));
            }
        }
    }
    printf("%.9lf\n", ans);

    return 0;
}