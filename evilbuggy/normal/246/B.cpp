#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	int sum = 0;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		sum += x;
	}
	if(sum%n == 0){
		cout << n << '\n';
	}else{
		cout << n - 1 << '\n';
	}

	return 0;
}