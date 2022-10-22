#include <bits/stdc++.h>
using namespace std;

long long a[100010], sum[100010];
map <long long, long long> mp;

long long cnt(long long a){
	if (!mp.count(a)) return 0;
	return mp[a];
}

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++){
		scanf("%I64d", &a[i]);
		sum[i] = sum[i - 1] + a[i]; 
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++){
//		cout << i << endl;
		mp[sum[i - 1]]++;
		if (k == 1) ans += cnt(sum[i] - 1);
		if (k == -1) ans += cnt(sum[i] - 1) + cnt(sum[i] + 1);
		if (k == 1 || k == -1) continue;
		for (long long j = 1; abs(j) <= 1e15; j *= k){
			ans += cnt(sum[i] - j);
//			cout << "  " << j << "  " << cnt(sum[i] - j) << endl;
		}
	}
	printf("%I64d\n", ans);
	return 0;
}