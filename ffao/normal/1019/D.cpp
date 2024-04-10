#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <memory.h>
#include <cmath>
#include <array>

using namespace std;

void re(int& x);
void re(long long& x);

template<class T, class... Ts> void re(T& t, Ts&... ts);

void pr(int x);

void pr(const char *x);

void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);

#ifdef FFDBG

#else
#define dbg(x...) dsfdsfsdfasd
#endif

typedef pair<int, int> pii;

#define all(v) (v).begin(), (v).end()

#define trav(a, x) for(auto& a : x)
#define rep(i, a, b) for(int i = a; i < (b); ++i)

int n;
long long S;

struct point {
    int x, y;
};

point p[2100];
int curp[2100];

vector< pair<double, pii> > lines;

long long area(int p1, int p2, int p3) {
    return abs(
        p[p1].x*1ll*p[p2].y + p[p2].x*1ll*p[p3].y + p[p3].x*1ll*p[p1].y - p[p1].x*1ll*p[p3].y - p[p2].x*1ll*p[p1].y - p[p3].x*1ll*p[p2].y
    );
}

bool checkd(int p1, int p2, int l, int r) {
    if (l > r) return false;
    while (l < r) {
        int m = (l+r)/2;

        if (area(p1,p2,m) <= S) r = m;
        else l = m+1;
    }

    if (area(p1,p2,l) == S) {
        ps("Yes");
        ps(p[p1].x,p[p1].y);
        ps(p[p2].x,p[p2].y);
        ps(p[l].x,p[l].y);
        return true;
    }

    return false;
}

bool checki(int p1, int p2, int l, int r) {
    if (l > r) return false;
    while (l < r) {
        int m = (l+r+1)/2;

        if (area(p1,p2,m) <= S) l = m;
        else r = m-1;
    }

    if (area(p1,p2,l) == S) {
        ps("Yes");
        ps(p[p1].x,p[p1].y);
        ps(p[p2].x,p[p2].y);
        ps(p[l].x,p[l].y);
        return true;
    }

    return false;
}

void solve()
{
    re(n,S);
    S <<= 1;

    rep(i,0,n) {
        re(p[i].x, p[i].y);
    }

    sort(p,p+n,[](const point& a, const point&b) { 
        return pii(a.y, a.x) < pii(b.y, b.x);
    });

    rep(i,0,n) curp[i] = i;

    rep(i,0,n) {
        rep(j,i+1,n) {
            int dy = p[i].y - p[j].y;
            int dx = p[i].x - p[j].x;

            lines.push_back( { atan2(dy,dx), {i,j} } );
        }
    }

    sort(all(lines));
    trav(line, lines) {
        int idx1 = line.second.first;
        int idx2 = line.second.second;

        int t1 = curp[idx1], t2 = curp[idx2];
        if (t1 > t2) swap(t1,t2);
        
        if (checkd(t1, t2, 0, t1-1)) return;
        if (checki(t1, t2, t2+1, n-1)) return;

        swap(p[t1], p[t2]);
        swap(curp[idx1],curp[idx2]);
    }

    ps("No");
}

int main() {

    solve();
}

void re(int& x) { scanf("%d", &x); }
void re(long long& x) { scanf("%lld", &x); }

template<class T, class... Ts> void re(T& t, Ts&... ts) { 
    re(t); re(ts...); 
}

void pr(int x) { printf("%d", x); }

void pr(const char *x) { printf("%s", x); }

void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}