#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	int m; cin >> m;
	if(n > m)swap(n, m);
	if(n == 1){
		cout << m << '\n';
	}else if(n == 2){
		cout << 4*(m/4) + 2*min(2, m%4) << '\n';
	}else{
		cout << (n*m + 1)/2 << '\n';
	}

	return 0;
}