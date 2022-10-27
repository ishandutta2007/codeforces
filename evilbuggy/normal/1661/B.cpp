#include <bits/stdc++.h>
using namespace std;

int compute(int x){
	if(x == 0)return 0;
	int ret = 15;
	for(int i = 0; i < 16; i++){
		int y = x + i, z = 0;
		while(y%2 == 0){
			y >>= 1;
			z++;
		}
		ret = min(ret, i + 15 - z);
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		cout << compute(x) << ' ';
	}
	cout << '\n';

	return 0;
}