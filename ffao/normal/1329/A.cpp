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

void pr(const char *x);

template<class T, class... Ts> void pr(const T& t, const Ts&... ts);

void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);

#ifdef FFDBG

#else
#define dbg(x...) dsfdsfsdfasd
#endif

typedef vector<int> vi;

#define rep(i, a, b) for(int i = a; i < (b); ++i)

int n,m;

void solve()
{
    re(n,m);
    vi a(m); re(a);

    vector<long long> sum(m);
    sum[m-1] = a[m-1];
    for (int i = m-2; i >= 0; i--) sum[i] = sum[i+1] + a[i];

    vector<int> ans(m);

    int p = -1;
    int u = 0;
    rep(i,0,m) {
        ans[i] = max((long long)p+1, n - sum[i]);

        if (ans[i] > n - a[i] || ans[i] > u) {
            ps(-1);
            return;
        }

        p = ans[i];
        u = max(u, ans[i] + a[i]);
    }

    rep(i,0,m) pr(ans[i]+1," ");
    ps();
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

void pr(const char *x) { printf("%s", x); }

template<class T, class... Ts> void pr(const T& t, const Ts&... ts) { 
    pr(t); pr(ts...); 
}

void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}