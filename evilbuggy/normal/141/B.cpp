#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a; cin >> a;
	int x; cin >> x;
	int y; cin >> y;
	if(y < 0 || y%a == 0 || x < -a || x > a){
		cout << -1 << '\n';
		exit(0);
	}
	int row = (y + a - 1)/a;
	if(row == 1){
		if(-a < 2*x && 2*x < a){
			cout << 1 << '\n';
		}else{
			cout << -1 << '\n';
		}
	}else if(row%2 == 0){
		if(-a < 2*x && 2*x < a){
			cout << 3*(row/2) - 1 << '\n';
		}else{
			cout << -1 << '\n';
		}
	}else{
		int ind = 3*(row/2) - 1;
		if(-a < x && x < 0){
			cout << ind + 1 << '\n';
		}else if(0 < x && x < a){
			cout << ind + 2 << '\n';
		}else{
			cout << -1 << '\n';
		}
	}

	return 0;
}