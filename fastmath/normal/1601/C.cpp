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

struct ST {

const int INF = 1e9+7; // check INF!

int n; // 0...n - 1
vector <int> mn, mx, prop, prop_val, sum;

ST (int n_) {
    n = n_;
    mn.assign(n << 2, 0);
    mx.assign(n << 2, 0);
    sum.assign(n << 2, 0);
    prop.assign(n << 2, 0);
    prop_val.assign(n << 2, INF);
}
void gap(int v, int l, int r, int x) {
    mn[v] += x;
    mx[v] += x;
    sum[v] += (r - l + 1) * x;
    if (prop_val[v] != INF)
        prop_val[v] += x;
    else
        prop[v] += x;
}   
void gap_val(int v, int l, int r, int x) {
    mn[v] = mx[v] = x;
    sum[v] = (r - l + 1) * x;
    prop[v] = 0;
    prop_val[v] = x;
}
void push(int v, int l, int r) {
    int m = (l + r) >> 1;
    if (prop_val[v] != INF) {
        gap_val(v * 2 + 1, l, m, prop_val[v]);
        gap_val(v * 2 + 2, m + 1, r, prop_val[v]);
        prop_val[v] = INF;
    }
    else if (prop[v]) {
        gap(v * 2 + 1, l, m, prop[v]);
        gap(v * 2 + 2, m + 1, r, prop[v]);
        prop[v] = 0;
    }   
}
void relax(int v) {
    mn[v] = min(mn[v * 2 + 1], mn[v * 2 + 2]);
    mx[v] = max(mx[v * 2 + 1], mx[v * 2 + 2]);
    sum[v] = sum[v * 2 + 1] + sum[v * 2 + 2];
}   
void add(int v, int tl, int tr, int l, int r, int x) {
    if (tr < l || r < tl)
        return;
    if (l <= tl && tr <= r) {
        gap(v, tl, tr, x);
        return;
    }   
    int tm = (tl + tr) >> 1;
    push(v, tl, tr);
    add(v * 2 + 1, tl, tm, l, r, x);
    add(v * 2 + 2, tm + 1, tr, l, r, x);
    relax(v);                
}   
void setval(int v, int tl, int tr, int l, int r, int x) {
    if (tr < l || r < tl) 
        return;
    if (l <= tl && tr <= r) {
        gap_val(v, tl, tr, x);
        return;
    }
    int tm = (tl + tr) >> 1;
    push(v, tl, tr);
    setval(v * 2 + 1, tl, tm, l, r, x);
    setval(v * 2 + 2, tm + 1, tr, l, r, x);
    relax(v);
}
int getmin(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl)
        return INF;
    if (l <= tl && tr <= r)
        return mn[v];
    int tm = (tl + tr) >> 1;
    push(v, tl, tr);
    return min(getmin(v * 2 + 1, tl, tm, l, r), getmin(v * 2 + 2, tm + 1, tr, l, r));
}   
int getmax(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl)
        return -INF;
    if (l <= tl && tr <= r)
        return mx[v];
    int tm = (tl + tr) >> 1;
    push(v, tl, tr);
    return max(getmax(v * 2 + 1, tl, tm, l, r), getmax(v * 2 + 2, tm + 1, tr, l, r));
}   
int getsum(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl)
        return 0;
    if (l <= tl && tr <= r)
        return sum[v];
    int tm = (tl + tr) >> 1;
    push(v, tl, tr);
    return getsum(v * 2 + 1, tl, tm, l, r) + getsum(v * 2 + 2, tm + 1, tr, l, r);
}   
void setpoint(int v, int tl, int tr, int i, int x) {
    if (tl == tr) {
        mn[v] = mx[v] = sum[v] = x;
        return;
    }   
    int tm = (tl + tr) >> 1;
    push(v, tl, tr);
    if (i <= tm)
        setpoint(v * 2 + 1, tl, tm, i, x);
    else
        setpoint(v * 2 + 2, tm + 1, tr, i, x);
    relax(v);
}   
void build(int v, int tl, int tr, int *a) {
    if (tl == tr) {
        mn[v] = mx[v] = sum[v] = a[tl];
        return;
    }   
    int tm = (tl + tr) >> 1;
    build(v * 2 + 1, tl, tm, a);
    build(v * 2 + 2, tm + 1, tr, a);
    relax(v);
}   
void build(int v, int tl, int tr, vi &a) {
    if (tl == tr) {
        mn[v] = mx[v] = sum[v] = a[tl];
        return;
    }   
    int tm = (tl + tr) >> 1;
    build(v * 2 + 1, tl, tm, a);
    build(v * 2 + 2, tm + 1, tr, a);
    relax(v);    
}
void clear() {
    mn.assign(n << 2, 0);
    mx.assign(n << 2, 0);
    sum.assign(n << 2, 0);
    prop.assign(n << 2, 0);
    prop_val.assign(n << 2, INF);
}   
void add(int l, int r, int x) {
    add(0, 0, n - 1, l, r, x);
    //cout << "add " << l << ' ' << r << ' ' << x << endl;
}   
int getmin(int l, int r) {
    return getmin(0, 0, n - 1, l, r);
}   
int getmax(int l, int r) {
    return getmax(0, 0, n - 1, l, r);
}   
int getsum(int l, int r) {
    return getsum(0, 0, n - 1, l, r);
}   
void setpoint(int i, int x) {
    setpoint(0, 0, n - 1, i, x);
}   
void setval(int l, int r, int x) {
    setval(0, 0, n - 1, l, r, x);
}
void build(int *a) {
    build(0, 0, n - 1, a);
}   
void build(vi a) {
    assert(a.size() == n);
    build(0, 0, n - 1, a);
}

