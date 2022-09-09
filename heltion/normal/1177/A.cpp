#include<bits/stdc++.h>
using namespace std;
using LL = long long;
LL power(LL r){
	LL res = 1, a = 10;
	for(; r; r >>= 1, a = a * a)
		if(r & 1) res = res * a;
	return res;
}
int a[100];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	LL k;
	cin >> k;
	for(int i = 1; ; i += 1){
		if(k > (power(i) - power(i - 1)) * i){
			k -= (power(i) - power(i - 1)) * i;
			continue;
		}
		LL x = power(i - 1) - 1 + k / i;
		if(k % i == 0) cout << x % 10;
		else{
			int n = 0;
			for(x += 1; x; x /= 10) a[n += 1] = x % 10;
			reverse(a + 1, a + n + 1);
			cout << a[k % i];
		}
		return 0;
	}
	return 0;
}