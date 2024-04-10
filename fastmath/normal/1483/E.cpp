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
#define FOR(i, n) for (int i = 0; i < n; ++i)
#define pb push_back
#define trav(a, x) for (auto& a : x)
using vi = vector<int>;
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
tcT> void re(V<T>& x) { 
    trav(a, x)
        cin >> a;
}
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

const int N = 100;
int dp[N][N];

signed main() {
    int C = 1;
    FOR (i, 14)
        C *= 10;

    FOR (i, N) {
        dp[0][i] = 1;
    }
    for (int i = 1; i < N; ++i) {
        FOR (j, N - 1) {
            dp[i][j] = dp[i - 1][j + 1];
            if (j)
                dp[i][j] += dp[i - 1][j - 1];   
        }
    }

    #ifdef LOCAL
    int A = -1;
    #endif

    auto solve = [&] () {
        int have = 105;
        int money = 1;
        auto get = [&] (int x) {
            assert(0 <= x && x <= C);
            assert(have);
            have--;
            #ifndef LOCAL
            cout << "? " << x << endl;
            string ans;
            cin >> ans;
            if (ans[0] == 'L') {
                money += x;
                return 1;
            }
            else {
                assert(money >= x);
                money -= x;
                return 0;
            }
            #else
            if (A >= x) {
                money += x;
                return 1;
            }
            else {
                assert(money >= x);
                money -= x;
                return 0;
            }
            #endif
        };
        auto answer = [&] (int x) {
            #ifdef LOCAL
            assert(x == A);
            #endif
            cout << "! " << x << endl;
        };

        int L = 0, R = C + 1; // L <= m < R
        for (int bit = 0; bit < 47; ++bit) {
            if (get(1ll << bit)) {
                L = 1ll << bit;
            }
            else {
                R = 1ll << bit;
                break;
            }
        }

        int len = R - L;

        int need = 0;
        while (dp[need][0] < len) {
            need++;
        }

        assert(have >= need + 3);
        FOR (i, 3)
            get(L);

        int tok = 0;
        while (L < R - 1) {
            int M;
            if (tok == 0) {
                M = L;
            }
            else {
                M = L + dp[need - 1][tok - 1];
            }
            ckmin(M, R - 1);
            if (get(M)) {
                L = M;
                tok++;
            }
            else {
                R = M;
                tok--;
            }
            need--;
        }
        answer(L);
    };

    int t;
    cin >> t;
    while (t--) {
        #ifdef LOCAL
        cin >> A;
        #endif
        solve();
    }
}