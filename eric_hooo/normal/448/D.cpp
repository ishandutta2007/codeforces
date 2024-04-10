#include <bits/stdc++.h>
using namespace std;

long long n, m, k;

bool check(long long mid){
	long long y = m, ans = 0;
	for (long long x = 1; x <= n; x++){
		while (x * y > mid) y--;
		ans += y;
	}
	return ans >= k;
}

int main(){
	cin >> n >> m >> k;
	long long l = 0, r = n * m + 1, ans;
	while (l + 1 < r){
		long long mid = (l + r) >> 1;
		if (check(mid)) r = mid;
		else l = mid;
	}
	cout << r << endl;
	return 0;
}