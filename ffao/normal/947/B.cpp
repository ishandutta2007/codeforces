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

void pr(long long x);

void pr(char x);
void pr(const char *x);

template<class T, class... Ts> void pr(const T& t, const Ts&... ts);

void ps();

#ifdef FFDBG

#else
#define dbg(x...) dsfdsfsdfasd
#endif

#define rep(i, a, b) for(int i = a; i < (b); ++i)

int n;

int V[110000];
int T[110000];
long long Tsum[110000];
long long all_snow[110000];
long long add_snow[110000];

void solve()
{
    re(n);
    rep(i,0,n) re(V[i]);
    rep(i,0,n) re(T[i]);

    rep(i,0,n) Tsum[i+1] = Tsum[i] + T[i]; 
    rep(i,0,n) {
        int last_day = (lower_bound(Tsum+1, Tsum+n+1, Tsum[i] + V[i]) - Tsum) - 1;
        all_snow[i]++;
        all_snow[last_day]--;
        add_snow[last_day] += V[i] - (Tsum[last_day] - Tsum[i]);
    }

    rep(i,0,n) {
        if (i>0) all_snow[i] += all_snow[i-1];
        pr(add_snow[i] + all_snow[i]*1ll*T[i],' ');
    }
    ps();
}

int main() {

    solve();
}

// typedef unsigned long long ull;

// template <ull MOD>
// void mult(unsigned int * __restrict__ A, unsigned int * __restrict__ B, unsigned int * __restrict__ C, int Cn, int Am, int Cm)
// {
//     static ull buf[1000];
 
void re(int& x) { scanf("%d", &x); }

void pr(long long x) { printf("%lld", x); }

void pr(char x) { printf("%c", x); }
void pr(const char *x) { printf("%s", x); }

template<class T, class... Ts> void pr(const T& t, const Ts&... ts) { 
    pr(t); pr(ts...); 
}

void ps() { pr("\n"); }

#ifdef FFDBG

#else
#define dbg(x...) dsfdsfsdfasd
#endif