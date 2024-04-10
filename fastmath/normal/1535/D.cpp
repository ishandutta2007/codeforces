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

const int N = 1 << 19;
int dp[N];
int vert[N], pos[N], h[N], cnt[N];

signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    int k;
    cin >> k;

    string s;
    cin >> s;

    int n = 1 << k;
    for (int i = n; i < 2 * n; ++i) {
        dp[i] = 1;
    }

    for (int i = 1; i < n; ++i) {
        h[i] = h[i/2] + 1;
        int num = cnt[h[i]];

        //debug(i); 

        cnt[h[i]]++;
        for (int j = h[i] + 1; j <= k; ++j) {
            num += 1 << (j - 1);
        }

        //debug(num);

        pos[i] = num;
        vert[num] = i;
    }   

    for (int i = n - 1; i; --i) {
        int l = i * 2, r = i * 2 + 1;
        if (s[pos[i]] == '?') {
            dp[i] = dp[l] + dp[r];
        }
        else if (s[pos[i]] == '0') {
            dp[i] = dp[l];
        }
        else {
            dp[i] = dp[r];
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int p;
        char c;
        cin >> p >> c; 
        p--;
        s[p] = c;

        int v = vert[p];
        while (v) {
            int i = v;
            int l = i * 2, r = i * 2 + 1;


            //debug(v); debug(dp[l]); debug(dp[r]);

            if (s[pos[i]] == '?') {
                dp[i] = dp[l] + dp[r];
            }
            else if (s[pos[i]] == '0') {
                dp[i] = dp[l];
            }
            else {
                dp[i] = dp[r];
            }
            v /= 2;
        }
        cout << dp[1] << endl;
    }
}