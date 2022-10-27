#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		int r; cin >> r;
		cout << "Division ";
		if(r >= 1900){
			cout << 1 << '\n';
		}else if(r >= 1600){
			cout << 2 << '\n';
		}else if(r >= 1400){
			cout << 3 << '\n';
		}else{
			cout << 4 << '\n';
		}
	}

	return 0;
}