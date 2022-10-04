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

// a ^ 2 - b ^ 2 = (a - b) * (a + b)

bool prime(ll x) {
	for (ll d = 2; d * d <= x; ++d) {
		if ((x % d) == 0) return 0;
	}
	return 1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
    	ll a, b;
    	cin >> a >> b;
    	if (a - b == 1 && prime(a + b)) {
    		cout << "YES\n";
    	}
    	else {
    		cout << "NO\n";
    	}
    }
}