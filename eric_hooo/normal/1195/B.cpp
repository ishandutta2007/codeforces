#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, k; cin >> n >> k;
	int l = 0, r = n;
	while (l < r){
		int x = (l + r) >> 1;
		if (1ll * x * (x + 1) / 2 - (n - x) >= k) r = x;
		else l = x + 1;
	}
	printf("%d\n", n - l);
	return 0;
}