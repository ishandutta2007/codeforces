#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long n; cin >> n; n++;
	if(n == 1){
		cout << 0 << '\n';
	}else if(n&1){
		cout << n << '\n';
	}else{
		cout << (n >> 1) << '\n';
	}

	return 0;
}