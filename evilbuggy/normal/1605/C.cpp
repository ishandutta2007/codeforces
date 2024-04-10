#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	for(int l = 2; l <= n; l++){
		if(l > 7)break;
		for(int i = 0; i + l <= n; i++){
			vector<int> cnt(3);
			for(int j = 0; j < l; j++){
				cnt[s[i + j] - 'a']++;
			}
			if(cnt[0] > cnt[1] && cnt[0] > cnt[2]){
				cout << l << '\n';
				return;
			}
		}
	}
	cout << -1 << '\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--)solve();

	return 0;
}