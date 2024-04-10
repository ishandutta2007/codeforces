#include <bits/stdc++.h>

using namespace std;

int n, a[5005];

int Divide(int l,int r) {
	if (l > r)	return 0;
	int val=2147483647, minn=l;
	for (int i = l; i <= r; ++ i)	if (a[i] < val)	val = a[i], minn = i;
	int dis = a[minn];
	for (int i = l; i <= r; ++ i)	a[i] -= dis;
	int ret=min(r - l + 1, Divide(l,minn - 1) + Divide(minn + 1,r) + dis);
	return ret;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; ++ i)	cin >> a[i];
	int ans = Divide(1, n);
	cout << ans << endl;
	return 0;
}