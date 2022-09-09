//Author: Heltion
//Date: 07-22-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(const T& s = "NO"){cout << s; exit(0);}
constexpr int maxn = 320000;
LL a[maxn], b[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i += 1) cin >> a[i];
	for(int i = 1; i < n; i += 1) b[i] = -a[i + 1] + a[i];
	sort(b + 1, b + n);
	LL ans = a[n] - a[1];
	for(int i = 1; i < k; i += 1) ans += b[i];
	cout << ans;
	return 0;
}