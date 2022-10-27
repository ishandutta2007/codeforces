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
		if(n == 1){
			cout << 1 << '\n';
		}else if(n == 2){
			cout << -1 << '\n';
		}else{
			int cur = 1;
			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= n; j++){
					cout << cur << " ";
					cur += 2; if(cur > n*n)cur = 2;
				}
				cout << '\n';
			}
		}
	}

	return 0;
}