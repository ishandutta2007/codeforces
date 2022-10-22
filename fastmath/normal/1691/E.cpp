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
#include <array>
#include <functional>
#include <stack>
#include <memory>
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

#ifdef LOCAL
#define debug(x) std::cerr << #x << ": " << x << '\n';
#else
#define debug(x)
#endif

#define FORI(i,a,b) for (int i = (a); i < (b); ++i)
#define FOR(i,a) FORI(i,0,a)
#define ROFI(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define ROF(i,a) ROFI(i,0,a)
#define rep(a) FOR(_,a)
#define each(a,x) for (auto& a: x)
#define FORN(i, n) FORI(i, 1, n + 1)

using vi = vector<int>;
template <typename T>
std::istream& operator >>(std::istream& input, std::pair <T, T> & data)
{
    input >> data.x >> data.y;
    return input;
}
template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& data)
{
    for (T& x : data)
        input >> x;
    return input;
}
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
std::ostream& operator <<(std::ostream& output, const __int128 &x)
{
    __int128 n = x;
    if (n == 0) {
        output << "0";
        return output;
    }
    if (n < 0) {
        n = -n;
        output << "-";
    }
    string s;
    while (n) {
        s += '0' + (n%10);
        n /= 10;
    }
    reverse(all(s));
    cout << s;
    return output;
}
ll div_up(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll div_down(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down 
ll math_mod(ll a, ll b) { return a - b * div_down(a, b); }
#define tcT template<class T
#define tcTU tcT, class U
tcT> using V = vector<T>; 
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
int Bit(int mask, int bit) { return (mask >> bit) & 1; }

struct Dsu {
int n;
vector <int> par, cnt;
Dsu (int n_) {
    n = n_;
    par.resize(n + 1);
    cnt.resize(n + 1, 1);
    FOR (i, n + 1)
        par[i] = i;
}   
int root(int u) {
    if (par[u] == u)
        return u;
    else
        return par[u] = root(par[u]);                
}   
int get_cnt(int u) {
    return cnt[root(u)];
}   
bool merge(int u, int v) {
    u = root(u);
    v = root(v);
    if (u == v)
        return 0;
    par[u] = v;
    cnt[v] += cnt[u];
    return 1;
}
bool connected(int u, int v) {
    return root(u) == root(v);
}   
};  


signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    auto solve = [&] () {
        int n;
        cin >> n;

        Dsu d(n);

        vi cnt(2);
        V <vi> x(2);
        V <array <int, 3> > e;

        V <vi> a;
        FOR (i, n) {
            int l,r,c;
            cin >> c >> l >> r;
            a.app({l, r, c});
            x[c].app(l); 
            x[c].app(r);
            cnt[c]++;
            e.app({l, 1, i});
            e.app({r, 2, i});
        }
        FOR (t, 2) sort(all(x[t]));

        sort(all(e));

        debug("tak");

        V <set <ii> > op(2);
        each (e, e) {
            int i = e[2];
            if (e[1] == 1) {
                op[a[i][2]].insert(mp(a[i][1], i));
            }
            else {
                op[a[i][2]].erase(mp(a[i][1], i));
            }

            if (op[0].size() && op[1].size()) {
                FOR (t, 2) {
                    while (op[t].size() > 1) {
                        int l = op[t].begin()->second;
                        op[t].erase(op[t].begin());
                        d.merge(l, op[t].begin()->second);
                    }
                }
                d.merge(op[0].begin()->second, op[1].begin()->second);
            }

        }

        int ans = 0;
        set <int> dif;
        FOR (i, n) {
            //debug(d.root(i));
            ans += d.root(i) == i;
        }
        cout << ans << endl;
        return;

        V <ii> byl, byr;
        FOR (i,n) {
            if (a[i][2] == 0) {
                byl.app(mp(a[i][0], a[i][1]));
                byr.app(mp(a[i][1], a[i][0]));
            }
        }
        sort(all(byl));
        int sz = byl.size();
        vi prefmax(sz + 1, -1);
        FOR (i, sz) {
            prefmax[i + 1] = max(prefmax[i], byl[i].y);
        }

        sort(all(byr));
        vi sufmin(sz + 1, 2e9);
        ROF (i, sz) {
            sufmin[i] = min(sufmin[i + 1], byr[i].y);
        }


        FOR (i, n) {
            if (a[i][2] == 1) {
                bool nonint = 1;
                int l = a[i][0], r = a[i][1];
                auto t = lower_bound(all(byl), mp(r + 1, -1ll));
                int p = t - byl.begin() - 1;
                nonint &= prefmax[p + 1] < l;

                {
                auto t = lower_bound(all(byr), mp(l, -1ll));
                int p = t - byr.begin();
                nonint &= sufmin[p] > r;
                }

                if (nonint) {
                    debug(i);
                    ans++;
                }
            }
        }
        cout << ans << endl;
    };
    int t;
    cin >> t;
    rep (t) {
        solve();
    }
}