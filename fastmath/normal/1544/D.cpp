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
signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t;
    cin >> t;
    rep (t) {
        int n;
        cin >> n;
        vi who(n + 1), ans(n + 1), want(n + 1), in(n + 1);
        FORN (i, n) {
            cin >> want[i];
            who[want[i]] = i;
            in[want[i]]++;
        }
        FORN (i, n) {
            if (in[i] == 0) {
                who[want[i]] = i;
            }
        }
        vi without_gift;
        int res = n;
        FORN (i, n) {
            if (who[i]) {
                ans[who[i]] = i;
            }
            else {
                res--;
                without_gift.app(i);
            }
        }
        FORN (i, n) {

            if (without_gift.size() <= 2) {
                break;
            }

            if (!ans[i]) {
                int sz = without_gift.size();
                if (i == without_gift[sz - 1]) {
                    swap(without_gift[sz - 2], without_gift[sz - 1]);
                }
                ans[i] = without_gift.back();
                without_gift.pop_back();
            }
        }

        vi L;
        FORN (i, n) {
            if (!ans[i]) {
                L.app(i);
            }
        }
        assert(L.size() == without_gift.size());
        assert(L.size() <= 2);

        if (L.size() == 0) {

        }
        else if (L.size() == 1) {
            assert(L[0] != without_gift[0]);
            ans[L[0]] = without_gift[0];
        }
        else {
            if (L[0] == without_gift[0] || L[1] == without_gift[1]) {
                swap(L[0], L[1]);
            }
            ans[L[0]] = without_gift[0];
            ans[L[1]] = without_gift[1];
        }

        cout << res << endl;
        FORN (i, n) {
            assert(ans[i] != i);
            cout << ans[i] << ' ';
        }
        cout << endl;
    }
}