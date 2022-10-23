#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>

#include <algorithm>
#include <stack>
#include <bitset>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <vector>
#include <random>
#include <chrono>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

using u64 = unsigned long long;

int v[510005];

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int n, x; cin >> n >> x;
	
	while (n--) {
		int a; cin >> a;
		++v[a];
		while (v[a] == a + 1) {
			v[a] = 0;
			++v[++a];
		}
	}
	cout << (count(v, v + x, 0) == x ? "Yes\n" : "No\n");

	return 0;
}