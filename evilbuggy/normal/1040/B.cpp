#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	if(k == 0){
		cout << n << '\n';
		for(int i = 1; i <= n; i++){
			cout << i << ' ';
		}
		cout << '\n';
	}else if(n <= 2*k + 1){
		cout << 1 << '\n';
		cout << (n + 1)/2 << '\n';
	}else{
		int len = 2*k + 1;
		int cnt = (n + len - 1)/len;

		for(int i = 1; i <= k + 1; i++){
			if(cnt*len - k <= i + n - 1){
				cout << cnt << '\n';
				for(int j = 0; j < cnt; j++){
					cout << (j*len + k + 1) - i + 1 << ' ';
				}
				cout << '\n';
				exit(0);
			}
		}
		assert(false);
	}

	return 0;
}