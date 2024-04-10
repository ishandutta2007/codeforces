#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, h;
	cin >> n >> h;
	vector<long long> st(n);
	vector<long long> en(n);
	for(int i = 0; i < n; i++){
		cin >> st[i] >> en[i];
	}	
	int l = n - 1;
	long long ans = 0;
	long long cur = 0;
	for(int i = n - 1; i >= 0; i--){
		cur += en[i] - st[i];
		while(en[l] - st[i] - cur >= h){
			cur -= en[l] - st[l]; l--;
		}
		ans = max(ans, cur + h);
	}
	cout << ans << '\n';

	return 0;
}