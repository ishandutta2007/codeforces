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

void pr(const char *x);

void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);

#ifdef FFDBG

#else
#define dbg(x...) dsfdsfsdfasd
#endif

int t;
int n;

void solve()
{
    for (re(t); t; t--) {
        re(n);

        vector<int> a(n), occ(n);
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            re(a[i]);
            int nn = ( ( (i + a[i])%n ) + n) % n;

            if (!occ[nn]) {
                occ[nn] = 1;
                cnt++;
            }
        }

        ps(cnt == n ? "YES" : "NO");
    }
}

int main() {

    solve();
}

void re(int& x) { scanf("%d", &x); }

void pr(const char *x) { printf("%s", x); }

void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}