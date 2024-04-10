#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef long double ld;

using namespace std;
const int MAXN = 1200000;

int n, m;
int cc[MAXN];
int a[MAXN];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		if (a[i] <= m)
			++cc[a[i]];
	}
	for (int i = m; i >= 1; --i) {
		for (int j = i + i; j <= m; j += i)
			cc[j] += cc[i];
	}
	pair<int, int> mx = make_pair(0, 1);
	for (int i = 1; i <= m; ++i)
		mx = max(mx, make_pair(cc[i], i));
	int aa = mx.second;
	vector<int> ans;
	ll go = 1;
	for (int i = 0; i < n; ++i)
		if (aa % a[i] == 0)
			ans.push_back(i + 1), go = go * a[i] / __gcd(go, (ll)a[i]);
	printf("%lld %d\n", go, (int)ans.size());
	for (int i = 0; i < (int)ans.size(); ++i)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}