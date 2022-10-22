#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n, k;
	cin >> n >> k;
	long long a, b;
	if (k > n) a = k - n, b = n;
	else a = 1, b = k - 1;
	long long tmp = (a + b) / 2;
	long long ans = tmp - a + 1;
	if ((a + b) % 2 == 0) ans--;
	if (ans < 0) ans = 0;
	cout << ans << endl;
	return 0;
}