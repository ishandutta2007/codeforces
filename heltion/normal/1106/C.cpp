#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define maxn 360000
LL a[maxn];
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < n; i += 1) cin >> a[i];
	sort(a, a + n);
	LL ans = 0;
	for(int i = 0; i < n / 2; i += 1) ans += (a[i] + a[n - 1 - i]) * (a[i] + a[n - 1 - i]);
	cout << ans << endl;
}