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

const int L = 30;
struct Basis {
int order;
int a[L];
Basis() {
    memset(a, 0, sizeof a);
    order = 0;
}
void clear() {
    memset(a, 0, sizeof a);
    order = 0;    
}
int add(int x) {
    for (int i = L - 1; i >= 0; --i) {
        if (Bit(x, i)) {
            if (a[i]) {
                x ^= a[i];
            }
            else {
                a[i] = x;
                order++;
                return i;
            }
        }
    }
    return -1;
}
bool have(int x) {
    for (int i = L - 1; i >= 0; --i) {
        if (Bit(x, i)) {
            if (a[i]) {
                x ^= a[i];
            }
            else {
                return 0;
            }
        }
    }
    return 1;
}
void form() {
    for (int i = L - 1; i >= 0; --i) {
        if (a[i]) {
            FOR (j, i) {
                if (Bit(a[j], i)) {
                    a[j] ^= a[i];
                }
            }
        }
    }
}
int Order() {
    return order;
}
void PourIn(Basis b) {
    FOR (i, L) {
        if (b.a[i]) {
            add(b.a[i]);
        }
    }
}
};

const int N = 2e5+7;
int n, q, a[N];

Basis tree[N << 2];
void relax(int v) {
    tree[v].clear();
    tree[v].PourIn(tree[v * 2 + 1]);
    tree[v].PourIn(tree[v * 2 + 2]);
}
void build(int v, int l, int r) {
    if (l == r) {
        tree[v].add(a[l]);
        return;
    }
    int m = (l + r) / 2;
    build(v * 2 + 1, l, m);
    build(v * 2 + 2, m + 1, r);
    relax(v);
}
void change_point(int v, int l, int r, int i, int x) {
    if (l == r) {
        a[i] ^= x;
        tree[v].clear();
        tree[v].add(a[i]);
        return;
    }
    int m = (l + r) / 2;
    if (i <= m) {
        change_point(v * 2 + 1, l, m, i, x);
    }
    else {
        change_point(v * 2 + 2, m + 1, r, i, x);
    }
    relax(v);
}
Basis get(int v, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) {
        return Basis();
    }
    if (ql <= l && r <= qr) {
        return tree[v];
    }
    int m = (l + r) / 2;
    Basis ans;
    ans.PourIn(get(v * 2 + 1, l, m, ql, qr));
    ans.PourIn(get(v * 2 + 2, m + 1, r, ql, qr));
    return ans;
}

struct Fen {
int f[N];
void clear() {
    for (int i = 0; i < N; ++i) f[i] = 0;
}   
void add(int i, int x) {
    for (; i < N; i |= i + 1) 
        f[i] ^= x;
}   
int get(int i) {
    int ans = 0;
    for (; i >= 0; i &= i + 1, --i) ans ^= f[i];
    return ans;
}   
int get(int l, int r) {
    //check r < l!
    return get(r) ^ get(l - 1);
}   
} f;

signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> q;
    FOR (i, n) {
        cin >> a[i];
        f.add(i, a[i]);
        f.add(i + 1, a[i]);
    }
    for (int i = n - 1; i; --i) {
        a[i] ^= a[i - 1];
    }
    build(0, 0, n - 1);
    rep (q) {
        int t;
        cin >> t;
        int l, r;
        cin >> l >> r;
        l--; r--;
        if (t == 1) {
            int x;
            cin >> x;
            f.add(l, x);
            f.add(r + 1, x);
            change_point(0, 0, n - 1, l, x);
            if (r + 1 < n) {
                change_point(0, 0, n - 1, r + 1, x);
            }
        }
        else {
            auto b = get(0, 0, n - 1, l + 1, r);
            b.add(f.get(l));
            cout << (1ll << b.Order()) << endl;
        }
    }
}