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

int getl(int x) {
    const int INF = 1e9+7;
    assert(x > 0);
    assert(x < INF * (INF - 1) / 2);
    int l = 0, r = INF;
    while (l < r - 1) {
        int m = (l + r) / 2;
        if (m * (m - 1) / 2 < x) {
            l = m;
        }
        else {
            r = m;
        }
    }
    assert(r * (r - 1) / 2 == x);
    return r;
}

mt19937 rnd(2007);
int p[101];

signed main() {
    int t;
    cin >> t;
    rep (t) {
        auto ask = [&] (int l, int r) {
            #ifdef LOCAL
            int ans = 0;
            for (int i = l; i <= r; ++i) {
                for (int j = i + 1; j <= r; ++j) {
                    ans += p[j] < p[i];
                }
            }
            return ans;
            #else
            cout << "? " << l << ' ' << r << endl;
            int ans; cin >> ans; return ans;
            #endif
        };

        int n;
        #ifdef LOCAL
        n = rnd()%10+4;
        FORN (i, n) p[i] = i;

        int I, J, K;
        while (1) {
            int i = rnd()%n+1;
            int j = rnd()%n+1;
            int k = rnd()%n+1;
            if (i + 1 < j && j < k) {
                reverse(p + i, p + j);
                reverse(p + j, p + k + 1);
                I = i;
                J = j;
                K = k;
                break;
            }
        }

        #else
        cin >> n;
        #endif
        int tot = ask(1, n);
        int l = 1, r = n;
        int j = -1;
        while (1) {
            int m = (l + r) / 2;
            int t = ask(l, m);
            if (t == tot) {
                r = m;
            }
            else if (t == 0) {
                assert(m - 1 != l);
                l = m - 1;
            }
            else {
                int x = ask(l, m + 1);
                j = (m + 1) - (x - t);

                int L = 0;
                if (j > 1) {
                    L = ask(1, j - 1);
                }
                if (L) {
                    int R = tot - L;

                    int l_len = getl(L);
                    int r_len = getl(R);

                    int i = j - l_len;
                    int k = j + r_len - 1;

                    #ifdef LOCAL
                    if (i != I || j != J || k != K) {
                        cout << n << endl;
                        FORN (i, n) {
                            cout << p[i] << ' ';
                        }
                        cout << endl;
                        exit(0);
                    }
                    debug("ok1");
                    #else
                    cout << "! " << i << ' ' << j << ' ' << k << endl;
                    #endif
                }
                else {

                    int i = j;

                    l = j;
                    while (l < r - 1) {
                        int m = (l + r) / 2;
                        int t = ask(i, m);
                        int len = m - i + 1;
                        if (t == len * (len - 1) / 2) {
                            l = m;
                        }
                        else {
                            r = m;
                        }
                    }

                    int j = r;
                    int R = ask(j, n);
                    int k = j + getl(R) - 1;

                    #ifdef LOCAL
                    if (i != I || j != J || k != K) {
                        cout << n << endl;
                        FORN (i, n) {
                            cout << p[i] << ' ';
                        }
                        cout << endl;
                        exit(0);
                    }
                    debug("ok2");
                    #else
                    cout << "! " << i << ' ' << j << ' ' << k << endl;
                    #endif
                }

                break;
            }
        }
    }
}