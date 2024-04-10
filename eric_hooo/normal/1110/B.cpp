#include <bits/stdc++.h>
using namespace std;

int a[100010];

int main(){
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	vector <int> v;
	long long ans = n;
	for (int i = 1; i < n; i++){
		v.push_back(a[i] - a[i - 1] - 1);
		ans += v.back();
	}
	sort(v.begin(), v.end());
	k--;
	for (int i = v.size() - 1; i >= 0; i--){
		if (k) ans -= v[i], k--;
	}
	printf("%I64d\n", ans);
	return 0;
}