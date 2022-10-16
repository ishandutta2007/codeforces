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

void pr(int x);

void pr(const char *x);

template<class T, class... Ts> void pr(const T& t, const Ts&... ts);

void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);

#ifdef FFDBG

#else
#define dbg(x...) dsfdsfsdfasd
#endif

int n,a,b;
void solve()
{
    re(n,a,b);
    for (int na = 0; a*na <= n; na++) {
        int nb = (n - a*na)/b;
        if (na*a + nb*b == n) {

            int st = 1;
            for (; na; na--) {
                for (int t = st; t < st+a-1; t++) pr(t+1," ");
                pr(st," ");
                st += a;
            }

            for (; nb; nb--) {
                for (int t = st; t < st+b-1; t++) pr(t+1," ");
                pr(st," ");
                st += b;
            }

            return;
        }
    }

    ps(-1);
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

template<class T, class... Ts> void pr(const T& t, const Ts&... ts) { 
    pr(t); pr(ts...); 
}

void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}