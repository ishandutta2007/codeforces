#include<bits/stdc++.h>
using LL = long long;
using namespace std;
constexpr int maxn = 120000;
LL a[maxn]; 
int main(){
	ios::sync_with_stdio(false);
	int n;
	LL ans = 0;
	cin >> n;
	for(int i = 1; i <= n; i += 1){
		cin >> a[i + 1] >> a[i];
		ans += n * a[i] - a[i + 1];
		a[i] -= a[i + 1]; 
	} 
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i += 1) ans -= i * a[i];
	cout << ans;
}