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

// x1 * y2 = 2 * n * m / k

int gcd (int a, int b, int & x, int & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	int x1, y1;
	int d = gcd (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

int gcd(int a, int b) {
	return (b == 0 ? a : gcd(b, a % b));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m, k;
    cin >> n >> m >> k;
    int x = n, y = m;
    if (((ll)2 * n * m) % k) {
    	cout << "NO\n";
    	return 0;
    }
    bool fl = false;
    if ((k % 2) == 0) {
    	k /= 2;
    	fl = true;
    }
    int g = gcd(k, n);
    n /= g;
    k /= g;
    g = gcd(k, m);
    m /= g;
    k /= g;
    assert(k == 1); 
    if (!fl) {
    	if (2 * n <= x) n *= 2;
    	else if (2 * m <= y) m *= 2;
    }
    cout << "YES\n";
    cout << "0 0\n";
    cout << n << ' ' << 0 << '\n';
    cout << 0 << ' ' << m << '\n';
}