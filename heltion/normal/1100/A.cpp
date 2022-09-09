#include<bits/stdc++.h>
using namespace std;
#define maxn 120
int a[maxn];
int main(){
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i += 1) cin >> a[i];
	int ans = 0;
	for(int b = 1; b <= n; b += 1){
		int pans = 0;
		for(int i = 1; i <= n; i += 1) if((b - i) % k) pans += a[i];
		ans = max(ans, abs(pans));
	}
	cout << ans;
}