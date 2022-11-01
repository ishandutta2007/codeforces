#include <bits/stdc++.h>

using namespace std;

int n, a[2020], ans[2020];
vector<pair<int, int>> pos;

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		pos.emplace_back(a[i], i);
	}
	sort(pos.begin(), pos.end(), greater<pair<int, int>>());
	
	int quant = 0, tmp = 0;
	for(int i = 0; i < n; i++) {
		if(i && pos[i-1].first != pos[i].first) {
			quant += tmp;
			tmp = 1;
		} else tmp++;
		ans[pos[i].second] = 1 + quant;
	}
	
	for(int i = 0 ; i < n; i++) {
		printf("%d ", ans[i]);
	}
	
	return 0;
}