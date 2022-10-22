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
    int n = 8;
    string ans;
    cout << 1 << ' ' << 2 << endl;
    cin >> ans;
    if (ans == "Done") return;
    cout << 1 << ' ' << 1 << endl;
    int x = 1, y = 1;
    bool going_right = 1;
    while (1) {
        cin >> ans;
        if (ans == "Done") return;
        if (ans.size() >= 4 && ans.substr(0, 4) == "Down") {
            x++;
            if (y == 1) {
                y++;
            }
            cout << x << ' ' << y << endl;
            going_right = 0;
        }
        else if (ans.size() >= 2 && ans.substr(0, 2) == "Up") {
            going_right = 1;
            if (y != 1) {
                y = 1;
                cout << x << ' ' << y << endl;                
            }
            else {
                y++;
                cout << x << ' ' << y << endl;
            }
        }
        else if (!going_right) {
            going_right = 1;
            if (y == 1) {
                y++;
            }
            else {
                y = 1;
            }
            cout << x << ' ' << y << endl;
        }
        else if (y < n) {
            y++;
            cout << x << ' ' << y << endl;                
        }
        else {
            x++;
            cout << x << ' ' << y << endl;
            going_right = 0;
        }
    }
    assert(0);
}

signed main() {
    int n = 4;
    int t;
    cin >> t;
    rep (t) {
        solve();
    }
}