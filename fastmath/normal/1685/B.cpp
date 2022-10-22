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
    auto solve = [&] () {
        vi w(4);
        cin >> w;

        string s;
        cin >> s;

        int n = s.size();

        vi cnt(2);
        each (c, s) cnt[c - 'A']++;

        vi wantc(2);
        wantc[0] = w[0] + w[2] + w[3];
        wantc[1] = w[1] + w[2] + w[3];

        debug(s);
        debug(cnt);
        debug(wantc);

        FOR (i, 2) {
            if (wantc[i] != cnt[i]) {
                cout << "NO" << endl;
                return;
            }
        }


        int S = 0;

        vi ab, ba;

        int p = 0;
        while (p < n) {
            if (p + 1 < n && s[p + 1] != s[p]) {
                int r = p;
                while (r + 1 < n && s[r + 1] != s[r]) r++;

                int len = r - p + 1;
                if (len & 1) {
                    S += len/2;
                }
                else {
                    if (s[p] == 'A') {
                        ab.app(len/2 - 1);
                    }
                    else {
                        ba.app(len/2 - 1);
                    }
                }

                p = r + 1;
            }
            else {
                p++;
            }

        }

        sort(all(ab));
        sort(all(ba));

        debug(ab);
        debug(ba);

        int i = 0;
        while (i < ab.size()) {
            if (ab[i] + 1 > w[2]) {
                break;
            }
            else {
                w[2] -= ab[i] + 1;
                i++;
            }
        }
        while (i < ab.size()) {
            S += ab[i++];
        }

        i = 0;
        while (i < ba.size()) {
            if (ba[i] + 1 > w[3]) {
                break;
            }
            else {
                w[3] -= ba[i] + 1;
                i++;
            }
        }
        while (i < ba.size()) {
            S += ba[i++];
        }

        debug(w);
        debug(S);

        if (w[2] + w[3] <= S) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }

    };
    int t;
    cin >> t;
    rep (t) {
        solve();
    }
}