#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	if(n <= 2){
		cout << "No" << '\n';
	}else{
		cout << "Yes" << '\n';

		cout << n - 1;
		for(int i = 1; i < n; i++){
			cout << ' ' << i;
		}
		cout << '\n';

		cout << 1 << ' ' << n << '\n';
	}

	return 0;
}