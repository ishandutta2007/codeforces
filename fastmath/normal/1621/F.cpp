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
signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t;
    cin >> t;
    rep (t) {
        int n, a, b, c;
        cin >> n >> a >> b >> c;
        string s;
        cin >> s;

        vi h(2);
        FOR (i, n - 1) {
            if (s[i] == s[i + 1]) {
                h[s[i]-'0']++;
            }
        }

        vi cnt(2);
        each (c, s) cnt[c-'0']++;

        vi bl;
        FOR (i, n) {
            if (i == 0 || s[i] != s[i - 1]) {
                if (s[i] == '0') {
                    int r = i;
                    while (r < n && s[r] == s[i]) r++;
                    if (i != 0 && r != n) bl.app(r - i);
                }
            }
        }

        sort(all(bl));

        vi p = {0};
        each (e, bl) {
            p.app(p.back() + e - 1);
        }

        vi maxone(n + 1);   
        int ptr = 0;
        FOR (i, n + 1) {
            while (ptr < p.size() && p[ptr] <= i) ptr++;
            maxone[i] = ptr - 1;
        }

        vi mindel(n + 1);
        ptr = 0;
        FOR (i, n + 1) {
            while (ptr <= n && maxone[ptr] < i) ptr++;
            mindel[i] = ptr;
        }

        int ans = 0;
        FOR (s, 2) {
            for (int w = 0; w <= n; ++w) {
                int d0 = (w + (s == 0))/2;
                int d1 = (w + (s == 1))/2;
                if (d0 <= cnt[0] && d1 <= cnt[1]) {
                    if (d1 <= h[1]) {
                        int fi = min(d0, h[0]);
                        ckmax(ans, a * fi + b * d1 - c * (d0 - fi));
                    }
                    else {
                        int wc = d1 - h[1];
                        if (wc <= cnt[0] && wc <= d0) {
                            int fi = min({d0, h[0], d0 - wc});
                            if (maxone[fi] >= wc) {

                                if (h[1] == 0 && s == 1) {
                                    //bred
                                }
                                else {
                                    // 01010101
                                    int can_del_0_before = h[1] - s;
                                    int need = mindel[wc];
                                    if (need <= can_del_0_before) {
                                        ckmax(ans, a * fi + b * d1 - c * (d0 - fi));    
                                    }
                                }
                            }
                        }
                    }
                }
            }            
        }
        cout << ans << endl;
    }
}


                                /*
                                debug(wc);
                                debug(d0);
                                debug(d1);
                                debug(fi);
                                debug(a * fi + b * d1 - c * (d0 - fi));
                                */