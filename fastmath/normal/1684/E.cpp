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

struct Fen {
int n, lg = 0;
vi f;
Fen (int n_) {

    n = 1;
    while (n < n_) {
        n <<= 1;
        lg++;
    }

    f.assign(n, 0);
}  
void add(int i, int x) {
    for (; i < n; i |= i + 1) {
        f[i] += x;
    }
}
int get(int k) {
    int i = 0;
    for (int bit = lg - 1; bit >= 0; --bit) {
        int b = f[i + (1 << bit) - 1];
        if (b < k) {
            k -= b;
            i += 1 << bit;
        }
    }
    return i;
}  
};

struct FenCnt {
int n;
vi f;
FenCnt (int n_) {
    n = n_;
    f.assign(n, 0);
}  
void add(int i, int x) {
    for (; i < n; i |= i + 1) 
        f[i] += x;
}   
int get(int i) {
    ckmin(i, n - 1);
    int ans = 0;
    for (; i >= 0; i &= i + 1, --i) ans += f[i];
    return ans;
}     
};

signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    /*
    Fen f(10);
    f.add(1, 1);
    f.add(4, 1);
    cout << f.get(0) << ' ' << f.get(1) << ' ' << f.get(2) << ' ' << f.get(3) << endl;
    exit(0);
    */

    int t;
    cin >> t;
    auto solve = [&] () {
        int n, k;
        cin >> n >> k;

        vi a(n);
        cin >> a;

        map <int, int> c;
        each (x, a) c[x]++;

        V <ii> v;
        each (e, c) v.app(mp(e.y, e.x));
        sort(all(v));
        map <int, int> num;
        FOR (i, v.size()) num[v[i].y] = i;

        FenCnt cnt(n);
        Fen sc(2 * n);
        FOR (i, v.size()) {
            cnt.add(i, 1);
            sc.add(i, v[i].x);
        }

        int G = v.size();

        int ans = 1e18;
        int need = 0;
        FOR (mex, n + 1) {
            if (need > k) continue;
            int can_rem = cnt.get(sc.get(k + 1) - 1);
            debug(G);
            //debug(from_right);
            debug(can_rem);
            debug(mex);
            ckmin(ans, G - can_rem);
            if (c.find(mex) == c.end()) {
                need++;
            }
            else {
                G--;
                cnt.add(num[mex], -1);
                sc.add(num[mex], -c[mex]);
            }
        }

        cout << ans << endl;
    };
    rep (t) {
        solve();
    }
}