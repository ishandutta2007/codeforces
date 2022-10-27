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
		vector<int> a(n);
		bool flg = true;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			if(a[i] != i + 1)flg = false;
		}
		if(flg){
			cout << 0 << '\n';
		}else if(a[0] == 1 || a[n - 1] == n){
			cout << 1 << '\n';
		}else if(a[0] != n || a[n - 1] != 1){
			cout << 2 << '\n';
		}else{
			cout << 3 << '\n';
		}
	}

	return 0;
}