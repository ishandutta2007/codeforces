#include <bits/stdc++.h>
using namespace std;

vector <int> a;

int main(){
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++){
		int x; scanf("%d", &x);
		if (x > 0) a.push_back(x);
		else a.push_back(-x);
	}
	long long ans = 0;
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++){
		int pos = upper_bound(a.begin(), a.end(), a[i] * 2) - a.begin();
		ans += pos - i - 1;
	}
	printf("%I64d\n", ans);
	return 0;
}