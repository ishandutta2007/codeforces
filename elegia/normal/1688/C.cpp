#include <cmath>
#include <cstring>

#include <algorithm>
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

using namespace std;

using ull = unsigned long long;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> par(26);
		for (int rep = 0; rep <= N * 2; ++rep) {
			string s; cin >> s;
			for (char c : s)
				par[c - 'a'] ^= 1;
		}
		int c = 0; while (!par[c]) ++c;
		cout << char(c + 'a') << '\n';
	}
	
	return 0;
}