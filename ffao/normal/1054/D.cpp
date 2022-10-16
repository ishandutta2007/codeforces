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

void pr(long long x);

void pr(const char *x);

void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);

#ifdef FFDBG

#else
#define dbg(x...) dsfdsfsdfasd
#endif

typedef vector<int> vi;

int n, k;

int flip(int x, int k) {
    return x ^ ((1<<k)-1);
}

void solve()
{
    map<int, int> mp;

    re(n,k);
    vi a(n); re(a);

    mp[0] = 1;

    int x = 0;
    for (int i = 0; i < n; i++) {
        x ^= a[i];
        
        mp[min(x, flip(x, k))]++;
    }

    long long con = 0;
    for (auto p : mp) {
        long long f = p.second / 2;
        long long s = p.second - f;

        con += (f * (f-1) + s * (s-1)) / 2;
    }

    long long tot = n * 1ll * (n+1) / 2;
    ps(tot - con);
}

int main() {

    solve();
}

void re(int& x) { scanf("%d", &x); }

template<class T, class... Ts> void re(T& t, Ts&... ts) { 
    re(t); re(ts...); 
}
template<class T> void re(std::vector<T>& a) { for (int i = 0; i < a.size(); i++) re(a[i]); }

void pr(long long x) { printf("%lld", x); }

void pr(const char *x) { printf("%s", x); }

void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}