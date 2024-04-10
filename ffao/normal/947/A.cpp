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

void pr(int x);

void pr(const char *x);

void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);

#ifdef FFDBG

#else
#define dbg(x...) dsfdsfsdfasd
#endif

int p[1100000];
int mn[1100000];
int n;

void solve()
{
    for (int i = 2; i <= 1000000; i++) if (!p[i]) {
        for (int j = i+i; j <= 1000000; j += i) {
            p[j] = i;
        }
    }

    for (int i = 3; i <= 1000000; i++) {
        int oi = i;
        mn[i] = i;
        if (p[i]) {
            while (i > 1) {
                int pp = p[i];
                if (pp == 0) pp = i;

                i /= pp;
                mn[oi] = min(mn[oi], oi - pp + 1);
            }
        }

        i = oi;
    }

    re(n);
    //dbg(mn[14]);
    int ans = 10000000;
    for (int i = mn[n]; i < n; i++) {
        ans = min(ans, mn[i]);
    } 
    ps(ans);
}

int main() {

    solve();
}

// typedef unsigned long long ull;

// template <ull MOD>
// void mult(unsigned int * __restrict__ A, unsigned int * __restrict__ B, unsigned int * __restrict__ C, int Cn, int Am, int Cm)
// {
//     static ull buf[1000];
 
void re(int& x) { scanf("%d", &x); }

void pr(int x) { printf("%d", x); }

void pr(const char *x) { printf("%s", x); }

void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}

#ifdef FFDBG

#else
#define dbg(x...) dsfdsfsdfasd
#endif