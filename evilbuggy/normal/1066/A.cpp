#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		int L, v, l, r;
		cin >> L >> v >> l >> r;
		cout << (L/v) - (r/v) + ((l - 1)/v) << '\n';
	}

	return 0;
}