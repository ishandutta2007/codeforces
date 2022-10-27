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
	int s, f;
	cin >> s >> f;
	vector<int> sum(n + 1);
	auto update = [&](int l, int r, int x){
		// cout << l << " " << r << " " << x << endl;
		if(l < 1)l += n;
		if(r < 1)r += n;
		if(l > n)l -= n;
		if(r > n)r -= n;
		if(l <= r){
			sum[l] += x;
			if(r + 1 <= n)sum[r + 1] -= x;
		}else{
			sum[l] += x;
			sum[1] += x;
			sum[r + 1] -= x;
		}
	};
	for(int i = 0; i < n; i++){
		update(s - i, f - 1 - i, a[i]);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		sum[i] += sum[i - 1];
		if(sum[i] > sum[ans]){
			ans = i;
		}
	}
	cout << ans << '\n';

	return 0;
}