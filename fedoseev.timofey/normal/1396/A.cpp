#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>
#include <functional>
#include <cassert>
#include <bitset>
#include <chrono>
 
using namespace std;
 
typedef long long ll;

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
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  if (n == 1) {
    cout << "1 1\n" << -a[0] << '\n';
    cout << "1 1\n" << 0 << '\n';
    cout << "1 1\n" << 0 << '\n';
  } else {
    int x, y;
    gcd(n, n - 1, x, y);
    cout << 1 << ' ' << n << '\n';
    for (int i = 0; i < n; ++i) {
      cout << (ll)-n * x * a[i] << ' ';
    }
    cout << '\n';
    cout << 1 << ' ' << n - 1 << '\n';
    for (int i = 0; i + 1 < n; ++i) {
      cout << (ll)-(n - 1) * y * a[i] << ' ';
    }
    cout << '\n';
    cout << n << ' ' << n << '\n';
    for (int i = n - 1; i <= n - 1; ++i) {
      cout << (ll)-(n - 1) * y * a[i] << ' ';
    }
    cout << '\n';
  } 
}