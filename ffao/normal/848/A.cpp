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

void pr(char x);
void pr(const char *x);

void ps();

#ifdef FFDBG

#else
#define dbg(x...) dsfdsfsdfasd
#endif

#define rep(i, a, b) for(int i = a; i < (b); ++i)

int k;
void solve()
{
    re(k);

    for (int i = 0; i < 26; i++) {
        int c = 1;
        while (c*1ll*(c+1)/2 <= k) c++;

        k -= c*1ll*(c-1)/2;
        rep(j,0,c) pr((char)('a'+i));
    }
    ps();
}

int main() {

    solve();
}

void re(int& x) { scanf("%d", &x); }

void pr(char x) { printf("%c", x); }
void pr(const char *x) { printf("%s", x); }

void ps() { pr("\n"); }