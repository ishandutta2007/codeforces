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

const int N = 5007;

int ans[N][N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int l = 0; l < n; ++l) {
		ans[l][l] = a[l];
	}

	for (int len = 1; len < n; ++len) {
		for (int l = 0; l + len < n; ++l) {
			int r = l + len;
			ans[l][r] = ans[l][r - 1] ^ ans[l + 1][r];
		}
	}

	for (int len = 1; len <= n; ++len) {
        for (int l = 0; l + len < n; ++l) {
            int r = l + len;
            ans[l][r] = max(ans[l][r], ans[l + 1][r]);
            ans[l][r] = max(ans[l][r], ans[l][r - 1]);
        }
    }
    
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int l, r;
		cin >> l >> r;
		--l, --r;
		cout << ans[l][r] << '\n';
	}
}