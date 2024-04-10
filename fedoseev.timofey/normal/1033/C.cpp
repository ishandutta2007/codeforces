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
    int n;
    cin >> n;
    
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
    	cin >> a[i];
    }
    vector <int> idx;
    for (int i = 0; i < n; ++i) idx.push_back(i);

    vector <int> b(n);

    sort(idx.begin(), idx.end(), [&] (int i, int j) {
    	return a[i] < a[j];
    });

    reverse(idx.begin(), idx.end());

    for (int i : idx) {
    	b[i] = 0;
    	for (int d = a[i]; d < n; d += a[i]) {
    		int j = i - d;
    		if (j >= 0 && a[j] > a[i] && b[j] == 0) {
    			b[i] = 1;
    		}
    		j = i + d;
    		if (j < n && a[j] > a[i] && b[j] == 0) {
    			b[i] = 1;
    		}
    	}
    }
    for (int i = 0; i < n; ++i) {
    	if (b[i]) cout << 'A';
    	else cout << 'B';
    }
}