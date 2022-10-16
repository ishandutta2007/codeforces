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
#define sz(x) (int)(x).size()
#define trav(a, x) for(auto& a : x)
#define rep(i, a, b) for(int i = a; i < (b); ++i)

int n;
int st[110000];
int ed[110000];
vector<int> iline;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b,a%b);
}

pair<int, int> norm(int a, int b) {
    int g = gcd(a,b);
    if (g < 0) g = - g;
    return {a/g, b/g};
}

int tree[310000];
int la[310000];
int ans[310000];

int read(int x) {
    int s = 0;
    for (; x > 0; x -= x&-x) s+=tree[x];
    return s;
}

void upd(int x, int d) {
    for (; x <= 300000; x+=x&-x) tree[x]+=d;
}

struct point {
    long long x,  y;

    bool top_half() const {
        return y > 0 || (y == 0 && x > 0);
    }
};

long long cross(const point &a, const point &b) {
    return (long long) a.x * b.y - (long long) b.x * a.y;
}

bool angle_compare(const point &a, const point &b) {
    if (a.top_half() ^ b.top_half())
        return a.top_half();
 
    return cross(a, b) > 0;
}
 
bool angle_equal(const point &a, const point &b) {
    if (a.top_half() ^ b.top_half())
        return false;
 
    return cross(a, b) == 0;
}

vector<point> lines;

void solve()
{
    re(n);
    rep(i,0,n) {
        int k; re(k); 
        st[i] = sz(lines)+1;
        ed[i] = st[i] + k - 1;

        vector< pii > poly(k);
        rep(j,0,k) re(poly[j].first, poly[j].second);
        rep(j,0,k) {
            int dx = poly[(j+1)%k].first - poly[j].first;
            int dy = poly[(j+1)%k].second - poly[j].second;
            pii n = norm(dy,dx);
            // dbg(n.second,n.first);
            lines.push_back(point{n.second,n.first});
            // dbg(lines[sz(lines)-1]);
        }
    }

    auto lin = lines;
    sort(all(lin), angle_compare);
    lin.erase(unique(all(lin), angle_equal), lin.end());
    rep(i,0,sz(lines)) iline.push_back( lower_bound(all(lin), lines[i], angle_compare) - lin.begin() );

    int q; re(q);
    vector< pair< pii, int>> qs;

    rep(i,0,q) {
        int l, r; re(l,r);
        qs.push_back({{r, l}, i});
    }

    sort(all(qs));
    int nxt = 1;

    trav(q,qs) {
        for (; nxt <= q.first.first; nxt++) {
            for (int idx = st[nxt-1]; idx <= ed[nxt-1]; idx++) {
                int val = iline[idx-1];
                if (la[val] != 0) upd(la[val], -1);

                upd(idx, 1);
                la[val] = idx;
            }
        }

        ans[q.second] = read(ed[q.first.first-1]) - read(st[q.first.second-1] - 1);
    }

    rep(i,0,q) ps(ans[i]);
}

int main() {

    solve();
}

void re(int& x) { scanf("%d", &x); }

template<class T, class... Ts> void re(T& t, Ts&... ts) { 
    re(t); re(ts...); 
}

void pr(int x) { printf("%d", x); }

void pr(const char *x) { printf("%s", x); }

void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}