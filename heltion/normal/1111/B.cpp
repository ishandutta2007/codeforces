#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define maxn 120000
LL a[maxn];
int main(){
	ios::sync_with_stdio(false);
	LL n, k, m, s = 0;
	double ans = 0;
	cin >> n >> k >> m;
	for(int i = 1; i <= n; i += 1){
		cin >> a[i];
		s += a[i];
	}
	sort(a + 1, a + n + 1); 
	for(int i = 0; i < n && i <= m; i += 1)
		ans = max(ans, 1.0 * ((s -= a[i]) + min(m - i, k * (n - i))) / (n - i));
	cout << setprecision(10) << ans;
}