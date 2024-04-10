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
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, M, k;
    cin >> n >> M >> k;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int l = 0, r = n + 1;
	while (r - l > 1) {
		int m = (l + r) >> 1;
		int cl = n - m;
		int cnt = 1;
		int sum = 0;
		for (int i = cl; i < n; ++i) {
			if (a[i] + sum > k) {
				sum = a[i];
				++cnt;
			}
			else sum += a[i];
		}
		if (cnt <= M) l = m;
		else r = m;
	}
	cout << l << '\n';
}