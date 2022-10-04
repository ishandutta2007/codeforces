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
    vector <int> cnt(n);
    for (int i = 0; i + 1 < n; ++i) {
    	int a, b;
    	cin >> a >> b;
    	--a, --b;
    	if (max(a, b) != n - 1) {
    		cout << "NO\n";
    		return 0;
    	}
    	++cnt[min(a, b)];
    }
    vector <pair <int, int>> ed;
    int pt = 0;
    for (int i = 0; i < n; ++i) {
    	if (!cnt[i]) continue;
    	int ls = n - 1;
    	int cur = cnt[i] - 1;
    	while (cur) {
    		if (cnt[pt]) {
    			++pt;
    			continue;
    		}
    		if (pt >= i) {
    			cout << "NO\n";
    			return 0;
    		}
    		--cur;
    		ed.push_back(make_pair(ls, pt));
    		ls = pt;
    		++pt;
    	}
    	ed.push_back(make_pair(ls, i));
    }
    cout << "YES\n";
    for (auto p : ed) {
    	cout << p.first + 1 << ' ' << p.second + 1 << '\n';
    }
}