#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	int xsum = 0;
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		xsum ^= x;
	}
	if(n%2 == 0 && xsum != 0){
		cout << "NO" << '\n';
		exit(0);
	}
	if(n%2 == 0)n--;
	cout << "YES" << '\n';
	cout << n - 1 << '\n';
	for(int i = 2; i <= n; i += 2){
		cout << 1 << " " << i << " " << i + 1 << '\n';
	}
	for(int i = 2; i <= n; i += 2){
		cout << 1 << " " << i << " " << i + 1 << '\n';
	}

	return 0;
}