#include <bits/stdc++.h>

using namespace std;

int n, a[1515], ans, anslen;
map<int, vector<pair<int, int>>> occ;


int main() {
	scanf("%d", &n);
	
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		for(int j = i, sum = 0; j > 0; j--) {
			sum += a[j];
			
			vector<pair<int, int>> &v = occ[sum];
			if(v.empty() || v.back().first != i) {
				v.emplace_back(i, j);
			}
		}
	}
	
	for(int i = 1; i <= n; i++) {
		for(int j = i, sum = 0; j > 0; j--) {
			sum += a[j];
			
			vector<pair<int, int>> &v = occ[sum];
			if(v[0].first == i) {	
				int cur = 1, k = 1, last = v[0].first;
				while(k < (int) v.size()) {
					int tt = v[k].second;
					if(tt <= last) k++;
					else {
						cur++;
						last = v[k].first;
						k++;
					}
				}
				if(cur > anslen) {
					anslen = cur;
					ans = sum;
				}
			}
		}
	}
	
	printf("%d\n", anslen);
	
	vector<pair<int, int>> &v = occ[ans];
	int last = -1, k = 0;
	while(k < (int) v.size()) {
		int tt = v[k].second;
		if(tt <= last) k++;
		else {
			printf("%d %d\n", v[k].second, v[k].first);
			last = v[k].first;
			k++;
		}
	}
	return 0;
}