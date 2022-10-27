#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		a[i] = s[i] - '0';
	}
	for(int dig = 1; dig <= 9; dig++){
		bool flg = true;
		int p1 = 0, p2 = 0;
		vector<int> ans(n);
		for(int i = 0; i < n; i++){
			if(a[i] < dig){
				if(p1 > a[i]){
					flg = false;
					break;
				}
				ans[i] = 1;
				p1 = a[i];
			}else if(a[i] > dig){
				if(p2 > a[i]){
					flg = false;
					break;
				}
				ans[i] = 2;
				p2 = a[i];
			}else{
				if(p2 > a[i]){
					p1 = a[i];
					ans[i] = 1;
				}else{
					p2 = a[i];
					ans[i] = 2;
				}
			}
		}
		if(flg){
			for(int i = 0; i < n; i++){
				cout << ans[i];
			}
			cout << '\n';
			return;
		}
	}
	cout << '-' << '\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--)solve();

	return 0;
}