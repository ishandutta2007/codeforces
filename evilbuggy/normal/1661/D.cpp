#include <bits/stdc++.h>
using namespace std;

const int maxn = 300005;

long long b[maxn], x[maxn], a[maxn];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	int k; cin >> k;
	for(int i = 1; i <= n; i++){
		cin >> b[i]; x[i] = 0;
	}
	a[n + 1] = 0;
	long long ans = 0;
	long long sum = 0;
	long long mxv = 0;
	for(int i = n; i >= 1; i--){
		if(i >= k){
			long long tmp = b[i] + sum - a[i + 1];
			x[i] = (max(0LL, tmp) + k - 1)/k;
		}else{
			x[i] = 0;
		}
		a[i] = k*x[i] - sum + a[i + 1];
		if(i < k && a[i] < b[i]){
			mxv = max(mxv, (b[i] - a[i] + i - 1)/i);
		}
		ans += x[i];
		sum += x[i]; if(i + k <= n)sum -= x[i + k];
	}
	ans += mxv;
	cout << ans << '\n';

	return 0;
}