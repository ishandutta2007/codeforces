#include <bits/stdc++.h>
using namespace std;

int a[100010];
int t[100010];

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	int last = 0, ans = 1;
	for (int i = 1; i < n; i++){
		if (a[i] == a[i - 1]){
			ans = max(ans, i - last);
			last = i;
		}
	}
	ans = max(ans, n - last);
	printf("%d\n", ans);
	return 0;
}