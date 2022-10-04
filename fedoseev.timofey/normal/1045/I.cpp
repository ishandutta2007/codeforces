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
    int n;
    cin >> n;
    map <int, int> cnt;
    for (int i = 0; i < n; ++i) {
    	string s;
    	cin >> s;
    	int cur = 0;
    	for (auto c : s) {
    		cur ^= (1 << (c - 'a'));
    	}
    	++cnt[cur];
    }
    ll ans = 0;
    for (auto &p : cnt) ans += (ll)(p.second) * (p.second - 1) / 2;
    for (int c = 0; c < 26; ++c) {
    	for (auto &p : cnt) {
    		int cur = p.first;
    		if (cur & (1 << c)) {
    			cur ^= (1 << c);
    			if (cnt.count(cur)) {
    				ans += (ll)cnt[cur] * p.second;
    			}
    		}
    	}
    }
    cout << ans << '\n';
}