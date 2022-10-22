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
signed main() {
    #ifdef ONLINE_JUDGE
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, q;
    cin >> n >> q;

    const int L = 320, B = 320;

    int sz = L * (B + 1);
    vi a(sz, 1), f(sz);
    for (int i = 2; i <= n; ++i)
        cin >> a[i];

    vi did(B + 1), push(B + 1);
    auto rebuild = [&] (int b) {
        int l = b * L;
        int r = l + L - 1;
        did[b] += push[b];
        for (int i = l; i <= r; ++i) {
            a[i] = max(1, a[i] - push[b]);
        }
        push[b] = 0;
        for (int i = l; i <= r; ++i) {
            if (a[i]/L < i/L) {
                f[i] = i;
            }
            else {
                f[i] = f[a[i]];
            }
        }
    };

    for (int i = 0; i <= B; ++i)
        rebuild(i);

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            if (l/L == r/L) {
                for (int i = l; i <= r; ++i) {
                    a[i] = max(1, a[i] - x);
                }
                rebuild(l/L);
                continue;
            }
            for (int i = l/L + 1; i < r/L; ++i) {
                push[i] += x;
                ckmin(push[i], 200000);
                if (did[i] <= L) {
                    rebuild(i);
                }
            }
            for (int i = l; i/L == l/L; i++)
                a[i] = max(1, a[i] - x);
            for (int i = r; i/L == r/L; i--)
                a[i] = max(1, a[i] - x);
            rebuild(l/L);
            rebuild(r/L);
        }
        else {
            int u, v;
            cin >> u >> v;
            if (v < u)
                swap(u, v);

            if (u == v) {
                cout << u << endl;
                continue;
            }

            auto par = [&] (int u) {
                return max(1, a[u] - push[u/L]);
            };

            while (f[u] != f[v]) {
                if (u/L > v/L) {
                    u = par(f[u]);
                }
                else if (v/L > u/L) {
                    v = par(f[v]);
                }
                else {
                    u = par(f[u]);
                    v = par(f[v]);
                }
            }
            while (u != v) {
                if (u > v) {
                    u = par(u);
                }
                else {
                    v = par(v);
                }
            }
            cout << u << endl;
        }
    }
}