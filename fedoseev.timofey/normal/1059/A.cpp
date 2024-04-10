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
    int n, L, a;
    cin >> n >> L >> a;
    int last = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
    	int x, y;
    	cin >> x >> y;
    	ans += (x - last) / a;
    	last = x + y;
    }
    ans += (L - last) / a;
    cout << ans << '\n';
}