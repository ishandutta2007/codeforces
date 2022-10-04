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
    vector <int> l(n), r(n);
    for (int i = 0; i < n; ++i) cin >> l[i];
    for (int i = 0; i < n; ++i) cin >> r[i];
    vector <int> a(n);
	int cnt = 0;
	for (int i = n; i >= 1; --i) {
		for (int j = 0; j < n; ++j) {
			if (l[j] + r[j] == cnt) {
				a[j] = i;
			}
		}
		for (int j = 0; j < n; ++j) {
			if (a[j] == i) ++cnt;
		}
	}
	for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (int j = 0; j < i; ++j) {
            if (a[j] > a[i]) ++cnt;
        }
        if (cnt != l[i]) {
            cout << "NO\n";
            return 0;
        }
        cnt = 0;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] > a[i]) ++cnt;
        }
        if (cnt != r[i]) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        cout << a[i] << ' ';
    }
}