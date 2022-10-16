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

void pr(int x);

void pr(const char *x);

void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);

#ifdef FFDBG

#else
#define dbg(x...) dsfdsfsdfasd
#endif

#define rep(i, a, b) for(int i = a; i < (b); ++i)

int n;
multiset<int> els[30];
long long s[30];

void solve()
{
    re(n);

    int eels = 0;

    rep(i,0,n) {
        char op; scanf(" %c", &op);
        int k; re(k);

        int log;
        for (log = 0; (1<<(log+1)) <= k; log++);
        
        if (op == '+') {
            els[log].insert(k);
            s[log]+=k;
            eels++;
        }
        else {
            els[log].erase(els[log].find(k));
            s[log]-=k;
            eels--;
        }

        int ans = 0;
        long long curs = 0;
        for (log = 0; log < 30; log++) {
            if (!els[log].empty()) {
                int f = *els[log].begin();
                // dbg(f,curs);
                if (curs*2 < f) ans++;
            }

            curs += s[log];
        }

        // dbg(ans);
        ps(eels-ans);
    }
}

int main() {

    solve();
}

void re(int& x) { scanf("%d", &x); }

void pr(int x) { printf("%d", x); }

void pr(const char *x) { printf("%s", x); }

void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}