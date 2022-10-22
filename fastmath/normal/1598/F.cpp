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
const int INF = 1e9+7;
int n;
int dp[1 << 20][2];
vi d[20];
int val[20], mn[20];
int sum[1 << 20];
vi rec[20], pos[20];
vi same[20];
signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n;
    V <string> a(n);
    cin >> a;

    FOR (i, n) {
        int cur = 0;
        mn[i] = 0;

        pos[i] = {0};
        rec[i] = {0};
        same[i] = {0};

        d[i].resize(a[i].size() * 2 + 1);

        int shift = a[i].size();

        int len = 0;
        each (c, a[i]) {
            len++;
            if (c == '(') cur++;
            else cur--;

            d[i][cur + shift]++;
            same[i].app(d[i][cur + shift]);

            if (ckmin(mn[i], cur)) {
                pos[i].app(len);
                rec[i].app(cur);                
            }
        }
        val[i] = cur;
    }

    FOR (i, 1 << 20) {
        FOR (j, 2) {
            dp[i][j] = -INF;
        }
    }

    FOR (mask, 1 << n) {
        FOR (i, n) {
            if (Bit(mask, i)) {
                sum[mask] = sum[mask ^ (1 << i)] + val[i];
            }
        }
    }

    auto get = [&] (int i, int bal) {
        int l = 0, r = (int)rec[i].size() - 1;

        assert(rec[i][r] + bal < 0);

        while (l < r - 1) {
            int m = (l + r) / 2;
            if (rec[i][m] + bal < 0) {
                r = m;
            }
            else {
                l = m;
            }
        }
        int cut = pos[i][r];
        return same[i][cut - 1];
    };

    dp[0][1] = 0;
    FOR (mask, 1 << n) {
        FOR (t, 2) {    
            if (dp[mask][t] >= 0) {
                FOR (add, n) {
                    if (!Bit(mask, add)) {
                            if (sum[mask] + mn[add] >= 0) {
                                if (t) {
                                    int neu = 0;
                                    if (sum[mask] <= a[add].size()) {
                                        neu = d[add][-sum[mask] + a[add].size()];
                                    }
                                    ckmax(dp[mask ^ (1 << add)][t], dp[mask][t] + neu);
                                }
                                else {
                                    ckmax(dp[mask ^ (1 << add)][t], dp[mask][t]);
                                }
                            }
                            else {
                                if (t) {
                                    ckmax(dp[mask ^ (1 << add)][0], dp[mask][t] + get(add, sum[mask]));    
                                }
                                else {
                                    ckmax(dp[mask ^ (1 << add)][0], dp[mask][t]);
                                }
                            }
                    }
                }                
            }
        }
    }

    int t = (1 << n) - 1;
    cout << max(dp[t][0], dp[t][1]) << endl;
}