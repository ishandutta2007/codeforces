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

const int INF = 1e9;

struct Fen {
int n;
V <ii> f;
Fen (int n_) {
    n = n_;
    f.assign(n, mp(INF, INF));
}  
void add(int i, ii x) {
    for (; i < n; i |= i + 1) 
        ckmin(f[i], x);
}   
ii get(int i) {
    ckmin(i, n - 1);
    ii ans = mp(INF, INF);
    for (; i >= 0; i &= i + 1, --i) ckmin(ans, f[i]);
    return ans;
}     
};

void calc(int l, int r, vi &b, vi &dp, vi &p) {
    if (l == r) return;
    int m = (l + r) / 2;
    calc(l, m, b, dp, p);

    vi bl, blm, maxmem;
    int mxl = b[m];
    for (int i = m; i >= l; --i) {
        ckmax(mxl, b[i]);
        maxmem.app(mxl);
        bl.app(b[i]);
        blm.app(b[i] - mxl);
    }
    sort(all(bl));
    reverse(all(bl));

    sort(all(blm));
    reverse(all(blm));

    V <ii> ask_pref, ask_suf;
    vi maxmemr;

    int mxr = b[m + 1];
    for (int i = m + 1; i <= r; ++i) {
        ckmax(mxr, b[i]);
        maxmemr.app(mxr);

        int p = lower_bound(all(maxmem), mxr) - maxmem.begin();

        //int p = lower_bound(all(maxmem), mxr, greater <int>()) - maxmem.begin();
        p = m - p;

        if (b[i] >= 0) {
            //ask_suf.app(mp(p, i));
            //if ()
            if (p >= l) {
                ask_pref.app(mp(p, i));
            }
            if (p < m) {
                ask_suf.app(mp(p + 1, i));
            }
        }
    }

    sort(all(ask_pref));
    sort(all(ask_suf));
    reverse(all(ask_suf));

    int L = m - l + 1;
    int gr = r;
    Fen f1(L);

    debug(mp(l, r));
    //debug(m);

    if (l == 0 && gr == 6) {
        debug(ask_pref);
    }


    for (int i = l, ptr = 0, num = L - 1; i <= m; ++i, num--) {
        int pos = lower_bound(all(blm), b[i] - maxmem[num], greater <int>()) - blm.begin();
        if (b[i] >= 0) f1.add(pos, mp(dp[i], i));
        while (ptr < ask_pref.size() && ask_pref[ptr].x == i) {
            int r = ask_pref[ptr].y;

            if (l == 0 && gr == 6) {
                debug(r);
            }

            int getpos = upper_bound(all(blm), -b[r], greater <int>()) - blm.begin() - 1;
            auto t = f1.get(getpos);
            if (ckmin(dp[r], t.x + 1)) {
                if (r == 10) {
                    debug(t);
                }
                p[r] = t.y;
            }
            ptr++;
        }
    }

    Fen f2(L);
    for (int i = m, ptr = 0, num = 0; i >= l; --i, num++) {
        int pos = lower_bound(all(bl), b[i], greater <int>()) - bl.begin();
        if (b[i] >= 0) f2.add(pos, mp(dp[i], i));
        while (ptr < ask_suf.size() && ask_suf[ptr].x == i) {
            int r = ask_suf[ptr].y;
            int getpos = upper_bound(all(bl), maxmemr[r - m - 1] - b[r], greater <int>()) - bl.begin() - 1;



            auto t = f2.get(getpos);
            if (ckmin(dp[r], t.x + 1)) {
                if (r == 10) {
                    debug(m);
                    debug(t);
                }
                p[r] = t.y;
            }
            ptr++;
        }
    }

    if (b[m] >= 0 && b[m + 1] >= 0) {
        if (ckmin(dp[m + 1], dp[m])) {
            p[m + 1] = m;
        }
    }

    calc(m + 1, r, b, dp, p);
}

signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    auto solve = [&] () {
        int n;
        cin >> n;

        n <<= 1;

        string s;
        cin >> s;

        vi b(n + 1);
        FOR (i, n) {
            b[i + 1] = b[i];
            if (s[i] == '(') b[i + 1]++;
            else b[i + 1]--;
        }

        vi dp(n + 1, 2 * n), p(n + 1);

        dp[0] = 0;

        calc(0, n, b, dp, p);

        debug(dp);

        cout << dp[n] << endl;


        int cur = n;
        while (cur) {
            if (p[cur] == cur - 1) {
                cur--;
            }
            else {
                cout << p[cur] + 1 << ' ' << cur << endl;
                cur = p[cur];
            }
        }

    };
    int t;
    cin >> t;
    rep (t) {
        solve();
    }
}