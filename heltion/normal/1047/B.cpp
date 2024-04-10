#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	int n, ans = 0;
	cin >> n;
	while(n --){
		int x, y;
		cin >> x >> y;
		ans = max(ans, x + y);
	}
	cout << ans;
}