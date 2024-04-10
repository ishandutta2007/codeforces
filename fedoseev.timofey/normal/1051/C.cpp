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

const int N = 101;
int cnt[N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) ++cnt[a[i]];
    int res = 0;
	for (int i = 0; i < N; ++i) {
		if (cnt[i] == 1) ++res;
	}
	int who = -1;
	if (res & 1) {
		for (int i = 0; i < N; ++i) {
			if (cnt[i] > 2) who = i;
		}
	}
	if ((res & 1) && who == -1) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	for (int i = 0; i < n; ++i) {
		if (cnt[a[i]] == 1 && (res & 1)) {
			cout << 'A';
			--res;
		}
		else if (cnt[a[i]] == 1) {
			cout << 'B';
			--res;
		}
		else {
			if (a[i] == who) {
				cout << 'B';
				who = -1;
			}
			else {
				cout << 'A';
			}
		}
	}
}