#include <bits/stdc++.h>
using namespace std;

inline void solvecor(int n){
	for(int i = 2; i <= n; i++){
		cout << 1 << " " << i << '\n';
	}
}

inline void solveinc(int n){
	if(n <= 5){
		cout << -1 << '\n';
		return;
	}
	for(int i = 2; i <= 4; i++){
		cout << 1 << " " << i << '\n';
	}
	for(int i = 5; i <= n; i++){
		cout << 4 << " " << i << '\n';
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	solveinc(n);
	solvecor(n);

	return 0;
}