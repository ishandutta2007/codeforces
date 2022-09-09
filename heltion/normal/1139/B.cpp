#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 240000;
int a[maxn];
int main(){
	ios::sync_with_stdio(false);
	LL ans = 0;
	int n, x = 1e9;
	cin >> n;
	for(int i = 1; i <= n; i += 1) cin >> a[i];
	for(int i = n; i and x; i -= 1){
		ans += min(x, a[i]);
		x = min(x, a[i]) - 1;
	}
	cout << ans;
}