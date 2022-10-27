#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		int x; cin >> x;
		int y; cin >> y;
		bool flg = false;
		for(int a = 1; a <= 100; a++){
			int z = x;
			for(int b = 1; b <= 100; b++){
				z *= a;
				if(z == y){
					cout << b << " " << a << '\n';
					flg = true;
					break;
				}
			}
			if(flg)break;
		}
		if(!flg){
			cout << 0 << " " << 0 << '\n';
		}
	}

	return 0;
}