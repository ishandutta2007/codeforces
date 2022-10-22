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
V <ii> v = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int solve(V <vi> a, V <vi> b) {
    int n = a[0].size();
    auto in = [&] (int i, int j) { return 0 <= i && i < 2 && 0 <= j && j < n; };
    queue <V <vi> > q;
    q.push(a);
    map <V <vi>,int > d;
    d[a] = 0;
    while (q.size()) {
        auto u = q.front(); q.pop();
        FOR (x, 2) {
            FOR (y, n) {
                each (e, v) {
                    int i = x + e.x, j = y + e.y;
                    if (in(i, j)) {
                        auto v = u;
                        swap(v[i][j], v[x][y]);
                        if (d.find(v) == d.end()) {
                            d[v] = d[u] + 1;
                            q.push(v);
                        }
                    }
                }
            }
        }
    }
    if (d.find(b) == d.end()) {
        return -1;
    }
    else {
        return d[b];
    }
}

int smart(V <vi> a, V <vi> b) {
    int n = a[0].size();

    int sum = 0;
    FOR (i, 2) FOR (j, n) sum += a[i][j] - b[i][j];
    if (sum) return -1;
    /*
    int ans = 0;
    while (a != b) {
        int d = 1e9, oi, oj, ox, oy;
        FOR (i, 2) {
            FOR (j, n) {
                if (a[i][j] != b[i][j]) {
                    FOR (x, 2) {
                        FOR (y, n) {
                            if (a[x][y] != b[x][y]) {
                                if (a[i][j] != a[x][y]) {
                                    if (ckmin(d, abs(i - x) + abs(j - y))) {
                                        oi = i, oj = j, ox = x, oy = y;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }    
        swap(a[oi][oj], a[ox][oy]);
        ans += d;
    }
    return ans;
    */

    int t = 0, c = 0, u = 0, ans = 0;
    FOR (i, n) {
        if ((a[0][i] ^ b[0][i]) && (a[1][i] ^ b[1][i])) {
            if (a[0][i] == a[1][i]) {
                if (a[0][i] == t) {
                    c += 2;
                    u++;
                }
                else {

                    if (c == 0) {
                        c = 2;
                        t = a[0][i];
                        u = 1;
                    }
                    else if (c == 1) {
                        c = 1;
                        t = a[0][i];
                        u ^= 1;
                    }
                    else if (u == 0) {
                        c -= 2;
                        ans++;
                    }
                    else if (u == c) {
                        c -= 2;
                        u -= 2;
                        ans++;
                    }
                    else {
                        c -= 2;
                        u--;
                    }
                }
            }
            else {
                if (c == 0) {
                    ans++;
                }
                else {
                    int w = a[0][i] == t;
                    vi h(2);
                    h[0] = !!u;
                    h[1] = u < c;
                    if (!h[w]) {
                        ans++;
                    }
                    else {
                        if (w == 0) {
                            u--;
                        }
                        else {
                            u++;
                        }
                    }
                }
            }         
        }
        else if (a[0][i] ^ b[0][i]) {
            if (c == 0) {
                t = a[0][i];
                c = 1;
                u = 1;
            }
            else if (a[0][i] == t) {
                t = a[0][i];
                c++;
                u++;
            }
            else {

                int w = 0;
                    vi h(2);
                    h[0] = !!u;
                    h[1] = u < c;
                    c--;
                    if (!h[w]) {
                        ans++;
                    }
                    else {
                        if (w == 0) {
                            u--;
                        }
                    }
            }
        }
        else if (a[1][i] ^ b[1][i]) {
            if (c == 0) {
                t = a[1][i];
                c = 1;
                u = 0;
            }
            else if (a[1][i] == t) {
                c++;
            }
            else {
                int w = 1;
                vi h(2);
                h[0] = !!u;
                h[1] = u < c;
                c--;
                if (!h[w]) {
                    ans++;
                    u--;
                }
                else {
                    if (w == 0) {
                        u--;
                    }
                }
            }
        }
        else {

        }
        debug(i);
        debug(mp(t, c));
        debug(u);
        debug(ans);
        //cout << endl;
            ans += c;
    }
    return ans;
}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    auto get = [&] (int l, int r) {
        int len = r - l + 1;
        return l + (ll)(rng()%len);
    };
    /*
    V <vi> a = {{1, 1, 0}, {0, 1, 0}};
    V <vi> b = {{1, 0, 1}, {1, 0, 0}};

    cout << solve(a, b) << endl;
    cout << smart(a, b) << endl;
    exit(0);
    */

    /*
    V <vi> a = {{0, 0, 0, 1, 1}, {0, 1, 1, 0, 1}};
    V <vi> b = {{1, 1, 0, 1, 0}, {1, 0, 0, 1, 0}};

    cout << solve(a, b) << endl;
    cout << smart(a, b) << endl;
    exit(0);
    */


    int n;
    cin >> n;
    V <vi> a(2, vi(n)), b(2, vi(n));
    cin >> a >> b;
    cout << smart(a, b) << endl;
    exit(0);
    

    //cout << smart(a, b) << endl;


    rep (100000) {

        int n = get(1, 8);
    V <vi> a(2, vi(n)), b(2, vi(n));
        FOR (i, 2) {
            FOR (j, n) {
                a[i][j] = get(0, 1);
                b[i][j] = get(0, 1);
            }
        }

        if (solve(a, b) != smart(a, b)) {
            cout << a << endl;
            cout << b << endl;
            exit(0);
        }

        debug(_);
    }


}