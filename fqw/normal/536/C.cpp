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
typedef pair<int,int> PDD;
typedef vector<LL> VL;
typedef vector<int> VI;
typedef vector<PII> VPI;
typedef vector<string> VS;
template<class T> bool setmax(T &_a, T _b) { if(_b>_a) { _a=_b; return true; } return false; }
template<class T> bool setmin(T &_a, T _b) { if(_b<_a) { _a=_b; return true; } return false; }
template<class T> T gcd(T _a, T _b) { return _b==0?_a:gcd(_b,_a%_b); }

struct Point {
    int x, y;
    bool operator <(const Point &p) const {
        if(x!=p.x) return x<p.x;
        return y>p.y;
    }
    friend int mult(Point p0, Point p1, Point p2) { 
        LL x0=p0.x, x1=p1.x, x2=p2.x, tx=x0*x1*x2;
        LL y0=p0.y, y1=p1.y, y2=p2.y, ty=y0*y1*y2;
        x0=tx/x0, x1=tx/x1, x2=tx/x2;
        y0=ty/y0, y1=ty/y1, y2=ty/y2;
        x1-=x0, x2-=x0;
        y1-=y0, y2-=y0;
        LL tmp=x1*y2-x2*y1;
        if(tmp==0) return 0;
        return tmp<0?-1:1;
    }
};

Point a[200010];
VI ids[200010];
bool valid[200010];
int n;
VI ans;

void clear_same_x() {
    map<int, int> xs;
    forint(i, 1, n) if(valid[i]) {
        setmax(xs[a[i].x], a[i].y);
    }
    forint(i, 1, n) if(valid[i]) {
        if(a[i].y==xs[a[i].x])
            continue;
        valid[i]=false;
    }
}

bool cmp1(int i, int j) {
    return a[i].x<a[j].x;
}

int main() {
    map<PII, int> p;
    int num;
    scanf("%d", &num);
    n=0;
    forint(i, 1, num) {
        int x, y;
        scanf("%d%d", &x, &y);
        if(p.find(MP(x, y))==p.end()) {
            ++n;
            a[n].x=x, a[n].y=y;
            ids[n].clear();
            p[MP(x, y)]=n;
        }
        ids[p[MP(x, y)]].PB(i);
    }

    fillchar(valid, true);
    clear_same_x();
    forint(i, 1, n) swap(a[i].x, a[i].y);
    clear_same_x();
    forint(i, 1, n) swap(a[i].x, a[i].y);

    VI es;
    forint(i, 1, n) if(valid[i]) es.PB(i);
    sort(all(es), cmp1);

    VI fs;
    for(int e: es) {
        while(fs.size()>0) {
            if(a[fs.back()].y<a[e].y) {
                fs.pop_back(); continue;
            }
            if(fs.size()>=2 && mult(a[fs[fs.size()-2]], a[fs.back()], a[e])>0) {
                fs.pop_back(); continue;
            }
            break;
        }
        fs.PB(e);
    }
    for(int f: fs)
        for(int id: ids[f])
            ans.PB(id);
    sort(all(ans));
    for(int i: ans) cout<<i<<" "; cout<<endl;

    return 0;
}