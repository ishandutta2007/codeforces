#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		int n; cin >> n;
		int m; cin >> m;
		vector<string> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		while(true){
			bool flg = false;
			for(int i = n - 2; i >= 0; i--){
				for(int j = 0; j < m; j++){
					if(a[i][j] == '*' && a[i + 1][j] == '.'){
						swap(a[i][j], a[i + 1][j]);
						flg = true;
					}
				}
			}
			if(!flg)break;
		}
		for(int i = 0; i < n; i++){
			cout << a[i] << '\n';
		}
	}

	return 0;
}