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

const int mod = 1000000007;

int dp[40][40][3];
int p2[50];

int lim;

int calc(int n, int h, bool eq) {
    if (n == -1) return 1;
    int &ret = dp[n][h][eq];
    
    if (ret == -1) {
        ret = 0;

        if (!eq || (lim&(1<<n))) {
            ret = (ret + calc(n-1, h+1, eq && (lim&(1<<n)))) % mod;
            ret = (ret + (h==0 ? 0 : p2[h-1]) * 1ll * calc(n-1,h, eq && (lim&(1<<n)))) % mod;
        }
        ret = (ret + (h==0 ? 1 : p2[h-1]) * 1ll * calc(n-1,h, eq && !(lim&(1<<n)))) % mod;
    }

    return ret;
}

void solve()
{
    p2[0] = 1;
    for (int i = 1; i <= 45; i++) p2[i] = (p2[i-1]+p2[i-1])%mod;
    
    re(lim);
    memset(dp,-1,sizeof(dp));

    ps(calc(29,0,true));
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