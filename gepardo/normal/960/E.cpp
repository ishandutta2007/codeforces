#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <sstream>
#include <tuple>
#include <vector>

using namespace std;
using namespace chrono;

#ifdef DEBUG
	#define LOCAL_INPUT_FILE
#else
	//#define USE_FILE_IO
#endif

#ifdef USE_FILE_IO
	#define INPUT_FILE "input.txt"
	#define OUTPUT_FILE "output.txt"
	#define cin ____cin
	#define cout ____cout
	ifstream cin(INPUT_FILE);
	ofstream cout(OUTPUT_FILE);
#else
	#ifdef LOCAL_INPUT_FILE
		#define cin ____cin
		ifstream cin("input.txt");
	#endif
#endif

const int infinity = (int)1e9 + 42;
const int64_t llInfinity = (int64_t)1e18 + 256;
const int module = (int)1e9 + 7; 
const long double eps = 1e-8;

mt19937_64 randGen(system_clock().now().time_since_epoch().count());

inline void raiseError(string errorCode) {
	cerr << "Error : " << errorCode << endl;
	exit(42);
}

template<int Modulo>
class Modular {
private:
	int value;
public:
	inline friend Modular binPow(Modular a, int pow) {
		Modular res = 1;
		while (pow) {
			if (pow & 1) {
				res *= a;
			}
			a *= a;
			pow >>= 1;
		}
		return res;
	}
	
	inline friend Modular rev(const Modular &a) {
		return binPow(a, Modulo - 2);
	}
	
	Modular()
		: value(0) {
	}
	
	Modular(int64_t v)
		: value((v % Modulo + Modulo) % Modulo)  {
	}
	
	inline Modular &operator=(int64_t b) {
		value = b % Modulo;
		return *this;
	}
	
	inline Modular &operator+=(const Modular &b) {
		value += b.value;
		value %= Modulo;
		return *this;
	}
	
	inline Modular &operator-=(const Modular &b) {
		value += Modulo;
		value -= b.value;
		value %= Modulo;
		return *this;
	}
	
	inline Modular &operator*=(const Modular &b) {
		value = ((int64_t)value * b.value) % Modulo;
		return *this;
	}
	
	inline Modular &operator/=(const Modular &b) {
		return *this *= rev(b);
	}
	
	inline friend Modular operator+(Modular a, const Modular &b) {
		return a += b;
	}
	
	inline friend Modular operator-(Modular a, const Modular &b) {
		return a -= b;
	}
	
	inline friend Modular operator*(Modular a, const Modular &b) {
		return a *= b;
	}
	
	inline friend Modular operator/(Modular a, const Modular &b) {
		return a /= b;
	}
	
	inline friend ostream &operator<<(ostream &os, const Modular &a) {
		return os << a.value;
	}
	
	inline int val() {
		return value;
	}
};
typedef Modular<(int)1e9 + 7> ModInt;

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> dOdd(n), dEven(n);
	vector<char> kind(n);
	vector< vector<int> > g(n);
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b; a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	function<void(int, int)> dfs = [&](int v, int p) {
		if (p >= 0) {
			kind[v] = kind[p] ^ 1;
		}
		(kind[v] ? dOdd : dEven)[v]++;
		for (int to: g[v]) {
			if (to == p) {
				continue;
			}
			dfs(to, v);
			dOdd[v] += dOdd[to];
			dEven[v] += dEven[to];
		}
	};
	dfs(0, -1);
	
	int kOdd = dOdd[0], kEven = dEven[0];
	ModInt all = 0;
	
	function<void(int, int)> dfs2 = [&](int v, int p) {
		vector< pair<ModInt, ModInt> > komps;
		komps.emplace_back(kEven - dEven[v], kOdd - dOdd[v]);
		for (int to: g[v]) {
			if (to == p) {
				continue;
			}
			dfs2(to, v);
			komps.emplace_back(dEven[to], dOdd[to]);
		}
		if (kind[v]) {
			for (auto &it: komps) {
				swap(it.first, it.second);
			}
		}
		ModInt ans = 1;
		ModInt preEven = 0, preOdd = 0;
		for (auto it: komps) {
			ModInt kEven = it.first, kOdd = it.second;
			ans += kEven + kOdd;
			ans += kEven - kOdd;
			ans += preEven * (kEven + kOdd);
			ans -= preOdd * (kEven + kOdd);
			ans += kEven * (preEven + preOdd);
			ans -= kOdd * (preEven + preOdd);
			preEven += kEven;
			preOdd += kOdd;
		}
		all += ans * a[v];
	};
	dfs2(0, -1);
	
	cout << all << endl;
	return 0;
}