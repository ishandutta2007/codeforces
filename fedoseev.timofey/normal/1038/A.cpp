#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false); cout.setf(ios::fixed); cout.precision(20); cin.tie(0);
	#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	map <char, int> cnt;
	for (auto c : s) ++cnt[c];
	if (cnt.size() < k) {
		cout << "0\n";
		return 0;
	}
	int mn = 1e9;
	for (auto p : cnt) mn = min(mn, p.second);
	cout << mn * k << '\n';
}