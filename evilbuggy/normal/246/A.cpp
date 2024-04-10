#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	if(n <= 2){
		cout << -1 << '\n';
	}else{
		for(int i = n; i >= 1; i--){
			cout << i << " ";
		}
		cout << '\n';
	}

	return 0;
}