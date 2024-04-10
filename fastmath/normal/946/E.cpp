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
#define debug2(x, y) std::cerr << #x << ", " << #y << ": " << x << ", " << y << '\n';
#define debug3(x, y, z) std::cerr << #x << ", " << #y << ", " << #z << ": " << x << ", " << y << ", " << z << '\n';
#else
#define debug(x)
#define debug2(x, y) 
#define debug3(x, y, z) 
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
    auto solve = [&] () {
        string s;
        cin >> s;
        int n = s.size();

        const int c = 10;

        vi cnt(c);
        auto can = [&] (int i, int w, bool a = false) {
            if (i == 0 && w == 0) {
                return false;

            } 
            vi h;
            FOR (i, c) {
                if (cnt[i]^(w==i)) {
                    h.app(i);
                }
            }

            int r = n - i - 1;

            if (h.size() > r) {
                return false;
            }

            if (a) {
                return true;
            }

            if (s[i]-'0' > w) {
                return true;
            }

            if (s[i]-'0' < w) {
                return false;
            }

            if (i + 1==n) {
                return false;
            }

            if (h.size() == r) {
                return h[0] < s[i+1]-'0';
            }

            if (s[i + 1] != '0') {
                return true;
            }

            int l = (int)n - h.size();
            for (int j = i + 1; j < l; ++j) {
                if (s[j]!='0') {
                    return true;
                }
            }

            FOR (j, h.size()) {
                if (h[j] < s[l + j] - '0') {
                    return true;
                }
                if (h[j] > s[l + j] - '0') {
                    return false;
                }
            }
            return false;
        };



        int mx = -1, di = -1;
        FOR (i, n) {

            FOR (t, s[i]-'0') {
                if (can(i, t)) {
                    mx = i;
                    di = t;
                }
            }

            cnt[s[i]-'0']^=1;
        }

        if (mx == -1) {
            rep (n - 2) cout << '9';
            cout << endl;
            return;
        }

        //debug2(mx, di);

        cout << s.substr(0, mx) << (char)(di+'0');

        FOR (i, c) cnt[i] = 0;
        FOR (i, mx) cnt[s[i]-'0']^=1;
        cnt[di]^=1;

        //debug(cnt);

        for (int i = mx + 1; i < n; ++i) {
            //debug(i);
            ROF (t, c) {
                if (can(i, t, 1)) {
                    cnt[t]^=1;
                    cout <<  (char)(t+'0');
                    break;
                }
            }
        }
        cout << endl;
    };
    int t;
    cin >> t;
    rep (t) {
        solve();
    }
}