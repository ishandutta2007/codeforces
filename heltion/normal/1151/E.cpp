#include<bits/stdc++.h>
using LL = long long;
using namespace std;
constexpr int maxn = 120000;
int a[maxn];
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	LL ans = 0;
	for(int i = 1; i <= n; i += 1){
		cin >> a[i];
		if(a[i] > a[i - 1])
			ans += 1LL * (a[i] - a[i - 1]) * (n - a[i] + 1);
		else ans += 1LL * a[i] * (a[i - 1] - a[i]);
	}
	cout << ans;
}