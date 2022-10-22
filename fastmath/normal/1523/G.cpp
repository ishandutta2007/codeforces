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
int l[N], r[N], len[N];
vi who[N];
set <ii> tree[N << 2];
int n, m;

void add(set <ii> &s, int i) {
    auto t = s.lower_bound(mp(l[i], -1));
    if (t != s.end() && t->y <= r[i]) {
        return;
    }
    while (1) {
        auto t = s.lower_bound(mp(l[i] + 1, -1));
        if (t == s.begin()) {
            break;
        }
        t--;
        if (t->y >= r[i]) {
            s.erase(t);
        }
        else {
            break;
        }
    }
    s.insert(mp(l[i], r[i]));
}
void turn_on(int v, int l, int r, int i) {
    add(tree[v], i);
    if (l == r) {
        return;
    }
    int m = (l + r) / 2;
    if (i <= m) {
        turn_on(v * 2 + 1, l, m, i);
    }
    else {
        turn_on(v * 2 + 2, m + 1, r, i);
    }
}   
int get(int v, int l, int r, int wl, int wr) {
    auto t = tree[v].lower_bound(mp(wl, -1));
    if (t == tree[v].end() || t->y > wr) {
        return -1;
    }
    if (l == r) {
        return l;
    }
    int m = (l + r) / 2;
    int a = get(v * 2 + 1, l, m, wl, wr);
    if (a != -1) {
        return a;
    }
    else {
        return get(v * 2 + 2, m + 1, r, wl, wr);
    }
}
int solve(int L, int R) {
    int i = get(0, 0, m - 1, L, R);
    if (i == -1) {
        return 0;
    }
    return len[i] + solve(L, l[i] - 1) + solve(r[i] + 1, R);
}

signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> m;
    FOR (i, m) {
        cin >> l[i] >> r[i];
        len[i] = r[i] - l[i] + 1;
        who[len[i]].app(i);
    }
    vi ans(n + 1);
    for (int x = n; x; --x) {
        each (i, who[x]) {
            turn_on(0, 0, m - 1, i);
        }
        ans[x] = solve(1, n);
    }
    FORN (i, n) {
        cout << ans[i] << endl;
    }
}