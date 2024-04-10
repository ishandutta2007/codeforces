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

int n,d,b;

bool check(vi a, int md) {
    int fl = 0;
    
    for (int i = md; i < (n+1)/2; i++) {
        int nd = b;
        while (nd && fl < n) {
            if (abs(fl - i) <= (i+1) * 1ll * d) {
                if (a[fl] >= nd) {
                    a[fl] -= nd;
                    nd = 0;
                    break;
                }
                else {
                    nd -= a[fl];
                    a[fl] = 0;
                }
            }
            fl++;
        }

        // if (md == 1) dbg(i,nd);
        if (nd) return false;
    }

    fl = n-1;
    for (int i = n-1-md; i >= (n+1)/2; i--) {
        int nd = b;
        while (nd && fl >= 0) {
            if (abs(fl - i) <= (n-i) * 1ll * d) {
                if (a[fl] >= nd) {
                    a[fl] -= nd;
                    nd = 0;
                    break;
                }
                else {
                    nd -= a[fl];
                    a[fl] = 0;
                }
            }
            fl--;
        }

        // if (md == 1) dbg(i,nd);
        if (nd) return false;
    }

    return true;
}

void solve()
{
    re(n,d,b);
    vi a(n); re(a);

    int st = 0, ed = n/2;
    while (st < ed) {
        int md = (st+ed)/2;
        if (check(a, md)) ed = md;
        else st = md+1;
    }

    ps(st); 
}

int main() {

    solve();
}

void re(int& x) { scanf("%d", &x); }

template<class T, class... Ts> void re(T& t, Ts&... ts) { 
    re(t); re(ts...); 
}
template<class T> void re(std::vector<T>& a) { for (int i = 0; i < a.size(); i++) re(a[i]); }

void pr(int x) { printf("%d", x); }

void pr(const char *x) { printf("%s", x); }

void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}