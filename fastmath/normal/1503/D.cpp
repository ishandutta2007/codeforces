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
const int N = 5e5+7;
int n, x[N], y[N];
bool inv[N];
int r[N];
int mn[N], mx[N];
signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n;
    FOR (i, n) {
    	cin >> x[i] >> y[i];
    	if (y[i] < x[i]) {
    		swap(x[i], y[i]);
    		inv[x[i]] = 1;
    	}
    	if (y[i] <= n) {
    		cout << -1 << endl;
    		exit(0);
    	}
    	r[x[i]] = y[i];
    }
    mn[0] = N;	
    for (int i = 1; i <= n; ++i) {
    	mn[i] = min(mn[i - 1], r[i]);
    }
    for (int i = n; i; --i) {
    	mx[i] = max(mx[i + 1], r[i]);
    }

    vi cut;
    for (int i = 1; i < n; ++i) {
    	if (mn[i] > mx[i + 1]) {
    		cut.app(i);
    	}
    }
    cut.app(n);

    /*
    for (int i = 1; i <= n; ++i) {
    	cout << r[i] << ' ';
    }
    cout << endl;
    */

    int l = 1, ans = 0;
    trav (R, cut) {
    	vi last(2, N);
    	vi cost(2);
    	for (int i = l; i <= R; ++i) {
    		bool ok = 0;
    		FOR (t, 2) {
    			if (last[t] > r[i]) {
    				last[t] = r[i];
    				ok = 1;
    				cost[t ^ inv[i]]++;
    				break;
    			}
    		}
    		if (!ok) {
    			cout << -1 << endl;
    			exit(0);
    		}
    	}
    	ans += min(cost[0], cost[1]);
    	l = R + 1;
    }
    cout << ans << endl;
}