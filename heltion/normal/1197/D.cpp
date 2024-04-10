//Author: Heltion
//Date: 07-22-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using LD = long double;
template<typename T>void no(const T& s = "NO"){cout << s; exit(0);}
constexpr int maxn = 320000;
LL a[maxn], s[maxn];
LL mi[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(0);
	LL n, m, k;
	cin >> n >> m >> k;
	//s[r] - kr / m - s[l - 1] - k(l - 1) / m + k((m - r + l - 1) % m) / m
	for(int i = 1; i <= n; i += 1) cin >> a[i];
	for(int i = 1; i <= n; i += 1) s[i] = a[i] + s[i - 1];
	LL ans = 0;
	for(int i = 1; i < m; i += 1) mi[i] = 1e18;
	for(int i = 1; i <= n; i += 1){
		LL y = s[i] * m - k * i;
		mi[i % m] = min(mi[i % m], y);
		for(int j = 0; j < m; j += 1) 
			if(i % m == j) ans = max(ans, y - mi[j]);
			else ans = max(ans, y - mi[j] - k * ((m - i % m + j) % m));
	}
	assert(ans % m == 0);
	cout << ans / m;
	return 0;
}