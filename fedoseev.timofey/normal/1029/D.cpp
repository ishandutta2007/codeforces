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

map <int, int> cnt[11];

int get(int x) {
	int l = 0;
	while (x) {
		++l;
		x /= 10;
	}
	return l;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    vector <int> len(n);
    for (int i = 0; i < n; ++i) {
    	cin >> a[i];
    	len[i] = get(a[i]);
    	a[i] %= k;
    	++cnt[len[i]][a[i]];
    }
    vector <int> p(11);
    p[0] = 1;
    for (int i = 1; i <= 10; ++i) {
    	p[i] = ((ll)p[i - 1] * 10) % k;
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
    	--cnt[len[i]][a[i]];
    	for (int l = 1; l <= 10; ++l) {
    		int cur = ((ll)p[l] * a[i]) % k;
    		int need = (k - cur) % k;
    		ans += cnt[l][need];
    	}
    	++cnt[len[i]][a[i]];
    }
    cout << ans << '\n';
}