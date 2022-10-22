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
void solve() {
    int sum, n;
    cin >> sum >> n;

    const int L = 15;
    vi cnt(L);

    int have = 0;

    int pw = 0;
    while (sum) {
        cnt[pw] += sum%10;
        have += sum%10;
        pw++;
        sum /= 10;
    }

    auto print = [&] (int p) {
        cout << '1';
        rep (p) cout << '0';
        cout << ' ';
    };

    if (have >= n) {
        rep (n - 1) {
            FOR (p, L) {
                if (cnt[p]) {
                    cnt[p]--;
                    print(p);
                    break;
                }
            }
        }
        while (cnt.back() == 0) {
            cnt.pop_back();
        }
        reverse(all(cnt));
        each (e, cnt) {
            cout << e;
        }
        cout << endl;
        return;
    }

    while (have < n) {
        int want = n - have;
        bool did = 0;
        for (int p = 1; p < L; ++p) {
            if (cnt[p]) {
                if (want <= 9) {
                    rep (want) {
                        print(p - 1);
                    }
                    cout << 10 - want;
                    rep (p - 1) cout << '0';
                    cout << ' ';

                    cnt[p]--;
                    rep (have - 1) {
                        FOR (p, L) {
                            if (cnt[p]) {
                                cnt[p]--;
                                print(p);
                                break;
                            }
                        }
                    }
                    cout << endl;

                    return;
                }
                else {
                    cnt[p]--;
                    cnt[p - 1] += 10;
                    have += 9;
                    did = 1;
                    break;
                }
            }
        }
        assert(did);
    }

    assert(0);
}
signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t;
    cin >> t;
    rep (t) {
        solve();
    }
}