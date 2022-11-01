#include <bits/stdc++.h>
#define N 1000500

using namespace std;
typedef long long LL;
inline int rd() {int r;scanf("%d",&r);return r;}

LL n, k, a, b, ans1, ans2;

int main() {
	cin >> n >> k;
	ans1 = n*k+1, ans2 = -1;
	cin >> a >> b;

	for (LL _=0;_<n;_++) {
		LL cur = _*k+a+b;
		LL tmp = __gcd(cur, n*k);
		ans1 = min(ans1, n*k / tmp);
		ans2 = max(ans2, n*k / tmp);
	}
	
	
	if (b-a < 0) b+=k;
	for (LL _=0;_<n;_++) {
		LL cur = _*k+b-a;
		LL tmp = __gcd(cur, n*k);
		ans1 = min(ans1, n*k / tmp);
		ans2 = max(ans2, n*k / tmp);
	}
	
	cout << ans1 << " " << ans2 << endl;
	
	return 0;
}