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
signed main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		V <vi> ans(n, vi(n));

		vi ord;
		FOR (u, n) {
			int l = -1, r = ord.size();
			while (l < r - 1) {
				int m = (l + r) >> 1;
				cout << "1 " << ord[m] << ' ' << u << endl;
				int ans;
				cin >> ans;
				if (ans) {
					l = m;
				}
				else {
					r = m;
				}
			}
			ord.insert(ord.begin() + r, u);
		}

		vi cut(n);
		int ptr = n;
		for (int i = n - 1; i >= 0; --i) {
			if (ptr > i) {
				cut[i] = 1;
			}

			ckmin(ptr, i);
			while (ptr) {
				cout << "2 " << ord[i] << ' ';
				cout << ptr << ' ';
				FOR (i, ptr) {
					cout << ord[i] << ' ';
				}
				cout << endl;

				int ans;
				cin >> ans;
				if (ans) {
					ptr--;
				}
				else {
					break;
				}
			}
		}

		FOR (i, n) {
			for (int j = i; j < n; ++j) {
				ans[ord[i]][ord[j]] = 1;
			}
		}
		FOR (i, n) {
			for (int j = i; j < n; ++j) {
				ans[ord[j]][ord[i]] = 1;
				if (cut[j]) {
					break;
				}
			}
		}

		cout << 3 << endl;
		FOR (i, n) {
			FOR (j, n) {
				cout << ans[i][j];
			}
			cout << endl;
		}

		int com;
		cin >> com;
	}
}