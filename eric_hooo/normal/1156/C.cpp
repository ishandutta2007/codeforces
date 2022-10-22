#include <bits/stdc++.h>
using namespace std;

int a[200010];
int n, m;

bool check(int x){
    if (x > n / 2) return 0;
	int p = n - x;
	for (int i = 0; i < x; i++){
		if (a[i + p] - a[i] < m) return 0;
	}
	return 1;
}

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	int l = 0, r = n;
	while (l < r){
		int mid = l + r + 1 >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	printf("%d\n", l);
	return 0;
}