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

const int N = 1e5+7;
int tree[N << 2][32]; // (a, b, c, ab, bc)
int mer[32][32];

void relax(int v) {
    FOR (i, 32) {
        tree[v][i] = N;
    }
    FOR (L, 32) {
        if (tree[v * 2 + 1][L] == N) continue;
        FOR (R, 32) {
            if (tree[v * 2 + 2][R] == N) continue;
            if (mer[L][R] != -1) ckmin(tree[v][mer[L][R]], tree[v * 2 + 1][L] + tree[v * 2 + 2][R]);
        }
    }
}

void build(int v, int l, int r, string &s) {
    if (l == r) {
        FOR (ty, 32) {
            tree[v][ty] = N;
        }
        int t = s[l] - 'a';
        FOR (go, 3) {
            tree[v][1 << go] = t != go;
        }
        return;
    }
    int m = (l + r) / 2;
    build(v * 2 + 1, l, m, s);
    build(v * 2 + 2, m + 1, r, s);
    relax(v);
}

void put(int v, int l, int r, int i, int t) {
    if (l == r) {
        FOR (ty, 32) {
            tree[v][ty] = N;
        }
        FOR (go, 3) {
            tree[v][1 << go] = t != go;
        }
        return;
    }
    int m = (l + r) / 2;
    if (i <= m) put(v * 2 + 1, l, m, i, t);
    else put(v * 2 + 2, m + 1, r, i, t);
    relax(v);
}

signed main() {
    #ifdef LOCAL
    //freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    FOR (L, 32) {
        FOR (R, 32) {
            FOR (i, 5) {
                if (Bit(L, i) || Bit(R, i)) {
                    mer[L][R] |= 1 << i;
                }
            }
            if (Bit(L, 0) && Bit(R, 1)) {
                mer[L][R] |= 1 << 3;
            }
            if (Bit(L, 1) && Bit(R, 2)) {
                mer[L][R] |= 1 << 4;
            }

            if (Bit(L, 0) && Bit(R, 4)) {
                mer[L][R] = -1;
            }
            if (Bit(L, 3) && Bit(R, 2)) {
                mer[L][R] = -1;
            }

            //cout << L << ' ' << R << ' ' << mer[L][R] << endl;
        }
    }
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    build(0, 0, n - 1, s);
    rep (q) {
        int p;
        cin >> p;
        char c; cin >> c;
        put(0, 0, n - 1, p - 1, c - 'a');

        /*
        FOR (i, 32) {
            cout << tree[0][i] << ' ';
        }
        cout << endl;
        */

        int ans = N;
        FOR (i, 32) {
            ckmin(ans, tree[0][i]);
        }
        cout << ans << endl;
    }

    debug(Time);
}