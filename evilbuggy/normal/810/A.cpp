#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	int sum = 0;
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		sum += x;
	}
	for(int r = 0; ; r++){
		if(sum*2 >= (2*k - 1)*n){
			cout << r << '\n';
			exit(0);
		}
		sum += k; n += 1;
	}

	return 0;
}