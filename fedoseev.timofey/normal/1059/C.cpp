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
    vector <int> used(n + 1);
    int g = 1;
    vector <int> ans;
    int alive = n;
    while (alive > 3) {
    	for (int i = 1; i <= n; ++i) {
    		if (used[i]) continue;
    		if (i % (2 * g)) {
    			ans.push_back(g);
    			used[i] = 1;
    			--alive;
    			if (alive <= 3) break;
    		}
    	}
    	g *= 2;
    }
    vector <int> have;
    for (int i = 1; i <= n; ++i) {
    	if (!used[i]) have.push_back(i);
    }
    vector <int> can;
    do {
    	vector <int> cur;
    	for (int i = 0; i < have.size(); ++i) {
    		g = 0;
    		for (int j = i; j < have.size(); ++j) {
    			g = gcd(g, have[j]);
    		}
    		cur.push_back(g);
    	}
    	can = max(can, cur);
    } 
    while (next_permutation(have.begin(), have.end()));
    for (int i = 0; i < can.size(); ++i) {
    	ans.push_back(can[i]);
    }
    for (int i = 0; i < n; ++i) {
    	cout << ans[i] << ' ';
    }
    cout << '\n';
}