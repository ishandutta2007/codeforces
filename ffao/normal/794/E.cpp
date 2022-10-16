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

typedef vector<int> vi;

int n;

void solve()
{
    re(n);
    vi a(n); re(a);

    vi ans(n);

    if (n % 2 == 1) {
        int bst = -1;
        for (int i = 0, j = 0; i < n; i+=2, j++) {
            bst = max(bst, a[n/2+j]);
            bst = max(bst, a[n/2-j]);
            ans[i] = bst;
        }

        bst = -1;
        for (int i = 1, j = 0; i < n; i+=2, j++) {
            bst = max(bst, min(a[n/2-j-1], a[n/2-j]));
            bst = max(bst, min(a[n/2+j], a[n/2+j+1]));
            ans[i] = bst;
        }
    }
    else {
        int bst = -1;
        for (int i = 1, j = 0; i < n; i+=2, j++) {
            bst = max(bst, a[n/2+j]);
            bst = max(bst, a[n/2-j-1]);
            ans[i] = bst;
        }

        bst = -1;
        for (int i = 0, j = 0; i < n; i+=2, j++) {
            bst = max(bst, min(a[n/2-j-1], a[n/2-j]));
            bst = max(bst, min(a[n/2+j-1], a[n/2+j]));
            ans[i] = bst;
        }
    }

    ans.push_back(ans.back());
    ans.erase(ans.begin());
    ps(ans);
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