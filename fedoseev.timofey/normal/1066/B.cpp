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
    int n, r;
    cin >> n >> r;
    vector <int> a(n);
   	for (int i = 0; i < n; ++i) cin >> a[i];
   	int l = 0;
   	int ans = 0;
   	while (l < n) {
   		++ans;
   		int idx = -1;
   		for (int i = 0; i < n; ++i) {
   			if (a[i] && i - r + 1 <= l && i + r - 1 >= l) {
   				idx = i;
   			}
   		}
   		if (idx == -1) {
   			cout << "-1\n";
   			return 0;
   		}
   		l = idx + r;
   	}
   	cout << ans << '\n';
}