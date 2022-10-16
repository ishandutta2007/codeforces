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

#define rep(i, a, b) for(int i = a; i < (b); ++i)

int nn;
int a[310];
int s[310];
int pd[310][310][310];

const int mod = 1000000007;

int rec(int i, int otblock, int curblock) {
    if (i == nn) return otblock+curblock == 0;
    
    if (i != 0 && a[i] != a[i-1]) {
        otblock += curblock;
        curblock = 0;
    }

    int &ret = pd[i][otblock][curblock];
    if (ret == -1) {
        ret = 0;

        int tot_spaces = i+1;
        int add_one = 2*s[i] - curblock;
        int rem_one = otblock;
        int generic_spaces = tot_spaces - rem_one - add_one;

        ret = (ret + generic_spaces * 1ll * rec(i+1, otblock, curblock)) % mod;
        ret = (ret + add_one * 1ll * rec(i+1, otblock, curblock+1)) % mod;
        if (otblock) ret = (ret + rem_one * 1ll * rec(i+1, otblock-1, curblock)) % mod;
    }

    // dbg(i,otblock,curblock,ret);
    return ret;
}

void solve()
{
    memset(pd,-1,sizeof(pd));

    re(nn);
    rep(i,0,nn) {
        re(a[i]);
        for (int s = 2; s*s <= a[i]; s++) {
            int sq = s*s;
            while (a[i] % sq == 0) a[i]/=sq;
        }
    }

    sort(a,a+nn);
    // int la = 0;
    for (int i = 0; i < nn; i++) {
        if (i != 0 && a[i] == a[i-1]) s[i] = s[i-1]+1;
        // if (a[i] != a[la] || i == n) {
        //     eq.push_back(i-la);
        //     la = i;
        // }
    }

    ps(rec(0,0,0));
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