#include <bits/stdc++.h>
using namespace std;

inline int mod = 1000*1000*1000 + 7;

void solve(){
	int n; cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	vector<int> c(n);
	for(int i = 0; i < n; i++){
		cin >> a[i]; a[i]--;
	}
	for(int i = 0; i < n; i++){
		int x; cin >> x; b[a[i]] = x - 1;
	}
	for(int i = 0; i < n; i++){
		int x; cin >> x; if(x)c[x - 1] = 1;
	}
	int ans = 1;
	vector<int> vis(n);
	for(int i = 0; i < n; i++){
		if(vis[i])continue;
		int x = i, flg = 0, len = 0;
		while(!vis[x]){
			vis[x] = 1;
			flg |= c[x];
			x = b[x];
			len++;
		}
		if(!flg && len > 1){
			ans <<= 1;
			if(ans >= mod)ans -= mod;
		}
	}
	cout << ans << '\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--)solve();

	return 0;
}