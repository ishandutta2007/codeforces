#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <fstream>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define x first
#define y second
#define Time (double)clock()/CLOCKS_PER_SEC
#define debug(x) std::cerr << #x << ": " << x << '\n';
#define FOR(i, n) for (int i = 0; i < n; ++i)
#define pb push_back
#define trav(a, x) for (auto& a : x)
using vi = vector<int>;
template <typename T>
std::ostream& operator <<(std::ostream& output, const pair <T, T> & data)
{
    output << "(" << data.x << "," << data.y << ")";
    return output;
}
template <typename T>
std::ostream& operator <<(std::ostream& output, const std::vector<T>& data)
{
    for (const T& x : data)
        output << x << " ";
    return output;
}
ll div_up(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll div_down(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down 
ll math_mod(ll a, ll b) { return a - b * div_down(a, b); }
#define tcT template<class T
#define tcTU tcT, class U
tcT> using V = vector<T>; 
tcT> void re(V<T>& x) { 
    trav(a, x)
        cin >> a;
}
tcT> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; 
} // set a = min(a,b)
tcT> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; 
}
ll gcd(ll a, ll b) {
    while (b) {
        tie(a, b) = mp(b, a % b);
    }
    return a;
}
signed main() {
    #ifdef ONLINE_JUDGE
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    vi c(n + 1), pos(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
        pos[c[i]] = i;
    }
    vi used(n + 1);
    V <vi> d;
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            int u = i;
            vi cyc;
            while (!used[u]) {
                used[u] = 1;
                cyc.app(c[u]);
                u = c[u];
            }
            d.app(cyc);
        }
    }

    V <ii> ans;
    vi cur(n + 1);
    auto flip = [&] (int x, int y) {
        //debug("flip");
        //debug(mp(x, y));
        ans.app(mp(pos[x], pos[y]));
        swap(c[pos[x]], c[pos[y]]);
        swap(pos[x], pos[y]);
        cur[x] ^= 1;
        cur[y] ^= 1;
    };

    for (int i = 0; i + 1 < d.size(); i += 2) {
        flip(d[i][0], d[i + 1][0]);
    }
    int sz = d.size();
    if (sz % 2 && sz > 1) {
        flip(d[sz - 2][0], d[sz - 1][0]);
    }

    used.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        if (!used[i] && c[i] != i) {
            int u = i;
            vi cyc;
            while (!used[u]) {
                used[u] = 1;
                cyc.app(c[u]);
                u = c[u];
            }
            vi who;
            trav (e, cyc) {
                if (cur[e])
                    who.app(e);
            }
            if (who.empty()) {
                flip(cyc[1], cyc[2]);
                flip(cyc[1], cyc[0]);
            }
        }
    }

    //debug(ans);

    used.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        if (!used[i] && c[i] != i) {
            int u = i;
            vi cyc;
            while (!used[u]) {
                used[u] = 1;
                cyc.app(c[u]);
                u = c[u];
            }
            vi who;
            trav (e, cyc) {
                if (cur[e])
                    who.app(e);
            }
            assert(who.size() == 2);
            int l = who[0];
            while (c[l] != who[1]) {
                int nxt = c[l];
                flip(l, c[l]);
                l = nxt;
            }
            int r = who[1];
            while (c[r] != l) {
                int nxt = c[r];
                flip(r, c[r]);
                r = nxt;
            }
            flip(l, r);
        }
    }

    assert(ans.size() <= n + 1);
    cout << ans.size() << endl;
    trav (e, ans)
        cout << e.x << ' ' << e.y << endl;

    //debug(c);
    //debug(cur);
}