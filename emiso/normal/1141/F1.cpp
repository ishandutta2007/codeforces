#include <bits/stdc++.h>

using namespace std;

int n, a[1515], ans, anslen;
map<int, int> fst[1515];
set<int> ja;


int main() {
	scanf("%d", &n);
	
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		for(int j = i, sum = 0; j > 0; j--) {
			sum += a[j];
			if(!fst[i].count(sum))
				fst[i][sum] = j;
		}
	}
	
	for(int i = 1; i <= n; i++) {
		for(int j = i, sum = 0; j > 0; j--) {
			sum += a[j];
			if(!ja.count(sum)) {
				int cur = 1, k = i + 1, last = i;
				while(k <= n) {
					auto tt = fst[k].find(sum);
					if(tt == fst[k].end() || (*tt).second <= last) k++;
					else {
						cur++;
						last = k;
						k++;
					}
				}
				if(cur > anslen) {
					anslen = cur;
					ans = sum;
				}
			}
			ja.insert(sum);
		}
	}
	
	printf("%d\n", anslen);
	
	int last = -1, k = 0;
	while(k <= n) {
		auto tt = fst[k].find(ans);
		if(tt == fst[k].end() || (*tt).second <= last) k++;
		else {
			printf("%d %d\n", (*tt).second, k);
			last = k;
			k++;
		}
	}
	
	return 0;
}