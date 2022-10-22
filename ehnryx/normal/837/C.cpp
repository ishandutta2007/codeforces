#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define End return 0; }
#define of ios::sync_with_stdio(0); cin.tie(0);
#define story int main() {
#define The

The story of ugly_casework:

int ans = 0;
int n, a, b;
cin >> n >> a >> b;
vector<int> area(n);
vector<pair<int,int>> seal(n);

for (int i = 0; i < n; i++) {
	cin >> seal[i].first >> seal[i].second;
	area[i] = seal[i].first * seal[i].second;
}
for (int i = 0; i < n; i++) {
	for (int j = 0; j < i; j++) {
		if (seal[i].first + seal[j].first <= a && max(seal[i].second, seal[j].second) <= b)
			ans = max(ans, area[i] + area[j]);
		if (seal[i].first + seal[j].second <= a && max(seal[i].second, seal[j].first) <= b)
			ans = max(ans, area[i] + area[j]);
		if (seal[i].second + seal[j].first <= a && max(seal[i].first,seal[j].second) <= b)
			ans = max(ans, area[i] + area[j]);
		if (seal[i].second + seal[j].second <= a && max(seal[i].first,seal[j].first) <= b)
			ans = max(ans, area[i] + area[j]);
		if (seal[i].first + seal[j].first <= b && max(seal[i].second, seal[j].second) <= a)
			ans = max(ans, area[i] + area[j]);
		if (seal[i].first + seal[j].second <= b && max(seal[i].second, seal[j].first) <= a)
			ans = max(ans, area[i] + area[j]);
		if (seal[i].second + seal[j].first <= b && max(seal[i].first,seal[j].second) <= a)
			ans = max(ans, area[i] + area[j]);
		if (seal[i].second + seal[j].second <= b && max(seal[i].first,seal[j].first) <= a)
			ans = max(ans, area[i] + area[j]);
	}
}
cout << ans << endl;

The End