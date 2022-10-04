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
    int n, m;
    cin >> n >> m;
    vector <vector <int>> a(n, vector <int> (m));
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < m; ++j) {
    		char c;
    		cin >> c;
    		if (c == '#') a[i][j] = 1;
    		else a[i][j] = 0;
    	}
    }
    vector <vector <int>> b(n, vector <int> (m));
    for (int i = 1; i + 1 < n; ++i) {
    	for (int j = 1; j + 1 < m; ++j) {
    		bool fl = 1;
    		for (int dx = -1; dx <= 1; ++dx) {
    			for (int dy = -1; dy <= 1; ++dy) {
    				if (dx == 0 && dy == 0) continue;
    				if (!a[i + dx][j + dy]) {
    					fl = 0;
    					break;
    				}
    			}
    		}
    		if (fl) {
    			for (int dx = -1; dx <= 1; ++dx) {
    				for (int dy = -1; dy <= 1; ++dy) {
    					if (dx == 0 && dy == 0) continue;
    					b[i + dx][j + dy] = 1;
    				}
    			}
    		}
    	}
    }
    if (a == b) {
    	cout << "YES\n";
    }
    else {
    	cout << "NO\n";
    }
}