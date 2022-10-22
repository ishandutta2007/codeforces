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

const int N = 5007;
set <int> c[N];
V <signed> where[1007][1007];
bool alive[N][N];

signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, m, q;
    cin >> n >> m >> q;

    int ptr = 0, ans = 0;

    FOR (j, m) {
        int i = 0;
                {
                c[ptr].insert(i + j - 1);
                int x = i, y = j;
                int dx = 0, dy = 1;
                while (x < n && y < m) {
                    where[x][y].app(ptr);
                    x += dx; y += dy;
                    swap(dx, dy);
                }
                c[ptr].insert(x + y);                    
                }
                ptr++;
    }

    FOR (i, n) {
        int j = 0;
                {
                c[ptr].insert(i + j - 1);
                int x = i, y = j;
                int dx = 1, dy = 0;
                while (x < n && y < m) {
                    where[x][y].app(ptr);
                    x += dx; y += dy;
                    swap(dx, dy);
                }
                c[ptr].insert(x + y); 
                }
                ptr++;
    }

    int cnt = 0;
    FOR (i, n) {
        FOR (j, m) {
            alive[i][j] = 1;
            cnt++;
        }
    }

    auto get = [&] (int l, int r) {
        int in = r - l - 1;
        return in * (in - 1) / 2;
    };

    FOR (line, ptr) {
        ans += get(*c[line].begin(), *c[line].rbegin());
        //debug(line);
        //debug(*c[line].begin());
        //debug(*c[line].rbegin());
        //debug(get(*c[line].begin(), *c[line].rbegin()));
    }

    debug(ans + cnt);

    FOR (i, q) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        cnt -= alive[x][y];
        if (alive[x][y]) {
            each (line, where[x][y]) {
                c[line].insert(x + y);
                auto p = c[line].find(x + y);
                auto l = prev(p);
                auto r = next(p);
                //debug(*l);
                //debug(*r);
                //debug(*p);
                ans += get(*l, *p);
                ans += get(*p, *r);
                ans -= get(*l, *r);
            }
        }
        else {
            each (line, where[x][y]) {
                auto p = c[line].find(x + y);
                auto l = prev(p);
                auto r = next(p);
                ans -= get(*l, *p);
                ans -= get(*p, *r);
                ans += get(*l, *r);
                c[line].erase(p);
            }
        }
        alive[x][y] ^= 1;
        cnt += alive[x][y];
        cout << ans + cnt << endl;
    }
}