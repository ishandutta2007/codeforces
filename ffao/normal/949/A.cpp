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

void pr(int x);

void pr(char x);
void pr(const char *x);

template<class T> void pr(const std::vector<T> x);
template<class T, class... Ts> void pr(const T& t, const Ts&... ts);

void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);

#ifdef FFDBG

#else
#define dbg(x...) dsfdsfsdfasd
#endif

typedef vector<int> vi;

#define sz(x) (int)(x).size()

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#include <cstring>

char s[210000];

void solve()
{
    scanf("%s", s);
    int n = strlen(s);

    set<int> v[2];
    rep(i,0,n) v[s[i]-'0'].insert(i);

    vector< vi > seqs;

    while (!v[0].empty()) {
        int cur = *v[0].begin();
        vi seq = {cur+1};

        v[0].erase(v[0].begin());
        while (true) {
            auto it1 = v[1].lower_bound(cur);
            if (it1 != v[1].end()) {
                auto it2 = v[0].lower_bound(*it1);
                if (it2 != v[0].end()) {
                    seq.push_back(*it1 + 1);
                    seq.push_back(*it2 + 1);
                    cur = *it2;
                    v[0].erase(it2);
                    v[1].erase(it1);
                    continue;
                }
            }
            break;
        }

        seqs.push_back(seq);
    }

    if (!v[1].empty()) {
        ps(-1);
        return;
    }

    ps(sz(seqs));
    rep(i,0,sz(seqs)) {
        pr(sz(seqs[i])," ");
        ps(seqs[i]);
    }
}

int main() {

    solve();
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
template<class T, class... Ts> void pr(const T& t, const Ts&... ts) { 
    pr(t); pr(ts...); 
}

void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}