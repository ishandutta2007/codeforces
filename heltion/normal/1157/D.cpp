// Author: Heltion
// Date: 2019-04-26
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 240000;
LL a[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	LL n, k, s = 0;;
	cin >> n >> k;
	if(n < k * (k + 1) / 2){
		cout << "NO";
		return 0;
	}
	LL b = (n - k * (k + 1) / 2) / k;
	s = n;
	for(int i = 1; i <= k; i += 1) s -= a[i] = b + i;
	while(s){
		bool ok = false;
		for(int i = k; i >= 1; i -= 1){
			LL h = 0;
			if(i > 1) h = a[i - 1] * 2 - a[i];
			if(i < k) h = min(h, a[i + 1] - a[i] - 1);
			h = min(h, s);
			a[i] += h;
			ok |= h;
			s -= h;
		}
		if(not ok) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES\n";
	for(int i = 1; i <= k; i += 1) cout << a[i] << " ";
	return 0;
}