#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdint>
#include <climits>
#include <random>
#include <chrono>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
#include <functional>

using namespace std;

int main() {
    #ifdef DEBUG
        freopen("input.txt", "r", stdin);
    #else
		ios_base::sync_with_stdio(false);
    #endif // DEBUG
    int n; cin >> n;
    vector<char> has(n);
    int cnt = 0, best = 0;
    for (int i = 0; i < 2 * n; i++) {
		int v; cin >> v; v--;
		if (has[v]) {
			has[v] = false;
			cnt--;
		} else {
			has[v] = true;
			cnt++;
		}
		best = max(best, cnt);
    }
    cout << best << endl;
	return 0;
}