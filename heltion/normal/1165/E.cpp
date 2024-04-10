//Author: Heltion
//Date: 2019-05-14
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void maxi(T &a, const T &b){if(b > a) a = b;}
template<typename T>void mini(T &a, const T &b){if(b < a) a = b;}
template<typename T>void no(const T &a){cout << a; exit(0);}
constexpr LL mod = 998244353;
constexpr int maxn = 240000;
LL a[maxn], b[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//sum ai * bi * (n - i + 1) * i
	int n;
	cin >> n;
	for(int i = 1; i <= n; i += 1){
		cin >> a[i];
		a[i] *= 1LL * (n - i + 1) * i;
	}
	for(int i = 1; i <= n; i += 1) cin >> b[i];
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1, greater<LL>());
	LL ans = 0;
	for(int i = 1; i <= n; i += 1, ans %= mod) ans += a[i] % mod * b[i];
	cout << ans;
	return 0;
}