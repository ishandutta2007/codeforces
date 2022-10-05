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

using namespace std;

typedef long long ll;

const int N = 1e7;

char ans[N];

struct word {
	int x;
	int ind;
	bool operator<(const word &other) const {
		return x < other.x;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin >> n;
	vector <word> e;
	vector <string> t(n);
	for (int i = 0; i < n; ++i) {
		string s;
		int x;
		cin >> s >> x;
		for (int j = 0; j < x; ++j) {
			int ind;
			cin >> ind;
			--ind;
			e.push_back({ind, i});
		}
		t[i] = s;
	}
	sort(e.begin(), e.end());
	int last = 0;
	int q = e.size();
	for (int i = 0; i < q; ++i) {
		auto cur = e[i];
		if (cur.x > last) {
			for (int j = last; j < cur.x; ++j) {
				ans[j] = 'a';
			}
			last = cur.x;
		}
		if (last > (cur.x + t[cur.ind].size() - 1)) continue;
		for (int j = last; j <= cur.x + t[cur.ind].size() - 1; ++j) {
			ans[j] = t[cur.ind][j - cur.x];
		}
		last = cur.x + t[cur.ind].size();
	}
	for (int i = 0; i < last; ++i) {
		cout << ans[i];
	}
}