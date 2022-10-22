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
const int N = 3e5+7;
int par[N];
int root(int u) {
    if (u == par[u])
        return u;
    else
        return par[u] = root(par[u]);
}

ll c[N];
int d[N][3];
vi g[N];

vi s;
void dfs(int u, int p) {
    trav (i, g[u]) {
        int v = d[i][0] ^ d[i][1] ^ u;
        if (v != p) {
            if (u == d[i][0])
                swap(d[i][0], d[i][1]);
            dfs(v, u);
            s.app(i);
            while (s.size()) {
                int e = s.back();
                int V = d[e][0];
                int U = root(d[e][1]);
                assert(par[V] == V);
                if (c[V] + c[U] >= d[e][2]) {
                    cout << e + 1 << endl;
                    par[V] = root(U);
                    c[U] += c[V] - d[e][2];
                    s.pop_back();
                }
                else {
                    break;
                }
            }
        }
    }
}

vi ord;
signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, m, X;
    cin >> n >> m >> X;
    int sumV = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
        par[i] = i;
        sumV += c[i];
    }
    FOR (i, m) {
        cin >> d[i][0] >> d[i][1];
        d[i][2] = X;
        ord.app(i);
    }
    int cnt = 0, sumE = 0;
    auto comp = [&] (int e1, int e2) {
        return d[e1][2] < d[e2][2];
    };
    sort(all(ord), comp);
    trav (e, ord) {
        int u = root(d[e][0]), v = root(d[e][1]);
        if (u != v) {
            par[u] = v;
            g[d[e][0]].app(e);
            g[d[e][1]].app(e);
            sumE += d[e][2];
            cnt++;
        }        
    }
    if (sumE > sumV || cnt != n - 1) {
        cout << "NO" << endl;
        exit(0);
    }
    for (int i = 1; i <= n; ++i) {
        par[i] = i;
    }
    cout << "YES" << endl;
    dfs(1, 1);
    assert(s.empty());
}