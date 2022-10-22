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

int num[60];
int cnt[1 << 15];

signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, m, p;
    cin >> n >> m >> p;
    V <string> g(n);
    cin >> g;

    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

    vi tot(n);
    FOR (i, n) {
        FOR (j, m) {
            if (g[i][j] == '1') {
                tot[i] += 1ll << j;
            }
        }
    }

    int ans = -1;
    int msk = -1;
    FOR (t, 100) {
        int i = rng()%n;
        memset(cnt, 0, sizeof cnt);

        int ptr = 0;
        FOR (j, m) {
            if (Bit(tot[i], j)) {
                num[j] = ptr;
                ptr++;
            }
        }

        FOR (j, n) {
            int x = 0;
            FOR (bit, m) {
                if (Bit(tot[i], bit) && Bit(tot[j], bit)) {
                    x += 1ll << num[bit];
                }
            }
            cnt[x]++;
        }

        FOR (bit, ptr) {
            FOR (mask, 1 << ptr) {
                if (!Bit(mask, bit)) {
                    cnt[mask] += cnt[mask + (1 << bit)];
                }
            }
        }
        FOR (mask, 1 << ptr) {
            if (cnt[mask] * 2 >= n) {
                if (ckmax(ans, (int)bp(mask))) {
                    msk = 0;
                    FOR (bit, 60) {
                        if (Bit(tot[i], bit) && Bit(mask, num[bit])) {
                            msk += 1ll << bit;
                        }
                    }
                }
            }
        }
    }
    FOR (i, m) {
        cout << Bit(msk, i);
    }
    cout << endl;
}