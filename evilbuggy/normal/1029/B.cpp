#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int ans = 0, cur = 0;
	for(int i = 0; i < n; i++){
		if(i == 0 || a[i] > 2*a[i - 1]){
			cur = 1;
		}else{
			cur++;
		}
		ans = max(ans, cur);
	}
	cout << ans << '\n';

	return 0;
}