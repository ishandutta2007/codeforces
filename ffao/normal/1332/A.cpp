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

template<class T, class... Ts> void re(T& t, Ts&... ts);

void pr(const char *x);

void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);

#ifdef FFDBG

#else
#define dbg(x...) dsfdsfsdfasd
#endif

int t;
int a,b,c,d;
int x,y,x1,y1,x2,y2;

void solve()
{
    for (re(t); t; t--) {
        re(a,b,c,d);
        re(x,y,x1,y1,x2,y2);

        int left = (x-x1 >= max(0, a-b));
        int right = (x2-x >= max(0, b-a));
        int down = (y-y1 >= max(0, c-d));
        int up = (y2-y >= max(0, d-c));

        int hor = left && right && (x1 != x || x2 != x || a+b == 0);
        int vert = up && down && (y1 != y || y2 != y || c+d == 0);

        if (hor && vert) ps("Yes");
        else ps("No");
    }
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