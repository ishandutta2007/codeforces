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

const int N = 1e5;

map <int, int> cnt;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    string s;
    cin >> s;
    int m = s.size();
    vector <int> b(m);
    for (int i = 0; i < m; ++i) {
    	b[i] = s[i] - '0';
    }
    int all = 0;
    for (int l = 0; l < m; ++l) {
    	int s = 0;
    	for (int r = l; r < m; ++r) {
    		s += b[r];
    		++cnt[s];
    		++all;
    	}
    }
    ll ans = 0;
    for (int l = 0; l < m; ++l) {
    	int s = 0;
    	for (int r = l; r < m; ++r) {
    		s += b[r];
    		if (s != 0) {
	    		if (!(n % s) ) {
	    			ans += cnt[n / s];
	    		}
    		}
    		else {
    			if (n == 0) ans += all;
    		}
    	}
    }
    cout << ans << '\n';
}