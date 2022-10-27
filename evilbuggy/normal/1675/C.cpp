#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int n = (int)s.size();
		int pzer = 0, sone = 0;
		for(int i = 0; i < n; i++){
			if(s[i] == '1')sone++;
		}
		int ans = 0;
		for(int i = 0; i < n; i++){
			if(s[i] == '1')sone--;
			if(pzer == 0 && sone == 0)ans++;
			if(s[i] == '0')pzer++;
		}
		cout << ans << '\n';
	}

	return 0;
}