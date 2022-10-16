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

typedef vector<int> vi;

#define sz(x) (int)(x).size()

#define rep(i, a, b) for(int i = a; i < (b); ++i)

int n,k;
char c;

void reset() {
    ps("R");
    fflush(stdout);
}

bool query(int x) {
    ps("?", x+1);
    fflush(stdout);
    scanf(" %c", &c);
    return c == 'Y';
}

void solve()
{
    re(n,k);

    queue<vi> blocks;
    for (int i = 0; i < n; i += k) {
        reset();

        vi block;
        for (int j = i; j < i+k; j++) {
            if (!query(j)) block.push_back(j);
        }

        blocks.push(block);
    }

    while (sz(blocks) > 1) {
        vi b = blocks.front();
        blocks.pop();
        vi c = blocks.front();
        blocks.pop();
        
        vi ok(sz(c), 1);

        for (int cbl = 0; cbl < sz(c); cbl += k) {
            for (int bbl = 0; bbl < sz(b); bbl += k) {
                reset();
                for (int bi = bbl; bi < sz(b) && bi < bbl+k; bi++) query(b[bi]);
                for (int ci = cbl; ci < sz(c) && ci < cbl+k; ci++) ok[ci] &= !query(c[ci]);

                reset();
                for (int bi = min(bbl+k,sz(b))-1; bi >= bbl; bi--) query(b[bi]);
                for (int ci = min(cbl+k,sz(c))-1; ci >= cbl; ci--) ok[ci] &= !query(c[ci]);
            }
        }
        
        rep(ci,0,sz(c)) if (ok[ci]) b.push_back(c[ci]);
        blocks.push(b);
    }

    ps("!", sz(blocks.front()));
    fflush(stdout);
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