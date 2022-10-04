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

const int N = 15e6 + 1000;

int cnt[N];
bool bad[N];

int gcd(int a, int b) {
	return (b == 0 ? a : gcd(b, a % b));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    int g = 0;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
    	int x;
    	cin >> x;
    	g = gcd(g, x);
    	a[i] = x;
    }
    for (int i = 0; i < n; ++i) {
    	a[i] /= g;
    	++cnt[a[i]];
    }
    int ans = n;

    for (int i = 2; i < N; ++i) {
    	if (bad[i]) continue;
    	int cur = 0;
    	for (int j = i; j < N; j += i) {
    		bad[j] = 1;
    		cur += cnt[j];
    	}
    	ans = min(ans, n - cur);
    }
    if (ans != n) cout << ans << '\n';
    else cout << "-1\n";
}