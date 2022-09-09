//Author: Heltion
//Date: 2019-06-19
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(12);
	LL a[3], d;
	cin >> a[0] >> a[1] >> a[2] >> d;
	sort(a, a + 3);
	cout << max(0LL, d - abs(a[1] - a[0])) + max(0LL, d - abs(a[1] - a[2]));
	return 0;
}