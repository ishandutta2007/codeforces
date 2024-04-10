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

template<class T> void re(std::vector<T>& a);

void pr(int x);

void pr(const char *x);

void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);

#ifdef FFDBG

#else
#define dbg(x...) dsfdsfsdfasd
#endif

typedef vector<int> vi;

#define all(v) (v).begin(), (v).end()
#define sz(x) (int)(x).size()

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#include <chrono>
#include <random>

int t;

vi adj[256];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void answer(int x) {
    ps("!",x+1);
    fflush(stdout);
}

bool query(int x) {
    if (adj[x].empty()) {
        ps("?",x+1);
        fflush(stdout);
        int n; re(n);
        if (n == 0) exit(0);
        adj[x].resize(n); re(adj[x]);
        rep(i,0,sz(adj[x])) adj[x][i]--;
    }

    if (sz(adj[x]) == 2) {
        answer(x);
        return true;
    }
    return false;
}

bool expand(vi& path) {
    if (query(path.back())) return true;;

    while (1) {
        shuffle(all(adj[path.back()]), rng);
        bool found = false;
        for (int x : adj[path.back()]) if (adj[x].empty()) {
            found = true;
            // dbg("found", x, "from", path.back());
            // dbg(adj[path.back()]);
            path.push_back(x);
            if (query(x)) return true;
            break;
        }

        if (!found) break;
    }

    return false;
}

void solve()
{
    for (re(t); t; t--) {
        int h; re(h);
        if (h == 0) exit(0);

        int n = ((1<<h) - 1);
        rep(i,0,n) adj[i].clear();
        
        uniform_int_distribution<int> dist(0,n-1);
        int st = dist(rng);
        vi path = {st};
        
        if (expand(path)) continue;
        reverse(all(path));
        if (expand(path)) continue;

        while (1) {
            int len = sz(path);
            int height = len/2;

            if (height >= h-4) {
                vi otv;
                for (int x : adj[path[height]]) if (adj[x].empty()) {
                    if (query(x)) goto out;
                    otv.push_back(x);
                }

                vi otv2;
                for (int ot : otv) for (int x : adj[ot]) if (adj[x].empty()) {
                    if (query(x)) goto out;
                    otv2.push_back(x);
                }

                int ct = 0;
                for (int ot : otv2) {
                    for (int x : adj[ot]) if (adj[x].empty()) {
                        ct++;
                        if (ct == 4) {
                            answer(x);
                            goto out;
                        }
                        if (query(x)) goto out;
                    }
                }
            }

            path.erase(path.begin()+height+1, path.end());
            if (expand(path)) break;
        }

        out: {}
    }
}

int main() {

    solve();
}

void re(int& x) { scanf("%d", &x); }

template<class T> void re(std::vector<T>& a) { for (int i = 0; i < a.size(); i++) re(a[i]); }

void pr(int x) { printf("%d", x); }

void pr(const char *x) { printf("%s", x); }

void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}