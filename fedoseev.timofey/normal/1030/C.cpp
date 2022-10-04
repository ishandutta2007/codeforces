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
    vector <int> a(n);
    int sum = 0;
   	string s;
   	cin >> s;
   	for (int i = 0; i < n; ++i) a[i] = s[i] - '0';
   	for (int i = 0; i < n; ++i) sum += a[i];
    for (int k = 2; k <= n; ++k) {
    	if (sum % k) continue;
    	int cur = sum / k;
    	int c = 0;
    	bool fl = true;
    	for (int i = 0; i < n; ++i) {
    		c += a[i];
    		if (c == cur) {
    			c = 0;
    			continue;
    		}
    		else if (c > cur) {
    			fl = false;
    			break;
    		}
    	}
    	if (c != 0) {
    		fl = false;
    	}
    	if (fl) {
    		cout << "YES\n";
    		return 0;
    	}
    }
    cout << "NO\n";
}