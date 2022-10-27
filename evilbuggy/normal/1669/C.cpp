#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		bool flg = false;
		for(int b = 0; b < 2; b++){
			bool tmp = true;
			for(int i = 0; i < n; i += 2){
				if((a[i]^b)&1){
					tmp = false;
					break;
				}
			}
			if(tmp)flg = true;
		}
		if(!flg){
			cout << "NO" << '\n';
			continue;
		}
		flg = false;
		for(int b = 0; b < 2; b++){
			bool tmp = true;
			for(int i = 1; i < n; i += 2){
				if((a[i]^b)&1){
					tmp = false;
					break;
				}
			}
			if(tmp)flg = true;
		}
		if(!flg){
			cout << "NO" << '\n';
		}else{
			cout << "YES" << '\n';
		}
	}

	return 0;
}