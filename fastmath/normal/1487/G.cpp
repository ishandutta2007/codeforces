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

//need define int long long
namespace Stuff {
const int MOD = 998244353;
int mod(int n) {
    n %= MOD;
    if (n < 0) return n + MOD;
    else return n;
}   
int fp(int a, int p) {
    int ans = 1, c = a;
    for (int i = 0; (1ll << i) <= p; ++i) {
        if ((p >> i) & 1) ans = mod(ans * c);
        c = mod(c * c);
    }   
    return ans;
}   
int dv(int a, int b) { return mod(a * fp(b, MOD - 2)); }
};
struct M {
ll x;
M (int x_) { x = Stuff::mod(x_); }   
M () { x = 0; }
M operator + (M y) {
    int ans = x + y.x;
    if (ans >= Stuff::MOD)
        ans -= Stuff::MOD;
    return M(ans);
}
M operator - (M y) {
    int ans = x - y.x;
    if (ans < 0)
        ans += Stuff::MOD;
    return M(ans);            
}   
M operator * (M y) { return M(x * y.x % Stuff::MOD); }   
M operator / (M y) { return M(x * Stuff::fp(y.x, Stuff::MOD - 2) % Stuff::MOD); }   
M operator + (int y) { return (*this) + M(y); }
M operator - (int y) { return (*this) - M(y); }   
M operator * (int y) { return (*this) * M(y); }   
M operator / (int y) { return (*this) / M(y); }   
M operator ^ (int p) { return M(Stuff::fp(x, p)); }   
void operator += (M y) { *this = *this + y; }   
void operator -= (M y) { *this = *this - y; }   
void operator *= (M y) { *this = *this * y; }
void operator /= (M y) { *this = *this / y; }   
void operator += (int y) { *this = *this + y; }   
void operator -= (int y) { *this = *this - y; }   
void operator *= (int y) { *this = *this * y; }
void operator /= (int y) { *this = *this / y; }   
void operator ^= (int p) { *this = *this ^ p; }
bool operator == (M y) { return x == y.x; }
};  
std::ostream& operator << (std::ostream& o, const M& a)
{
    cout << a.x;
    return o;
}

const int N = 207;
M dp[N][N][N][3];
M sum[N][N];
M tot_A[N][N], tot_B[N][N];

signed main() {
    #ifdef ONLINE_JUDGE
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    dp[1][1][0][0] = dp[1][0][1][1] = 1;
    dp[1][0][0][2] = 24;
    for (int i = 1; i + 1 < N; ++i) {
        FOR (a, N - 1) {
            FOR (b, N - 1) {
                FOR (k, 3) {
                    auto x = dp[i][a][b][k];
                    FOR (add, 2) {
                        if (k != add) {
                            if (add == 0) {
                                dp[i + 1][a + 1][b][add] += x;
                            }
                            else {
                                dp[i + 1][a][b + 1][add] += x;
                            }
                        }
                    }
                    if (k < 2) {
                        dp[i + 1][a][b][2] += x * 24;
                    }
                    else {
                        dp[i + 1][a][b][2] += x * 23;
                    }
                }
            }
        }
    }


    int n;
    cin >> n;
    vi cnt(26);
    re(cnt);

    int A = n / 2;
    int B = (n + 1) / 2;

    FOR (i, N) {
        FOR (a, N) {
            FOR (b, N) {
                FOR (k, 3) {
                    sum[i][a] += dp[i][a][b][k];
                    if (i == A) {
                        tot_A[a][b] += dp[i][a][b][k];
                    }
                    if (i == B) {
                        tot_B[a][b] += dp[i][a][b][k];
                    }
                }
            }
        }
    }

    M ans = M(26) * M(26) * (M(25) ^ (n - 2));
    FOR (c, 26) {
        FOR (a, A + 1) {
            FOR (b, B + 1) {
                if (a + b > cnt[c]) {
                    ans -= sum[A][a] * sum[B][b];
                }
            }
        }
    }

    for (int i = N - 2; i >= 0; --i) {
        for (int j = N - 2; j >= 0; --j) {
            tot_B[i][j] += tot_B[i + 1][j] + tot_B[i][j + 1] - tot_B[i + 1][j + 1];
        }
    }

    auto get = [&] (int x, int y) {
        if (x >= N || y >= N)
            return M(0);
        ckmax(x, 0ll);
        ckmax(y, 0ll);
        return tot_B[x][y];
    };

    FOR (c1, 26) {
        FOR (c2, c1) {
            M bad = 0;
            FOR (a, N) {
                FOR (b, N) {
                    int wa = cnt[c1] - a + 1;
                    int wb = cnt[c2] - b + 1;
                    bad += tot_A[a][b] * get(wa, wb);
                }
            }
            ans += bad;
        }
    }
    cout << ans << endl;
}