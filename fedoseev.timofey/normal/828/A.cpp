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

using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n, a, b;
	cin >> n >> a >> b;
	int c = 0;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		if (x == 1) {
			if (a != 0) --a;
			else if (b != 0) {
				--b;
				++c;
			}
			else if (c != 0) {
				--c;
			}
			else {
				++ans;
			}
		}
		else {
			if (b != 0) {
				--b;
			}
			else {
				ans += 2;
			}
		}
	}
	cout << ans << endl;
}