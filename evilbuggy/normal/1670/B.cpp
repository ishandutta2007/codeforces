#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, k;
	string s;
	cin >> n;
	cin >> s;
	cin >> k;
	vector<int> f(26);
	for(int i = 0; i < k; i++){
		char ch; cin >> ch; f[ch - 'a'] = 1;
	}
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		a[i] = f[s[i] - 'a'];
	}
	int ans = 0;
	int cnt = 0;
	int flg = 0;
	for(int i = 0; i < n; i++){
		if(a[i]){
			if(flg){
				ans = max(ans, cnt + 1);
			}else{
				ans = cnt;
			}
			cnt = 0;
			flg = 1;
		}else{
			cnt++;
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