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
signed main() {
    #ifdef LOCAL
    #else
    #endif
    int m, k;
    cin >> m >> k;
    V <vi> a(k, vi(m));
    cin >> a;

    vi sum(k), sum2(k);
    FOR (i, k) {
        each (e, a[i]) {
            sum[i] += e;
            sum2[i] += e * e;
        }
    }

    vi dif(k - 1);
    FOR (i, k - 1) {
        dif[i] = sum[i + 1] - sum[i];
    }

    map <int, int> cnt;
    each (e, dif) {
        cnt[e]++;
    }

    int V = -1;
    each (e, cnt) {
        if (e.y > 2) {
            V = e.x;
        }
    }
    assert(V != -1);

    int wrong = -1;
    FOR (i, k) {
        if (sum[i] != sum[0] + V * i) {
            wrong = i;
            break;
        }
    }
    assert(wrong != -1);

    int V2 = -1;
    FOR (i, k - 2) {
        if (i != wrong && i + 1 != wrong && i + 2 != wrong) {
            int A = sum2[i + 1] - sum2[i];
            int B = sum2[i + 2] - sum2[i];
            V2 = (B - 2 * A)/2;
        }
    }
    assert(V2 != -1);

    assert(wrong != 0);
    int want_sum = sum[0] + V * wrong;

    /*
    debug(V);
    debug(V2);

    debug(sum[wrong]);
    debug(sum2[wrong]);
    debug(want_sum);
    */

    cout << wrong << ' ';
    each (e, a[wrong]) {
        int was = e + want_sum - sum[wrong];

        int t = sum2[wrong] - e * e + was * was;
        int A = t - sum2[wrong - 1];
        int B = sum2[wrong + 1] - sum2[wrong - 1];
        int get = (B - 2 * A)/2;

        if (get == V2) {
            cout << was << endl;
            exit(0);
        }
    }
    assert(0);
}