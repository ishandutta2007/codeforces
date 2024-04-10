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

const int N = 1e5+7;

int n;

string a[N];

string op[N << 2];
bool lo[N << 2], un[N << 2], unop[N << 2];

void relax(int v) {
	lo[v] = lo[v * 2 + 2] || (lo[v * 2 + 1] && !un[v * 2 + 2]);
	un[v] = un[v * 2 + 2] || (un[v * 2 + 1] && !lo[v * 2 + 2]);

	if (unop[v * 2 + 2] || (un[v * 2 + 1] && op[v * 2 + 2].size())) {
		op[v] = op[v * 2 + 2];
		unop[v] = 1;
	}
	else if (op[v * 2 + 2].size() && !lo[v * 2 + 1]) {
		op[v] = op[v * 2 + 2];
		unop[v] = 0;
	}
	else if (unop[v * 2 + 1]) {
		op[v] = op[v * 2 + 1];
		unop[v] = 1;
	}
	else if (op[v * 2 + 1].size()) {
		op[v] = op[v * 2 + 1];
		unop[v] = 0;
	}
	else {
		op[v] = "";
		unop[v] = 0;
	}
}

void build(int v, int tl, int tr) {
	if (tl == tr) {
		if (a[tl] == "lock") {
			lo[v] = 1;
		}
		else if (a[tl] == "unlock") {
			un[v] = 1;
		}
		else {
			op[v] = a[tl];
		}
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v * 2 + 1, tl, tm);
	build(v * 2 + 2, tm + 1, tr);
	relax(v);

	//debug(mp(tl, tr));
	//debug(op[v]); debug(unop[v]); debug(lo[v]); debug(un[v]);

}

void reset(int v, int tl, int tr, int i) {
	if (tl == tr) {
		lo[v] = un[v] = unop[v] = 0;
		op[v].clear();

		if (a[tl] == "lock") {
			lo[v] = 1;
		}
		else if (a[tl] == "unlock") {
			un[v] = 1;
		}
		else {
			op[v] = a[tl];
		}
		return;
	}

	int tm = (tl + tr) >> 1;
	if (i <= tm) {
		reset(v * 2 + 1, tl, tm, i);
	}
	else {
		reset(v * 2 + 2, tm + 1, tr, i);
	}
	relax(v);
}

signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n;
    FOR (i, n) {
    	cin >> a[i];
    }
    build(0, 0, n - 1);

    auto print = [&] () {
    	if (op[0].empty()) {
    		cout << "blue" << endl;
    	}
    	else {
    		cout << op[0] << endl;
    	}
    };

    print();

    int q;
    cin >> q;
    while (q--) {
    	int i; cin >> i;
    	i--;

    	cin >> a[i];
    	reset(0, 0, n - 1, i);

    	print();
    }
}