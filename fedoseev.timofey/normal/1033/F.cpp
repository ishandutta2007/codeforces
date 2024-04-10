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
    int w, n, m;
    cin >> w >> n >> m;
    vector <int> C(1 << w);
    for (int i = 0; i < n; ++i) {
    	int x;
    	cin >> x;
    	++C[x];
    }
    vector <int> p3(w + 1);
    p3[0] = 1;
    for (int i = 1; i <= w; ++i) p3[i] = p3[i - 1] * 3;
    vector <int> convert(1 << w);
	for (int x = 0; x < (1 << w); ++x) {
		for (int i = 0; i < w; ++i) {
			if (x & (1 << i)) convert[x] += p3[i];
		}
	}
	vector <int> cnt(p3[w]);
	for (int i = 0; i < (1 << w); ++i) {
		for (int j = 0; j < (1 << w); ++j) {
			cnt[convert[i] + convert[j]] += C[i] * C[j];
		}
	}
	while (m--) {
		string s;
		cin >> s;
		reverse(s.begin(), s.end());
		vector <int> a[2];
		for (int i = 0; i < w; ++i) {
			if (s[i] == 'A') {
				a[0].push_back(0);
				a[1].push_back(1);
			}
			else if (s[i] == 'O') {
				a[0].push_back(0);
				a[1].push_back(-1);
			}
			else if (s[i] == 'X') {
				a[0].push_back(0);
				a[1].push_back(2);
			}
			else if (s[i] == 'a') {
				a[0].push_back(2);
				a[1].push_back(-1);
			}
			else if (s[i] == 'o') {
				a[0].push_back(1);
				a[1].push_back(2);
			}
			else if (s[i] == 'x') {
				a[0].push_back(1);
				a[1].push_back(-1);
			}
		}
		ll ans = 0;
		for (int i = 0; i < (1 << w); ++i) {
			int mask = 0;
			bool fl = 1;
			for (int j = 0; j < w; ++j) {
				int id = (i >> j) & 1;
				if (a[id][j] == -1) {
					fl = 0;
					break;
				}
				else {
					mask += p3[j] * a[id][j];
				}
			}
			if (fl) ans += cnt[mask];
		}
		cout << ans << '\n';
	}
}