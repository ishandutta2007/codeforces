#include <iostream>
#include <bitset>
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

void pr(const char *x);

void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);

#ifdef FFDBG

#else
#define dbg(x...) dsfdsfsdfasd
#endif

#define sz(x) (int)(x).size()

#define rep(i, a, b) for(int i = a; i < (b); ++i)

string s[210];
bitset<2048> has[210][13];
int n, q;

void solve()
{
    cin >> n;
    rep(i,0,n) cin >> s[i];

    rep(i,0,n) {
        rep(k,0,10) {
            rep(j,0,sz(s[i])-k) {
                int th = 0;
                rep(p,j,j+k+1) th += (1<<(p-j))*(s[i][p]-'0');
                has[i][k][th] = 1;
                // if (k == 3) dbg(j,th);
            }
        }
    }
    // dbg((int)has[0][3].count());

    int cur = n;
    for (cin >> q; q; q--) {
        int a, b;
        cin >> a >> b; a--; b--;

        rep(k,0,10) has[cur][k] = has[a][k] | has[b][k];

        string ae, be = s[b].substr(0,10);
        if (sz(s[a]) >= 10) ae = s[a].substr(sz(s[a])-10,10);
        else ae = s[a];

        string mid = ae+be;
        
        rep(k,0,10) {
            rep(j,0,sz(mid)-k) {
                int th = 0;
                rep(p,j,j+k+1) th += (1<<(p-j))*(mid[p]-'0');
                has[cur][k][th] = 1;
            }
        }

        s[cur] = s[a] + s[b];
        // dbg(s[cur]);
        if (sz(s[cur]) >= 20) {
            s[cur] = s[cur].substr(0,10) + s[cur].substr(sz(s[cur])-10,10);
        }

        //dbg(s[cur]);

        int best = -1;
        rep(k,0,10) if ((int)has[cur][k].count() == (1<<(k+1))) best = k;

        ps(best+1);
        cur++;
    }
}

int main() {

    solve();
}

void pr(int x) { printf("%d", x); }

void pr(const char *x) { printf("%s", x); }

void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}