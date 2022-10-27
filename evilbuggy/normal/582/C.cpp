#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	long long ans = 0;
	for(int s = 1; s < n; s++){
		if(n%s)continue;
		vector<int> maxi(s);
		for(int j = 0, i = 0; i < n; i++, j++){
			if(j == s)j = 0;
			maxi[j] = max(maxi[j], a[i]);
		}
		int cnt = 0, m = n/s;
		vector<int> f(m + 1);
		for(int k = 1; k <= m; k++){
			if(__gcd(k, m) == 1)f[k] = 1;
			f[k] += f[k - 1];
		}
		for(int j = 0, i = 0; i < n; i++, j++){
			if(j == s)j = 0;
			if(maxi[j] == a[i]){
				cnt++;
			}else{
				cnt = 0;
			}
		}
		for(int j = 0, i = 0; i < n; i++, j++){
			if(j == s)j = 0;
			if(maxi[j] == a[i]){
				cnt++;
			}else{
				cnt = 0;
			}
			if(cnt > n)cnt = n;
			ans += f[cnt/s];
		}
	}
	cout << ans << '\n';

	return 0;
}