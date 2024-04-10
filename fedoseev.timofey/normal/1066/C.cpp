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

const int N = 2e5 + 7;

int where[N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int q;
    cin >> q;
    int l = 0, r = 1;
    while (q--) {
    	char c; int id;
    	cin >> c >> id;
    	if (c == 'L') {
    		where[id] = l--;
    	}
    	else if (c == 'R') {
    		where[id] = r++;
    	}
    	else {
    		int ans = min(where[id] - l - 1, r - where[id] - 1);
    		cout << ans << '\n';
    	}
    }
}