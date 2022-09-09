#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, a, maxx = 0, ans = 0;
	cin >> n;
	for(int i = 1; i <= n; i += 1){
		cin >> a;
		maxx = max(a, maxx);
		if(maxx == i) ans += 1;
	}
	cout << ans;
}