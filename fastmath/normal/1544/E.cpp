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

void solve() {
    string s;
    cin >> s;
    int n = s.size();

    bool same = 1;
    for (int i = 1; i < n; ++i) {
        same &= s[i] == s[0];
    }
    if (same) {
        cout << s;
        return;
    }

    vi cnt(26);
    each (c, s) {
        cnt[c - 'a']++;
    }
    FOR (c, 26) {
        if (cnt[c] == 1) {
            cout << (char)('a' + c);
            cnt[c]--;
            FOR (out, 26) {
                rep (cnt[out]) {
                    cout << (char)('a' + out);
                }
            }
            return;
        }
    }

    int mn = -1;
    FOR (c, 26) {
        if (cnt[c]) {
            mn = c;
            break;
        }
    }

    if (cnt[mn] > 1 && (cnt[mn] - 2) <= ((n - 2) / 2)) {
        cout << (char)(mn + 'a') << (char)(mn + 'a');

        int k = cnt[mn] - 2;

        string other;
        FOR (c, 26) {
            if (c != mn) {
                rep (cnt[c]) {
                    other += (char)('a' + c);
                }
            }
        }

        int ptr = 0;
        bool can_min = 0;
        rep (n - 2) {
            if (can_min && k) {
                k--;
                cout << (char)(mn + 'a');
                can_min = 0;
            }
            else {
                cout << other[ptr];
                ptr++;
                can_min = 1;
            }
        }
        return;
    }

    int sec = -1;
    for (int c = mn + 1; c < 26; ++c) {
        if (cnt[c]) {
            sec = c;
            break;
        }
    }

    cout << (char)(mn + 'a') << (char)(sec + 'a');

    cnt[mn]--;
    cnt[sec]--;

    string other;
    FOR (c, 26) {
        if (c != mn && c != sec) {
            rep (cnt[c]) {
                other += (char)('a' + c);
            }
        }
    }

    if (other.empty()) {
        FOR (i, cnt[sec]) {
            cout << (char)(sec + 'a');
        }
        FOR (i, cnt[mn]) {
            cout << (char)(mn + 'a');
        }
        return;
    }

    if (cnt[mn] == 0) {
        FOR (i, cnt[sec]) {
            cout << (char)(sec + 'a');
        }
        cout << other;
        return;
    }

    FOR (i, cnt[mn]) {
        cout << (char)(mn + 'a');
    }
    cout << other[0];
    FOR (i, cnt[sec]) {
        cout << (char)(sec + 'a');
    }
    for (int i = 1; i < other.size(); ++i) {
        cout << other[i];
    }
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
        cout << endl;
    }
}