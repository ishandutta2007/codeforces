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

template<class T> void re(std::vector<T>& a);

void pr(int x);

void pr(const char *x);

void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);

#ifdef FFDBG

#else
#define dbg(x...) dsfdsfsdfasd
#endif

typedef vector<int> vi;

int n;
int g[2100][30];

void solve()
{
    re(n);
    vi a(n); re(a);

    int no = 0;
    for (int i = 0; i < n; i++) if (a[i] != 1) no++;
    if (no != n) {
        ps(no);
        return;
    }

    int ans = 1000000000;

    for (int i = 0; i < n; i++) g[i][0] = a[i];
    
    for (int j = 1; j < 30; j++) {
        for (int i = 0; i < n; i++) {
            g[i][j] = g[i][j-1];
            if (i + (1<<(j-1)) < n) g[i][j] = __gcd(g[i][j], g[i + (1<<(j-1))][j-1]);
        }
    }

    for (int i = 0; i < n-1; i++) {
        int c = i;
        int cv = a[i];
        for (int k = 29; k >= 0; k--) if (c + (1<<k) < n && __gcd(cv,g[c][k]) != 1) {
            cv = __gcd(cv, g[c][k]);
            c += (1<<k);
        }

        if (__gcd(cv, a[c]) == 1) {
            ans = min(ans, (c - i) + n-1);
        }
    }

    ps(ans == 1000000000 ? -1 : ans);
}

int main() {

    solve();
}

void re(int& x) { scanf("%d", &x); }

template<class T> void re(std::vector<T>& a) { for (int i = 0; i < a.size(); i++) re(a[i]); }

void pr(int x) { printf("%d", x); }

void pr(const char *x) { printf("%s", x); }

void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}