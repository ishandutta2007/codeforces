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
void re(long long& x);

template<class T, class... Ts> void re(T& t, Ts&... ts);

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
long long k;

long long get_diff(long long a, long long b) {
    return a - (3*b*b + 3*b + 1);
}

long long check(vi& a, long long bound, vi &b) {
    long long ret = 0;

    for (int i = 0; i < n; i++) {
        int st = 0, ed = a[i];
        while (st < ed) {
            int md = (st+ed+1)/2;
            if (get_diff(a[i], md-1) >= bound) st = md;
            else ed = md-1;
        }
        b[i] = st;
        ret += st;
    }

    return ret;
}

void solve()
{
    re(n,k);

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) re(a[i]);

    long long st = -4e18, ed = 1e9 + 10;
    while (st < ed) {
        long long md = (st+ed+1)/2;
        if (check(a, md, b) >= k) st = md;
        else ed = md-1;
    }

    k -= check(a, st+1, b);
    for (int i = 0; i < n && k; i++) {
        if (b[i] < a[i] && get_diff(a[i],b[i]) == st) {
            k--;
            b[i]++;
        }
    }
    
    ps(b);
}

int main() {

    solve();
}

void re(int& x) { scanf("%d", &x); }
void re(long long& x) { scanf("%lld", &x); }

template<class T, class... Ts> void re(T& t, Ts&... ts) { 
    re(t); re(ts...); 
}

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