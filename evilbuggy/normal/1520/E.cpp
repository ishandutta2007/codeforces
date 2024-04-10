#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string s;
		cin >> s;
		vector<int> pos;
		for(int i = 0; i < n; i++){
			if(s[i] == '*')pos.push_back(i);
		}
		if(pos.empty()){
			cout << 0 << '\n';
			continue;
		}
		n = pos.size();
		for(int i = 0; i < n; i++){
			pos[i] -= i;
		}
		long long pref = 0, suff = 0;
		for(int i = 0; i < n; i++){
			suff += pos[i];
		}
		long long ans = 1e18;
		for(int i = 0; i < n; i++){
			suff -= pos[i];
			long long tmp = suff - (n - i - 1)*1LL*pos[i] + i*1LL*pos[i] - pref;
			ans = min(ans, tmp);
			pref += pos[i];
		}
		cout << ans << '\n';
	}

	return 0;
}