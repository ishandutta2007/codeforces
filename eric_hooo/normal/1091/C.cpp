#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d", &n);
	vector <long long> ans;
	for (long long i = 1; i * i <= n; i++){
		if (n % i != 0) continue;
//		cout << i << " " << 1ll * (1ll + n - i + 1) * (n / i) / 2 << endl;
		ans.push_back(1ll * (1ll + n - i + 1) * (n / i) / 2);
		ans.push_back(1ll * (1ll + n - n / i + 1) * i / 2);
	}
	sort(ans.begin(), ans.end());
	ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
	for (int i = 0; i < ans.size(); i++){
		printf("%I64d ", ans[i]);
	}
	printf("\n");
	return 0;
}