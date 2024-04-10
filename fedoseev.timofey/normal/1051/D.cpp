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

const int md = 998244353;

void add(int &a, int b) {
	a += b;
	if (a >= md) a -= md;
}

const int N = 1100;

int dp[N][2 * N][4];

int bit(int i, int x) {
	return (x >> i) & 1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, k;
    cin >> n >> k;
    for (int mask = 0; mask < 4; ++mask) {
    	if (mask == 0 || mask == 3) dp[0][1][mask] = 1;
    	else dp[0][2][mask] = 1;
    }
    for (int i = 0; i + 1 < n; ++i) {
    	for (int j = 1; j <= k; ++j) {
    		for (int mask = 0; mask < 4; ++mask) {
    			for (int nmask = 0; nmask < 4; ++nmask) {
    				if (bit(0, nmask) == bit(1, nmask)) {
    					if (bit(0, nmask) == bit(0, mask) || bit(0, nmask) == bit(1, mask)) {
    						add(dp[i + 1][j][nmask], dp[i][j][mask]);
    					}
    					else {
    						add(dp[i + 1][j + 1][nmask], dp[i][j][mask]);
    					}
    				}
    				else {
    					if (mask == nmask) {
    						add(dp[i + 1][j][nmask], dp[i][j][mask]);
    					}
    					else if (bit(0, mask) != bit(0, nmask) && bit(1, mask) != bit(1, nmask)) {
    						add(dp[i + 1][j + 2][nmask], dp[i][j][mask]);
    					}
    					else {
    						add(dp[i + 1][j + 1][nmask], dp[i][j][mask]);
    					}
    				}
    			}
    		}
    	}
    }
    int ans = 0;
    for (int mask = 0; mask < 4; ++mask) {
    	add(ans, dp[n - 1][k][mask]);
    }
    cout << ans << '\n';
}