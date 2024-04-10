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

int get(string s) {
	int cur = 0;
	for (auto c : s) {
		if (c == 'A') cur |= (1 << 0);
		if (c == 'B') cur |= (1 << 1);
		if (c == 'C') cur |= (1 << 2);
	}
	return cur;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector <int> mem(8, (int)1e8);
    for (int i = 0; i < n; ++i) {
    	string s; int c;
    	cin >> c >> s;
    	mem[get(s)] = min(mem[get(s)], c);
    }
    int ans = 1e9;
    for (int i = 1; i < 8; ++i) {
    	for (int j = 1; j < 8; ++j) {
    		for (int k = 1; k < 8; ++k) {
    			if ((i | j | k) == 7) {
    				int cur = 0;
    				cur += mem[i];
    				if (i != j) cur += mem[j];
    				if (k != j) cur += mem[k];
    				ans = min(ans, cur);
    			}
    		}
    	}
    }
    if (ans > (int)(1e7)) cout << "-1\n";
    else cout << ans << '\n';
}