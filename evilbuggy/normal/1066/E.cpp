#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	string a;
	cin >> a;
	string b;
	cin >> b;
	vector<int> cb(m);
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	for(int i = m - 1; i >= 0; i--){
		cb[i] = b[i] - '0';
		if(i + 1 < m)cb[i] += cb[i + 1];
	}
	int ans = 0, prod = 1;
	for(int i = 0; i < n && i < m; i++){
		if(a[i] == '1'){
			ans += 1LL*prod*cb[i]%mod;
			if(ans >= mod)ans -= mod;
		}
		prod <<= 1; if(prod >= mod)prod -= mod;
	}
	cout << ans << '\n';

	return 0;
}