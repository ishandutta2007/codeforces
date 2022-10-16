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

#define all(v) (v).begin(), (v).end()

int t;
char s[210000];
int n,k;

void solve()
{
    for (re(t); t; t--) {
        re(n,k);
        scanf("%s", s);

        int ans = 0;

        for (int i = 0; k-1-i >= i; i++) {
            int tot = 0;
            vi cnts(26,0);

            for (int j = i; j < n; j += k) {
                tot++;
                cnts[s[j]-'a']++;
            }

            if (k-1-i != i) {
                for (int j = k-1-i; j < n; j += k) {
                    tot++;
                    cnts[s[j]-'a']++;
                }
            }

            ans += tot - *max_element(all(cnts));
        }

        ps(ans);
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