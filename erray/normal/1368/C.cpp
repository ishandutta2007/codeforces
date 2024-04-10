#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	cout << n * 3 + 4 << '\n';
	for (int i = 0, j = 0; i <= n + 1; j += (i > 0), ++i) {
		for (int q = 0; q < 3 - (i == n + 1 || !i); ++q) cout << j + q << ' ' << i << '\n';	
	}
}