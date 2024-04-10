/*

Code for problem A by cookiedoth
Generated 09 Oct 2021 at 08.24 PM


 ] 
 
Il] 


~_^
=_=
>_<

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <cassert>
#include <random>
#include <cstring>
#include <numeric>
#include <random>
#include <utility>
#include <tuple>
#include <chrono>
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)
#define length(a) (int)a.size()

using namespace std;

template<class T> int chkmax(T &a, T b) {
	if (b > a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class T> int chkmin(T &a, T b) {
	if (b < a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class iterator> void output(iterator begin, iterator end, ostream& out = cerr) {
	while (begin != end) {
		out << (*begin) << " ";
		begin++;
	}
	out << endl;
}

template<class T> void output(T x, ostream& out = cerr) {
	output(x.begin(), x.end(), out);
}

void fast_io() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

const int MAX_N = 2e5 + 228;
int n, perm[MAX_N];
char ch[MAX_N];
ll a[MAX_N];
string s;

char flip(char c) {
	return c == 'L' ? 'R' : 'L';
}

signed main() {
	fast_io();
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	cin >> s;
	sort(a, a + n);
	deque<pair<int, char>> sol = {{0, s[0]}};
	for (int i = 1; i < n; ++i) {
		if (sol.back().second != s[i]) {
			sol.push_back({i, s[i]});
		} else if (sol.size() % 2 == 0) {
			sol.push_front({i, s[i]});
		} else {
			sol.push_front({i, flip(s[i])});
		}
	}
	for (int i = 0; i < n; ++i) {
		perm[sol[i].first] = i;
		ch[sol[i].first] = sol[i].second;
	}
	for (int i = 0; i < n; ++i) {
		cout << a[perm[i]] << ' ' << ch[i] << '\n';
	}
}