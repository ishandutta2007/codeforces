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

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#include <iostream>

string pw;
int n;

void solve()
{
    int ed = 0;
    int st = 0;
    cin >> pw;
    re(n);
    rep(i,0,n) {
        string s;
        cin >> s;
        if (s == pw) {
            ps("YES");
            return;
        }

        if (s[1] == pw[0]) st = 1;
        if (s[0] == pw[1]) ed = 1;
    }

    ps(st+ed == 2 ? "YES" : "NO");
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