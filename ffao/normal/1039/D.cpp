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
typedef vector<int> vi;

#define rep(i, a, b) for(int i = a; i < (b); ++i)

int n;
int u,v;
vi g[110000];
int r[110000];

pii checki(int v, int p, int k) {
    pii ret = {0, 1};

    for (int x : g[v]) if (x != p) {
        pii t = checki(x,v,k);
        ret.first += t.first;
        
        if (ret.second != 0) {
            if (ret.second + t.second - 1 >= k) {
                ret.second = 0;
                ret.first++;
            }
            else ret.second = max(ret.second, t.second);
        }
    }

    ret.second++;
    return ret;
}

int check(int k) {
    if (k == 1) return n;
    int &ret = r[k];
    if (ret == -1) ret = checki(0,-1,k).first;
    return ret;
}

void solve()
{
    memset(r,-1,sizeof(r));

    re(n);
    rep(i,0,n-1) {
        re(u,v); u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int k = 1;
    for (; k <= n; ) {
        int val = check(k);
        if (val == 0) break;

        int st = k, ed = n/val + 1;
        while (st < ed) {
            int md = (st+ed)/2;
            if (check(md) < val) ed = md;
            else st = md+1;
        }

        for (; k < st; k++) ps(val);
    }

    for (; k <= n; k++) ps(0);
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