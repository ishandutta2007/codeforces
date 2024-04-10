#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		int n, m, k;
		cin >> n >> m >> k;
		if(n%2 == 0 && m%2 == 0){
			if(k%2 != 0){
				cout << "NO" << '\n';
			}else{
				cout << "YES" << '\n';
			}
		}else if(n%2 == 0 && m%2 == 1){
			if(k%2 != 0){
				cout << "NO" << '\n';
			}else if(k > n*(m - 1)/2){
				cout << "NO" << '\n';
			}else{
				cout << "YES" << '\n';
			}
		}else if(n%2 == 1 && m%2 == 0){
			if(k < m/2){
				cout << "NO" << '\n';
			}else{
				k -= m/2;
				if(k%2 != 0){
					cout << "NO" << '\n';
				}else{
					cout << "YES" << '\n';
				}
			}
		}else{
			if(k < m/2){
				cout << "NO" << '\n';
			}else{
				k -= m/2;
				if(k%2 != 0){
					cout << "NO" << '\n';
				}else if(k > (n - 1)*(m - 1)/2){
					cout << "NO" << '\n';
				}else{
					cout << "YES" << '\n';
				}
			}
		}
	}

	return 0;
}