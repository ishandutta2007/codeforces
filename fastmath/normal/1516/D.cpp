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

const int N = 1e5+7, LG = 20;
int n, q;
bool is[N];
vi p[N];
int go[N][LG];
int last[N];

signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    for (int i = 2; i < N; ++i) {
    	is[i] = 1;
    }
    for (int i = 2; i < N; ++i) {
    	if (is[i]) {
    		p[i] = {i};
    		for (int j = i * 2; j < N; j += i) {
    			is[j] = 0;
    			p[j].app(i);
    		}
    	}
    }

    cin >> n >> q;
    vi a(n);
    cin >> a;

    FOR (i, N) {
    	last[i] = n;
    }

    FOR (i, LG) {
    	go[n][i] = n;
    }

    int r = n;
    for (int i = n - 1; i >= 0; --i) {
    	trav (e, p[a[i]]) {
    		ckmin(r, last[e]);
    		last[e] = i;
    	}
    	go[i][0] = r;
    	for (int j = 1; j < LG; ++j) {
    		go[i][j] = go[go[i][j - 1]][j - 1];
    	}
    }

    while (q--) {
    	int l, r;
    	cin >> l >> r;
    	l--; r--;
    	int ans = 1;
    	for (int i = LG - 1; i >= 0; --i) {
    		if (go[l][i] <= r) {
    			l = go[l][i];
    			ans += 1 << i;
    		}
    	}
    	cout << ans << endl;
    }
}