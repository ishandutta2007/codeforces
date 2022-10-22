#include <bits/stdc++.h>
using namespace std;

int a[110];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	int ans = 0;
	for (int i = 0; i < n; i += 2){
		ans += a[i + 1] - a[i];
	}
	printf("%d\n", ans);
	return 0;
}