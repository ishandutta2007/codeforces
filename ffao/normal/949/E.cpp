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

#define all(v) (v).begin(), (v).end()
#define sz(x) (int)(x).size()

int n;
vi ans(40,-1);
vi cur;

void go(vi& a, int d) {
    if (d > 20) return;
    if (sz(a) == 1 && a[0] == 0) {
        if (sz(cur) < sz(ans)) ans = cur;
        return;
    }

    vi nt;
    bool need = false;
    for (int x : a) {
        if (x%2 != 0) {
            nt.push_back((x+1)/2);
            need = true;
        }
        else nt.push_back(x/2);
    }
    nt.erase(unique(all(nt)), nt.end());

    if (!need) {
        go(nt,d+1);
        return;
    }

    cur.push_back(-(1<<d));
    go(nt,d+1);
    cur.pop_back();

    nt.clear();
    for (int x : a) {
        if (x%2 != 0) nt.push_back((x-1)/2);
        else nt.push_back(x/2);
    }
    nt.erase(unique(all(nt)), nt.end());

    cur.push_back((1<<d));
    go(nt,d+1);
    cur.pop_back();
}

void solve()
{
    re(n);
    vi a(n); re(a);

    sort(all(a));
    go(a,0);
    ps(sz(ans)); ps(ans);
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