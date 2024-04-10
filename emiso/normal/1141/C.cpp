#include <bits/stdc++.h>

using namespace std;

long long n, a[400040], mini, tmp, ans[200020], freq[200020], flag = 1;

int main() {
	scanf("%lld", &n);
	for(int i = 1; i < n; i++) {
		scanf("%lld", &a[i]);
		tmp += a[i];
		mini = min(mini, tmp);
	}
	ans[0] = 1 - mini;
	if(ans[0] > n || ans[0] <= 0 || freq[ans[0]]) flag = 0;
	else freq[ans[0]] = 1;
	
	for(int i = 1; i < n; i++) {
		ans[i] = ans[i-1] + a[i];
		if(ans[i] > n || ans[i] <= 0 || freq[ans[i]]) flag = 0;
		else freq[ans[i]] = 1;
	}
	
	if(!flag) {
		puts("-1");
		return 0;
	}
	
	for(int i = 0; i < n; i++)
		printf("%lld ", ans[i]);
	return 0;
}