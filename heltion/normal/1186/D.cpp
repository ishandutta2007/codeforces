#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 120000;
LL a[maxn], b[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	LL n, sum = 0;
	cin >> n;
	for(int i = 1; i <= n; i += 1){
		double x;
		cin >> x;
		a[i] = x * 100000 + .1 * (x >= 0 ? 1 : - 1);
		if(a[i] % 100000 == 0) sum += a[i] /= 100000;
		else{
			sum += a[i] = a[i] / 100000 - (a[i] < 0);
			b[i] = 1;
		}
	}
	for(int i = 1; i <= n; i += 1){
		if(b[i] == 0) cout << a[i] << "\n";
		else if(sum ++ < 0) cout << a[i] + 1 << "\n";
		else cout << a[i] << "\n";
	}
	return 0;
}