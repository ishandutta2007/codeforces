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

template<class T, class... Ts> void re(T& t, Ts&... ts);

void pr(const char *x);

void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);

#ifdef FFDBG

#else
#define dbg(x...) dsfdsfsdfasd
#endif

int h,m,s,t1,t2;

void solve()
{
    re(h,m,s,t1,t2);
    if (h == 12) h = 0;
    if (t1 == 12) t1 = 0;
    if (t2 == 12) t2 = 0;

    h *= 10;
    if (m != 0 || s != 0) h++;
    m *= 2;
    s *= 2;
    if (s != 0) m++;
    t1 *= 10;
    t2 *= 10;

    bool okf = true, okb = true;
    for (int i = t1; i != t2; i = (i+1)%120) {
        if (i == h || i == m || i == s) okf = false;
    }

    for (int i = t1; i != t2; i = (i+119)%120) {
        if (i == h || i == m || i == s) okb = false;
    }

    ps((okf || okb) ? "YES" : "NO");
}

int main() {

    solve();
}

void re(int& x) { scanf("%d", &x); }

template<class T, class... Ts> void re(T& t, Ts&... ts) { 
    re(t); re(ts...); 
}

void pr(const char *x) { printf("%s", x); }

void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}