int get_left_moq(int v, int tl, int tr, int l, int w) {
    if (tr < l || mx[v] < w)
        return -1;
    if (tl == tr)
        return tl;
    int tm = (tl + tr) >> 1;
    push(v, tl, tr);
    int t = get_left_moq(v * 2 + 1, tl, tm, l, w);
    if (t != -1)
        return t;
    else
        return get_left_moq(v * 2 + 2, tm + 1, tr, l, w);                                    
}   
int get_left_moq(int l, int w) {
    return get_left_moq(0, 0, n - 1, l, w);
}

int get_left_leq(int v, int tl, int tr, int l, int w) {
    if (tr < l || mn[v] > w)
        return -1;
    if (tl == tr)
        return tl;
    int tm = (tl + tr) >> 1;
    push(v, tl, tr);
    int t = get_left_leq(v * 2 + 1, tl, tm, l, w);
    if (t != -1)
        return t;
    else
        return get_left_leq(v * 2 + 2, tm + 1, tr, l, w);                                    
}   
int get_left_leq(int l, int w) {
    return get_left_leq(0, 0, n - 1, l, w);
}

};  

const int N = 1e6+7;
int a[N], b[N], start[N];

struct Fen {
int n;
int f[N];
void clear() {
    for (int i = 0; i < n; ++i) f[i] = 0;
}   
void add(int i, int x) {
    for (; i < n; i |= i + 1) 
        f[i] += x;
}   
int get(int i) {
    int ans = 0;
    for (; i >= 0; i &= i + 1, --i) ans += f[i];
    return ans;
}   
int get(int l, int r) {
    //check r < l!
    return get(r) - get(l - 1);
}   
} f;

signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t;
    cin >> t;
    rep (t) {
        int n, m;
        cin >> n >> m;

        V <ii> ord(n);
        FOR (i, n) {
            cin >> a[i];
            ord[i] = mp(a[i], i + 1);
        }
        FOR (i, m) {
            cin >> b[i];
        }

        int ans = 0;
        
        f.n = n;
        vi c(n);
        FOR (i, n) c[i] = a[i];
        sort(all(c));
        for (int i = n - 1; i >= 0; --i) {
            int pos = lower_bound(all(c), a[i]) - c.begin();
            ans += f.get(pos - 1);
            f.add(pos, 1);
        }
        f.clear();

        ST tree(n + 1);
        FOR (i, n + 1) {
            start[i] = i;
        }
        tree.build(start);

        sort(b, b + m);
        sort(all(ord));

        //debug(ord);

        int p = 0, state = 1, tot_less = 0;
        FOR (i, m) {
            int x = b[i];
            //debug(i);
            //debug(state);
            //debug(x);
            while (p < n) {
                int pos = ord[p].y;
                if (x < ord[p].x) {
                    state = 1;
                    break;
                }
                else if (x == ord[p].x) {
                    if (state == 1) {
                        for (int j = p; j < n && ord[j].x == ord[p].x; ++j) {
                            tree.add(ord[j].y, n, -1);
                        }
                        state = 0;
                    }
                    //debug(state);
                    //debug(p);
                    assert(state == 0);
                    break;
                }
                else {
                    if (state == 0) {
                        int le = ord[p].x;
                        for (; p < n && ord[p].x == le; ++p) {
                            tree.add(ord[p].y, n, -1);
                            tot_less++;
                        }
                        state = 1;
                    }
                    else {
                        tree.add(pos, n, -1-state);
                        tot_less++;
                        p++;
                        state = 1;
                    }
                }
            }
            ans += tot_less + tree.mn[0];
            //debug(tot_less);
            //debug(tree.mn[0]);
        }
        cout << ans << endl;
    }
}