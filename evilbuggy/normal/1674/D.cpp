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
		for(int i = (n&1); i < n; i += 2){
			if(a[i] > a[i + 1]){
				swap(a[i], a[i + 1]);
			}
		}
		bool flg = true;
		for(int i = 0; i + 1 < n; i++){
			if(a[i] > a[i + 1]){
				flg = false;
			}
		}
		if(flg){
			cout << "YES" << '\n';
		}else{
			cout << "NO" << '\n';
		}
	}

	return 0;
}