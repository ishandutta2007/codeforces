//Author: Heltion
//Date: 08-30-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 160000;
int a[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int t, n;
	for(cin >> t; t; t -= 1){
		cin >> n;
		for(int i = 1; i <= n; i += 1) cin >> a[i];
		int mn = 1 << 30, ans = 0;
		for(int i = n; i; i -= 1){
			ans += a[i] > mn;
			mn = min(mn, a[i]);
		}
		cout << ans << "\n";
	}
	return 0;
}