#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <cassert>


using namespace std;


#define sz(c) (int)(c).size()



int n, m;
int a[751];
vector<long long> dp;
multiset<int> used;


int good(long long x) {
	used.clear();
	for (int i = 0; i < n; i++) {
		used.insert(a[i]);
		x += a[i];
		while (x < 0) {
			x -= *used.begin();
			used.erase(used.begin());
		}
	}
	return (n - sz(used));
}


int ans[200001];


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	vector<pair<long long, int> > st;
	for (int i = 0; i < m; i++) {
		long long b;
		scanf("%lld", &b);
		st.push_back(make_pair(b, i));
	}
	sort(st.rbegin(), st.rend());
	int last = 0;
	for (int i = 0; i <= n; i++) {
		int l = last - 1, r = sz(st);
		while (l + 1 < r) {
			int mid = (l + r) >> 1;
			if (good(st[mid].first) <= i) {
				l = mid;
			} else {
				r = mid;
			}
		}
		for (int j = last; j <= l; j++) { 
			ans[st[j].second] = i;
		}
		last = l + 1;
	}
	for (int i = 0; i < m; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}