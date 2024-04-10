#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	map<int, long long> sum;
	long long ans = 0;
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		ans += (n - i + 1)*sum[x];
		sum[x] += i;
	}
	cout << ans << '\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while(t--)solve();

	return 0;
}