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
#define FORN(i, n) for (int i = 1; i <= n; ++i)
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

const int N = 607, INF = 1e18;
int c[N][N], d[N][N];
bool used[N];

int pref[N], suf[N];

signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, m;
    cin >> n >> m;

    FOR (i, N) {
    	FOR (j, N) {
    		c[i][j] = d[i][j] = INF;
    	}
    }

    FOR (i, m) {
    	int u, v;
    	cin >> u >> v;
    	cin >> c[u][v];
    }

    auto mod = [&] (int x) {
    	x %= n;
    	if (x < 0) {
    		x += n;
    	}
    	return x;
    };

    FOR (S, n) {
    	d[S][S] = 0;
    	memset(used, 0, sizeof used);
    	FOR (t, n) {
    		int u = -1;
    		FOR (i, n) {
    			if (!used[i]) {
    				if (u == -1 || d[S][i] < d[S][u]) {
    					u = i;
    				}
    			}
    		}
    		used[u] = 1;

    		pref[0] = c[u][0];
    		for (int i = 1; i < n; ++i) {
    			pref[i] = min(pref[i - 1], c[u][i] - i);
    		}

    		suf[n] = INF;
    		for (int i = n - 1; i >= 0; --i) {
    			suf[i] = min(suf[i + 1], c[u][i] - i);
    		}

    		FOR (v, n) {
    			int t = mod(v - d[S][u]);
    			ckmin(d[S][v], pref[t] + t + d[S][u]);
    			ckmin(d[S][v], suf[t + 1] + t + n + d[S][u]);
    		}
    	}
    }

    FOR (i, n) {
    	FOR (j, n) {
    		cout << d[i][j] << ' ';
    	}
    	cout << endl;
    }
}