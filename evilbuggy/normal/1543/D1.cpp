#include <bits/stdc++.h>
using namespace std;

int add(int x, int y, int k){
	int z = 0, prod = 1;
	while(x > 0 || y > 0){
		z += ((x + y)%k)*prod;
		x /= k; y /= k; prod *= k;
	}
	return z;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		int cur = 0;
		for(int i = 0; i < n; i++){
			int tmp = add(cur, i, k);
			cout << tmp << endl;
			int r; cin >> r;
			if(r == 1)break;
			cur = add(add(cur, i, k), cur, k);
		}
	}

	return 0;
}