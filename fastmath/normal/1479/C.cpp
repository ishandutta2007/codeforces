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
signed main() {
    #ifdef ONLINE_JUDGE
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int L, R;
    cin >> L >> R;
    V <vi> ed;
    auto edge = [&] (int u, int v, int c) {
    	ed.app({u, v, c});
    };
    vi who(20);
    int cur_pow = 0;
    for (int i = 21; i > 1; i--) {
    	edge(i, 22, 1);
    	int have = 1;
    	int pw = 0;
    	for (int j = 21; j > i; j--) {
    		edge(i, j, have);
    		have += 1 << pw;
    		pw++;
    	}
    	who[cur_pow] = i;
    	cur_pow++;
    }
    if (L == 1) {
    	edge(1, 22, 1);
    	L++;
    }
    auto getbit = [&] (int x, int i) {
    	return (x >> i) & 1;
    };
    if (L <= R) {
    	int len = R - L + 1;
    	int ptr = L;
    	FOR (bit, 20) {
    		if (getbit(len, bit)) {
    			edge(1, who[bit], ptr - 1);
    			ptr += 1 << bit;
    		}
    	}
    }
    cout << "YES" << endl;
    cout << 22 << ' ' << ed.size() << endl;
    trav (e, ed) {
    	cout << e << endl;
    }
}