#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 360000;
void no(){
	cout << "No";
	exit(0);
}
LL a[maxn];
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < n; i += 1) cin >> a[i];
	LL ans = 0, rst = 0;
	for(int i = 0; i < n; i += 1){
		if(rst){
			LL h = min(rst, a[i] / 2);
			ans += h;
			rst -= h;
			a[i] -= 2 * h;
		}
		LL h = a[i] / 3;
		ans += h;
		a[i] -= h * 3;
		rst += a[i];
	}
	cout << ans;
}