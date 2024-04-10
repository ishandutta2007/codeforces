#include <bits/stdc++.h>
using namespace std;

const int maxn = 3005;

long long suma[maxn];
int a[maxn], sumc[maxn];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	int k; cin >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	suma[0] = sumc[0] = 0;
	for(int i = 1; i <= n; i++){
		suma[i] = suma[i - 1] + a[i];
		sumc[i] = sumc[i - 1] + (a[i] == 0);
	}
	if(suma[n] + 1LL*k*sumc[n] < 0 || suma[n] - 1LL*k*sumc[n] > 0){
		cout << -1 << '\n';
		return 0;
	}
	long long ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			int cnt1 = sumc[j] - sumc[i - 1];
			int cnt2 = sumc[n] - cnt1;
			long long sum1 = suma[j] - suma[i - 1];
			long long sum2 = - suma[n] + sum1;
			long long mn = max(sum1 - 1LL*k*cnt1, sum2 - 1LL*k*cnt2);
			long long mx = min(sum1 + 1LL*k*cnt1, sum2 + 1LL*k*cnt2);
			if(mn <= mx){
				ans = max(ans, + mx + 1);
				ans = max(ans, - mn + 1);
			}
		}
	}
	cout << ans << '\n';

	return 0;
}