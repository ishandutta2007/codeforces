//Author: Heltion
//Date: 2019-05-01
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void maxi(T &a, const T &b){if(b > a) a = b;}
template<typename T>void mini(T &a, const T &b){if(b < a) a = b;}
template<typename T>void no(const T &a){cout << a; exit(0);}
constexpr int maxn = 120;
int a[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, ans = 0;
	cin >> n;
	for(int i = 1; i <= n; i += 1) cin >> a[i];
	for(int i = 1; i < n; i += 1){
		if(a[i] + a[i + 1] == 5) no("Infinite");
		else ans += a[i] + a[i + 1];
	}
	for(int i = 1; i + 2 <= n; i += 1)
		if(a[i] == 3 and a[i + 1] == 1 and a[i + 2] == 2) ans -= 1;
	cout << "Finite\n" << ans;
	return 0;
}