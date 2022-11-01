#include <bits/stdc++.h>

using namespace std;

int n, a[100010], k, sum, tmp;
vector<int> quant;

void cant() {
	puts("No");
	exit(0);
}

int main() {
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	if(sum % k) puts("No");
	else {
		
		quant.push_back(-1);
		for(int i = 0; i < n; i++) {
			tmp += a[i];
			if(tmp == sum / k) {
				quant.push_back(i);
				tmp = 0;
			}
			else if(tmp > sum / k) cant();
		}
		
		if(quant.size() != k + 1) cant();
		puts("Yes");
		for(int i = 1; i < quant.size(); i++) {
			printf("%d ", quant[i] - quant[i-1]);
		}
		puts("");
	}
	return 0;
}