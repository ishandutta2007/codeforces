#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long n;
	long long m;
	cin >> n >> m;
	if(n > m)swap(n, m);
	if(n == 1){
		int val = min(m%6, 6 - m%6);
		cout << n*m - val << endl;
	}else if(n == 2){
		if(m == 2){
			cout << 0 << endl;
		}else if(m == 3){
			cout << 4 << endl;
		}else if(m == 7){
			cout << 12 << endl;
		}else{
			cout << n*m << endl;
		}
	}else{
		long long ans = n*m;
		if(ans & 1) ans ^= 1;
		cout << ans << endl;
	}

	return 0;
}