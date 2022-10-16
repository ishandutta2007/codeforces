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

void re(int& x);

void pr(int x);

void pr(const char *x);

void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);

#ifdef FFDBG

#else
#define dbg(x...) dsfdsfsdfasd
#endif

int t, n;

long long get(int h) {
    return (h * 1ll * (3*h + 1)) / 2;
}

void solve()
{
    for (re(t); t; t--) {
        re(n);

        int h = 1;
        for (; get(h) <= n; h++);
        h--;

        int ans = 0;
        for (; h >= 1; h--) {
            while (get(h) <= n) {
                n -= get(h);
                ans++;
            }
        }

        ps(ans);
    }
}

int main() {

    solve();
}

void re(int& x) { scanf("%d", &x); }

void pr(int x) { printf("%d", x); }

void pr(const char *x) { printf("%s", x); }

void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}