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

const int N = 5e5+7;

int n;
string a[3];
array <int, 7> t[N << 2];

bool was[20];
int mn[20];
bool used[20];
int val[20];

array <int, 7> neu;

array <int, 7> merge(array <int, 7> l, array <int, 7> r) {

    /*
    FOR (i, 7) {
        cout << l[i] << ' ';
    }
    cout << endl;

    FOR (i, 7) {
        cout << r[i] << ' ';
    }
    cout << endl;
    */


    if (l[0] == -1) return r;
    if (r[0] == -1) return l;

    FOR (i, 20) mn[i] = i;

    memset(was, 0, sizeof was);
    for (int i = 1; i < 7; ++i) if (l[i]) was[l[i]] = 1;
    for (int i = 1; i < 7; ++i) {
        if (r[i]) {
            r[i] += 10;
            was[r[i]] = 1;            
        }
    }

    int cmp = 0;
    FORN (com, 20 - 1) {
        if (was[com]) {
            cmp++;
            debug(com);
        }
    }

    rep (3) {
        FOR (i, 3) {
            if (l[4 + i] && r[1 + i]) {
                debug("tak");
                ckmin(mn[r[1 + i]], mn[l[4 + i]]);
                ckmin(mn[l[4 + i]], mn[r[1 + i]]);
            }
        }        
    }

    memset(used, 0, sizeof used);
    for (int i = 1; i < 7; ++i) {
        if (l[i]) used[mn[l[i]]] = 1;
    }
    for (int i = 1; i < 7; ++i) {
        if (r[i]) used[mn[r[i]]] = 1;
    }
    FOR (c, 20) {
        if (used[c]) {
            debug(c);
            cmp--;
        }
    }

    memset(used, 0, sizeof used);
    for (int i = 1; i < 4; ++i) {
        if (l[i]) used[mn[l[i]]] = 1;
    }
    for (int i = 4; i < 7; ++i) {
        if (r[i]) used[mn[r[i]]] = 1;
    }
    int ptr = 0;
    FOR (i, 20) {
        if (used[i]) {
            debug(i);
            ptr++;
            val[i] = ptr;
        }
    }
    array <int, 7> ans;
    ans[0] = l[0] + r[0] - cmp;

    debug(l[0]); debug(r[0]);
    debug(l[1]); debug(l[2]);
    debug(cmp);
    debug(ptr);

    for (int i = 1; i < 4; ++i) {
        ans[i] = val[mn[l[i]]];
    }
    for (int i = 4; i < 7; ++i) {
        ans[i] = val[mn[r[i]]];
    }
    return ans;
}

void build(int v, int l, int r) {
    if (l == r) {
        FOR (i, 3) {
            t[v][0] += a[i][l] - '0';
        }
        FOR (i, 2) {
            t[v][0] -= (a[i][l] == '1') && (a[i + 1][l] == '1');
        }

        int ptr = 1;

        if (a[0][l] == '1') {
            t[v][1] = 1;
            ptr++;
        }
        else {
            t[v][1] = 0;
        }

        for (int i = 1; i < 3; ++i) {
            if (a[i][l] == '1') {
                if (t[v][i - 1 + 1]) {
                    t[v][i + 1] = t[v][i - 1 + 1];
                }
                else {
                    t[v][i + 1] = ptr;
                    ptr++;
                }
            }
            else {
                t[v][i + 1] = 0;
            }
        }

        FOR (i, 3) {
            t[v][4 + i] = t[v][1 + i];
        }

        return;
    }

    int m = (l + r) / 2;
    build(v * 2 + 1, l, m); build(v * 2 + 2, m + 1, r);

    debug(mp(l, m));
    debug(mp(m + 1, r));

    t[v] = merge(t[v * 2 + 1], t[v * 2 + 2]);
}

array <int, 7> get(int v, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return t[v];
    if (r < ql || qr < l) return neu;
    int m = (l + r) / 2;
    return merge(get(v * 2 + 1, l, m, ql, qr), get(v * 2 + 2, m + 1, r, ql, qr));
}

signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    neu[0] = -1;
    cin >> n;
    FOR (i, 3) cin >> a[i];
    build(0, 0, n - 1);
    int q;
    cin >> q;
    rep (q) {
        int l, r;
        cin >> l >> r;
        cout << get(0, 0, n - 1, l - 1, r - 1)[0] << endl;
    }
}