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

void pr(int x);

void pr(const char *x);

void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);

#ifdef FFDBG

#else
#define dbg(x...) dsfdsfsdfasd
#endif

#define all(v) (v).begin(), (v).end()

vector<int> seq[10];
int g[1100000];

void solve()
{
    for (int i = 1; i < 10; i++) {
        g[i] = i;
        seq[i].push_back(i);
    }

    for (int i = 10; i <= 1000000; i++) {
        int num = i;
        int p = 1;
        while (num) {
            if (num%10) p *= (num%10);
            num/=10;
        }
        g[i] = g[p];
        seq[g[i]].push_back(i);
    }

    int q;
    for (re(q); q; q--) {
        int l,r,k;
        re(l,r,k);

        int ur = upper_bound(all(seq[k]),r) - seq[k].begin();
        int lr = lower_bound(all(seq[k]),l) - seq[k].begin();
        ps(ur-lr);
    }
}

int main() {

    solve();
}

void re(int& x) { scanf("%d", &x); }

template<class T, class... Ts> void re(T& t, Ts&... ts) { 
    re(t); re(ts...); 
}

void pr(int x) { printf("%d", x); }

void pr(const char *x) { printf("%s", x); }

void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}