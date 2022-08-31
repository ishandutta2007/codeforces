/*
   
   
   
   
 */
#include <cmath>
#include <cassert>
#include <cstring>

#include <algorithm>
#include <complex>
#include <limits>
#include <functional>
#include <random>
#include <chrono>
#include <stack>
#include <bitset>
#include <numeric>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>

using ll = long long;
using ull = unsigned long long;

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		string s; cin >> s;
		bool ans = true;
		if (s[0] == 'B') ans = false;
		if (s.back() == 'A') ans = false;
		int val = 0;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == 'A') ++val;
			else --val;
			if (val < 0) ans = false;
		}
		cout << (ans ? "Yes\n" : "No\n");
	}

	return 0;
}