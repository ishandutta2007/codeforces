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

const int A = 1234567;
const int B = 123456;
const int C = 1234;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    for (int i = 0; i <= (n / A) + 1; ++i) {
    	for (int j = 0; j <= (n / B); ++j) {
    		ll cur = n - ((ll)i * A + (ll)j * B);
    		if (cur >= 0 && (cur % C) == 0) {
    			cout << "YES\n";
    			return 0;
    		}
    	}
    }
    cout << "NO\n";
}