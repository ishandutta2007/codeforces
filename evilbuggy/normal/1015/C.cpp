#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	vector<int> b(n);
	long long sum = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i] >> b[i];
		b[i] = a[i] - b[i];
		sum += a[i];
	}
	sort(b.begin(), b.end());
	
	int ans = 0;
	while(sum > m && !b.empty()){
		sum -= b.back(); b.pop_back();
		ans++;
	}
	if(sum > m){
		cout << -1 << '\n';
	}else{
		cout << ans << '\n';
	}

	return 0;
}