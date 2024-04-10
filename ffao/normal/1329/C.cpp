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

void pr(long long x);

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

int t;
int h, g;

int a[2100000];
long long tot;
vi proc;

int level(int i) {
    return 32 - __builtin_clz(i);
}

int pf(int i) {
    if (a[2*i]==0 && a[2*i+1]==0) return i;
    if (a[2*i] > a[2*i+1]) return pf(2*i);
    else return pf(2*i+1);
}

void f(int i) {
    if (a[2*i] == 0 && a[2*i+1] == 0) {
        a[i] = 0;
    }
    else {
        if (a[2*i] > a[2*i+1]) {
            a[i] = a[2*i];
            f(2*i);
        }
        else {
            a[i] = a[2*i+1];
            f(2*i+1);
        }
    }
}

long long del(int i) {
    if (a[i] == 0) return 0;

    long long ans = 0;
    while (level(pf(i)) > g) {
        ans += a[i];
        proc.push_back(i);
        f(i);
    }

    return ans + del(2*i) + del(2*i+1);
}

void solve()
{
    for (re(t); t; t--) {
        re(h, g);
        tot = 0;

        for (int i = 1; i < (1<<h); i++) {
            re(a[i]);
            tot += a[i];
        }
        for (int i = (1<<h); i <= (1<<(h+1)); i++) a[i] = 0;

        proc.clear();
        ps(tot - del(1));
        ps(proc);
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

void pr(long long x) { printf("%lld", x); }

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