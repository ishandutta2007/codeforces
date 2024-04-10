#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	int n, ans = 1;
	cin >> n;
	int a = 0, b = 0;
	for(int i = 0; i < n; i += 1){
		int na, nb;
		cin >> na >> nb;
		int L = max(a, b) + (a == b), R = min(na, nb);
		ans += max(0, R - L + 1);
		a = na, b = nb;
	}
	cout << ans;
}