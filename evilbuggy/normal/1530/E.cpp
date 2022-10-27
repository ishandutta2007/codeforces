#include <bits/stdc++.h>
using namespace std;

inline void solve(){
	string s;
	cin >> s;
	vector<int> f(26);
	int n = (int)s.size();
	for(int i = 0; i < n; i++){
		f[s[i] - 'a']++;
	}
	for(int i = 0; i < 26; i++){
		if(f[i] == n){
			cout << s << '\n';
			return;
		}
	}
	for(int i = 0; i < 26; i++){
		if(f[i] == 1){
			string ans = "";
			ans += char('a' + i); f[i]--;
			for(int j = 0; j < 26; j++){
				while(f[j]--)ans += char('a' + j);
			}
			cout << ans << '\n';
			return;
		}
	}
	for(int i = 0; i < 26; i++){
		if(f[i] == 0)continue;
		if(n - f[i] >= f[i] - 2){
			string rem = "";
			for(int j = i + 1; j < 26; j++){
				while(f[j]--)rem += char('a' + j);
			}
			string ans = "";
			ans += char('a' + i);
			ans += char('a' + i);
			for(int k = 0; k < n - f[i]; k++){
				ans += rem[k];
				if(k < f[i] - 2)ans += char('a' + i);
			}
			cout << ans << '\n';
			return;
		}
		int j = i + 1;
		while(f[j] == 0)j++;
		if(f[i] + f[j] != n){
			string ans = "";
			ans += char('a' + i); f[i]--;
			ans += char('a' + j); f[j]--;
			for(int k = 0; k < f[i]; k++){
				ans += char('a' + i);
			}
			for(int k = j + 1; k < 26; k++){
				if(f[k]){
					ans += char('a' + k);
					f[k]--; break;
				}
			}
			for(int k = i + 1; k < 26; k++){
				while(f[k]--){
					ans += char('a' + k);
				}
			}
			cout << ans << '\n';
		}else{
			string ans = "";
			ans += char('a' + i); f[i]--;
			while(f[j]--){
				ans += char('a' + j);
			}
			while(f[i]--){
				ans += char('a' + i);
			}
			cout << ans << '\n';
		}
		return;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--)solve();

	return 0;
}