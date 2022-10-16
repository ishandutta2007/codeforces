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
template<class T> void re(std::vector<T>& a);

void pr(int x);

void pr(char x);
void pr(const char *x);

template<class T> void pr(const std::vector<T> x);

void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);

#ifdef FFDBG

#else
#define dbg(x...) dsfdsfsdfasd
#endif

typedef vector<int> vi;

int n;

void solve()
{
    re(n);
    vi l(n), r(n); re(l, r);
    vi mk(n), ans(n);

    for (int c = n; c > 0; c--) {
        vi cur;

        for (int i = 0; i < n; i++) if (!mk[i]) {
            if (l[i] == 0 && r[i] == 0) cur.push_back(i);
        }

        for (int x : cur) {
            ans[x] = c; 
            for (int i = 0; i < n; i++) {
                if (x < i) l[i]--;
                if (x > i) r[i]--;
            }
            mk[x] = 1;
        }
    }

    for (int i = 0; i < n; i++) if (!mk[i]) {
        ps("NO");
        return;
    }

    ps("YES");
    ps(ans);
}

int main() {

    solve();
}

void re(int& x) { scanf("%d", &x); }

template<class T, class... Ts> void re(T& t, Ts&... ts) { 
    re(t); re(ts...); 
}
template<class T> void re(std::vector<T>& a) { for (int i = 0; i < a.size(); i++) re(a[i]); }

void pr(int x) { printf("%d", x); }

void pr(char x) { printf("%c", x); }
void pr(const char *x) { printf("%s", x); }

template<class T> void pr(std::vector<T> v) {
    int f=0;
    for (int x : v) {
        if (f++) pr(' ');
        pr(x);
    }
}

void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}