#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string s;
		cin >> s;
		bool ans = true;
		int b = 0, r = 0;
		for(int i = 0; i < n; i++){
			if(s[i] == 'W'){
				if(b + r && (b == 0 || r == 0)){
					ans = false;
					break;
				}
				b = r = 0;
			}else if(s[i] == 'B'){
				b++;
			}else{
				r++;
			}
		}
		if(b + r && (b == 0 || r == 0)){
			ans = false;
		}
		if(ans){
			cout << "YES" << '\n';
		}else{
			cout << "NO" << '\n';
		}
	}

	return 0;
}