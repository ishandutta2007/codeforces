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
#define debug2(x, y) std::cerr << #x << ", " << #y << ": " << x << ", " << y << '\n';
#define debug3(x, y, z) std::cerr << #x << ", " << #y << ", " << #z << ": " << x << ", " << y << ", " << z << '\n';
#else
#define debug(x)
#define debug2(x, y) 
#define debug3(x, y, z) 
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
signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    vi a(n), b(n);

    vi co;
    FOR (i, n) {
        cin >> a[i] >> b[i];
        co.app(a[i]);
        co.app(b[i]);
    }

    sort(all(co));

    auto pos = [&] (int x, vi &a) { return lower_bound(all(a), x) - a.begin(); };
    V <vi> g(n * 2), G(n * 2);

    FOR (i, n) {
        a[i] = pos(a[i], co);
        b[i] = pos(b[i], co);
        g[a[i]].app(i); g[b[i]].app(i);
        G[a[i]].app(b[i]);
        G[b[i]].app(a[i]);
    }

    int V, E;
    vi used(2 * n);
    function <void (int)> dfs = [&] (int u) {
        //debug2(u, G[u].size());
        used[u] = 1;
        E += G[u].size();
        V++;
        each (v, G[u]) {
            if (!used[v]) {
                dfs(v);
            }
        }
    };

    auto can = [&] (int t) {
        queue <int> q;
        vi us(2 * n);
        vi when(n, -1);
        FOR (i, n) {
            if (co[a[i]] > t) {
                return false;
            }
            if (co[b[i]] > t) {
                if (us[a[i]]) {
                    return false;
                }
                us[a[i]] = 1;
                when[i] = a[i];
                q.push(i);
            }
        }
        while (q.size()) {
            int e = q.front(); q.pop();
            each (v, g[when[e]]) {
                if (when[v] == -1) {
                    if (!us[a[v]]) {
                        us[a[v]] = 1;
                        when[v] = a[v];
                        q.push(v);
                    }
                    else if (!us[b[v]]) {
                        us[b[v]] = 1;
                        when[v] = b[v];
                        q.push(v);
                    }
                    else {
                        return false;
                    }
                }
            }
        }

        return true;
    };



        FOR (e, 2 * n) {
            if (G[e].size() && !used[e]) {
                E = 0; V = 0;
                dfs(e);
                assert(E%2==0);
                if (V < E/2) {
                    cout << -1 << endl;
                    exit(0);
                }
            }
        }

    int l = 0, r = 1e9+7;
    while (l < r - 1) {
        int m = (l + r) / 2;
        if (can(m)) {
            r = m;
        }
        else {
            l = m;
        }
    }
    cout << r << endl;
}