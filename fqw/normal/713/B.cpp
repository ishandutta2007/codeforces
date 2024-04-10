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
template<class T, class S> ostream& operator<<(ostream& os, const pair<T, S>& v) { return os<<"("<<v.first<<", "<<v.second<<")"; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& v) { os<<"["; repn(i, sz(v)) { if(i) os<<", "; os<<v[i]; } return os<<"]"; }
template<class T> bool setmax(T &_a, T _b) { if(_b>_a) { _a=_b; return true; } return false; }
template<class T> bool setmin(T &_a, T _b) { if(_b<_a) { _a=_b; return true; } return false; }
template<class T> T gcd(T _a, T _b) { return _b==0?_a:gcd(_b,_a%_b); }

int n;

int query(PII x, PII y) {
    cout<<"? " << x.fi<<" "<<y.fi<<" "<<x.se<<" "<<y.se<<endl;
    int v; cin>>v;
    return v;
}

// 0: x-, 1: x+, 2: y-, 3: y+
int query(int i, int cut) {
    PII x(1, n), y(1, n);
    if(i==0) x.fi+=cut;
    else if(i==1) x.se-=cut;
    else if(i==2) y.fi+=cut;
    else if(i==3) y.se-=cut;
    return query(x, y);
}

void answer(PII x1, PII y1, PII x2, PII y2) {
    cout<<"! " << x1.fi<<" "<<y1.fi<<" "<<x1.se<<" "<<y1.se<<" ";
    cout<<x2.fi<<" "<<y2.fi<<" "<<x2.se<<" "<<y2.se<<endl;
    exit(0);
}

int max_cut(int i, int limit) {
    int le=0, ri=n-1;
    while(le<ri) {
        const int mid=(le+ri+1)/2;
        if(query(i, mid)>=limit) {
            le=mid;
        } else {
            ri=mid-1;
        }
    }
    return le;
}

pair<VI, VI> go(bool is_x) {
    if(is_x) {
        const int l1=1+max_cut(0, 2);
        const int l2=1+max_cut(0, 1);
        const int r1=n-max_cut(1, 2);
        const int r2=n-max_cut(1, 1);
        return {{l1, l2}, {r1, r2}};
    } else {
        const int l1=1+max_cut(2, 2);
        const int l2=1+max_cut(2, 1);
        const int r1=n-max_cut(3, 2);
        const int r2=n-max_cut(3, 1);
        return {{l1, l2}, {r1, r2}};
    }
}

bool check(PII x, PII y) {
    if(x.fi>x.se || y.fi>y.se) return false;
    if(query(x, y)!=1) return false;
    if(x.fi<x.se) {
        if(query(mp(x.fi+1, x.se), y)>0) return false;
        if(query(mp(x.fi, x.se-1), y)>0) return false;
    }
    if(y.fi<y.se) {
        if(query(x, mp(y.fi+1, y.se))>0) return false;
        if(query(x, mp(y.fi, y.se-1))>0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);

    cin>>n;
    pair<VI, VI> xs=go(true);
    pair<VI, VI> ys=go(false);
    repn(i, 2) repn(j, 2) repn(k, 2) {
        PII x1=mp(xs.fi[0], xs.se[i]), y1=mp(ys.fi[j], ys.se[k]);
        PII x2=mp(xs.fi[1], xs.se[i^1]), y2=mp(ys.fi[j^1], ys.se[k^1]);
        if(check(x1, y1) && check(x2, y2)) {
            answer(x1, y1, x2, y2);
        }
    }

    return 0;
}