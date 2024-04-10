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

void pr(char x);
void pr(const char *x);

template<class T> void pr(const std::vector<T> x);

void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);

#ifdef FFDBG

#else
#define dbg(x...) dsfdsfsdfasd
#endif

template <typename T> std::vector<T> compress (std::vector<T> a) {
    std::vector<int> b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    for (int &x : a) 
        x = int(lower_bound(b.begin(), b.end(), x) - b.begin());
    return a;
}

typedef vector<int> vi;

#define all(v) (v).begin(), (v).end()

#define rep(i, a, b) for(int i = a; i < (b); ++i)

int p[] = {2,3,5,7,11,13,17,19,23,29,31};

int t, n;

void solve()
{
    for (re(t); t; t--) {
        re(n);
        vi a(n); re(a);

        vi ans(n);
        for (int i = 0; i < 11; i++) {
            for (int j = 0; j < n; j++) {
                if (a[j] % p[i] == 0) ans[j] = i;
            }
        }

        ans = compress(ans);
        rep(i,0,n) ans[i] = ans[i]+1;
        ps(*max_element(all(ans)));
        ps(ans);
    }
}

int main() {

    solve();
}

void re(int& x) { scanf("%d", &x); }

template<class T> void re(std::vector<T>& a) { for (int i = 0; i < a.size(); i++) re(a[i]); }

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