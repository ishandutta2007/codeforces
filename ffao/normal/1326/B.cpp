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

template<class T, class... Ts> void pr(const T& t, const Ts&... ts);

void ps();

#ifdef FFDBG

#else
#define dbg(x...) dsfdsfsdfasd
#endif

#define rep(i, a, b) for(int i = a; i < (b); ++i)

int n;

void solve()
{
    re(n);

    int m = 0;
    rep(i,0,n) {
        int b;
        re(b);

        pr(m+b," ");
        if (b > 0) m += b;
    }
    ps();
}

int main() {

    solve();
}

void re(int& x) { scanf("%d", &x); }

void pr(int x) { printf("%d", x); }

void pr(const char *x) { printf("%s", x); }

template<class T, class... Ts> void pr(const T& t, const Ts&... ts) { 
    pr(t); pr(ts...); 
}

void ps() { pr("\n"); }