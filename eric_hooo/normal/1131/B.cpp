#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d", &n);
	int la = 0, lb = 0;
	int ans = 0;
	for (int i = 0; i < n; i++){
		int a, b; scanf("%d%d", &a, &b);
		ans += min(a, b) - max(la, lb) + 1 >= 0 ? min(a, b) - max(la, lb) + 1 : 0;
		la = a, lb = b, ans -= a == b;
	}
	printf("%d\n", ans + (la == lb));
	return 0;
}