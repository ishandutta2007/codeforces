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
void re(long long& x);

template<class T, class... Ts> void re(T& t, Ts&... ts);

void pr(long long x);

void pr(const char *x);

void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);

#ifdef FFDBG

#else
#define dbg(x...) dsfdsfsdfasd
#endif

long long n;
int t;

long long f(long long n, long long x) {
    if (x % 2 == 1) return (x+1)/2;
    return f(n - x/2, n - x/2) + x/2;
}

void solve()
{
    for (re(n,t); t; t--) {
        long long x; re(x);
        ps(f(n,x));
    }
}

int main() {

    solve();
}

void re(int& x) { scanf("%d", &x); }
void re(long long& x) { scanf("%lld", &x); }

template<class T, class... Ts> void re(T& t, Ts&... ts) { 
    re(t); re(ts...); 
}

void pr(long long x) { printf("%lld", x); }

void pr(const char *x) { printf("%s", x); }

void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}