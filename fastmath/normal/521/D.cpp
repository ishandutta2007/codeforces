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
V <ii> d[N][4];
vi out[N][4];
int type[N];

signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int k, op, m;
    cin >> k >> op >> m;

    vi a(k + 1);
    FORN (i, k) {
        cin >> a[i];
    }

    FORN (i, op) {
        int num, x;
        cin >> type[i] >> num >> x;
        if (type[i] == 3 && x == 1) {
            continue;
        }
        d[num][type[i]].app(mp(x, i));
    }

    V <vi> cand; // (a, b, who, op)
    FORN (who, k) {
        int sz = 0;
        FORN (t, 3) {
            sort(all(d[who][t]));
            reverse(all(d[who][t]));
        }
        each (e, d[who][3]) {
            cand.app({e.x, 1, who, e.y});
        }
        if (d[who][1].size() && d[who][1][0].x > a[who]) {
            d[who][2].app(mp(d[who][1][0].x - a[who], d[who][1][0].y));
        }
        int cur = a[who];
        each (e, d[who][2]) {
            cand.app({cur + e.x, cur, who, e.y});
            cur += e.x;
        }
    }
    auto comp = [&] (vi a, vi b) {
        return (__int128)a[0] * b[1] > (__int128)b[0] * a[1];
    };
    sort(all(cand), comp);

    cout << min(m, (int)cand.size()) << endl;

    FOR (i, min(m, (int)cand.size())) {
        out[cand[i][2]][type[cand[i][3]]].app(cand[i][3]);
    }

    FORN (who, k) {
        FORN (t, 3) {
            each (e, out[who][t]) {
                cout << e << ' ';
            }
        }
    }
    cout << endl;
}