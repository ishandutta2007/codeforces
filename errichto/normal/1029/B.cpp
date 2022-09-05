#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	int answer = 0;
	for(int i = 0; i < n; ++i) {
		int cnt = 1;
		while(i + 1 < n && a[i+1] <= 2 * a[i]) {
			i++;
			cnt++;
		}
		answer = max(answer, cnt);
	}
	printf("%d\n", answer);
}