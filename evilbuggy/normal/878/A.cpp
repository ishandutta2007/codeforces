#include <bits/stdc++.h>
using namespace std;

int bit[10][2];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for(int i = 0; i < 10; i++){
		bit[i][0] = 0;
		bit[i][1] = 1;
	}
	for(int i = 0; i < n; i++){
		char op; int x;
		cin >> op >> x;
		if(op == '|'){
			for(int j = 0; j < 10; j++){
				int y = (x >> j) & 1;
				bit[j][0] |= y;
				bit[j][1] |= y;
			}
		}else if(op == '&'){
			for(int j = 0; j < 10; j++){
				int y = (x >> j) & 1;
				bit[j][0] &= y;
				bit[j][1] &= y;
			}
		}else{
			for(int j = 0; j < 10; j++){
				int y = (x >> j) & 1;
				bit[j][0] ^= y;
				bit[j][1] ^= y;
			}
		}
	}
	int aval = 0;
	int oval = 0;
	int xval = 0;
	for(int i = 0; i < 10; i++){
		if(bit[i][0] == 0 && bit[i][1] == 0){
			// do nothing
		}else if(bit[i][0] == 0 && bit[i][1] == 1){
			aval ^= (1 << i);
		}else if(bit[i][0] == 1 && bit[i][1] == 1){
			oval ^= (1 << i);
		}else{
			aval ^= (1 << i);
			xval ^= (1 << i);
		}
	}
	cout << 3 << '\n';
	cout << "& " << aval << '\n';
	cout << "| " << oval << '\n';
	cout << "^ " << xval << '\n';

	return 0;
}