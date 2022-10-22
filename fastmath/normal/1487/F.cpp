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

const int B = 300, A = 40;

int dp[2 * B][2 * A], ndp[2 * B][2 * A];

signed main() {
    #ifdef ONLINE_JUDGE
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    string s;
    cin >> s;

    const int INF = 1e18;
    FOR (i, 2 * B)
        FOR (j, 2 * A)
            dp[i][j] = INF;

    const int L = 70;
    reverse(all(s));
    while (s.size() < L)
        s += '0';

    dp[B][A] = 0;
    for (int i = L; i; --i) {
        FOR (a, 2 * B)
            FOR (b, 2 * A)
                ndp[a][b] = INF;
        int c = s[i - 1] - '0';
        int len = i;
        for (int bal = -B; bal < B; ++bal) {
            for (int add = -A; add < A; ++add) {
                int x = dp[bal + B][add + A];
                if (x == INF)
                    continue;
                for (int op = -100; op < 100; ++op) {
                    int have = bal + op + add * 10;
                    int new_bal = bal + op;
                    int new_add = have - c;
                    if (abs(new_bal) < B && abs(new_add) < A) {
                        ckmin(ndp[new_bal + B][new_add + A], x + abs(op) * len);
                    }
                }
            }
        }
        FOR (a, 2 * B)
            FOR (b, 2 * A)
                dp[a][b] = ndp[a][b];
    }

    int ans = INF;
    FOR (i, 2 * B)
        ckmin(ans, dp[i][A]);
    cout << ans << endl;
}