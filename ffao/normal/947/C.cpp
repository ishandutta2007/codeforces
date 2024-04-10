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

void pr(int x);

void pr(const char *x);

template<class T, class... Ts> void pr(const T& t, const Ts&... ts);

void ps();

#ifdef FFDBG

#else
#define dbg(x...) dsfdsfsdfasd
#endif

#define rep(i, a, b) for(int i = a; i < (b); ++i)

int n;
int A[310000];
int P[310000];

struct node {
    int nxt[2];
    int tam;
};

node tree[9010000];
int tam = 1;

void add(int n) {
    int cur = 0;
    tree[cur].tam++;

    for (int j = 29; j >= 0; j--) {
        int follow = ((n>>j) & 1);
        if (tree[cur].nxt[follow] == 0) tree[cur].nxt[follow] = tam++;
        cur = tree[cur].nxt[follow];
        tree[cur].tam++;
    }
}

int pop(int n) {
    int cur = 0;
    tree[cur].tam--;

    int ret = 0;
    for (int j = 29; j >= 0; j--) {
        int follow = ((n>>j) & 1);
        if (tree[cur].nxt[follow] == 0 || tree[tree[cur].nxt[follow]].tam == 0) follow ^= 1;

        cur = tree[cur].nxt[follow];
        tree[cur].tam--;
        ret |= follow*(1<<j);
    }
    return ret;
}

void solve()
{
    re(n);
    rep(i,0,n) re(A[i]);
    rep(i,0,n) {
        re(P[i]);
        add(P[i]);
    }

    rep(i,0,n) pr(A[i] ^ pop(A[i])," ");
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

void pr(int x) { printf("%d", x); }

void pr(const char *x) { printf("%s", x); }

template<class T, class... Ts> void pr(const T& t, const Ts&... ts) { 
    pr(t); pr(ts...); 
}

void ps() { pr("\n"); }

#ifdef FFDBG

#else
#define dbg(x...) dsfdsfsdfasd
#endif