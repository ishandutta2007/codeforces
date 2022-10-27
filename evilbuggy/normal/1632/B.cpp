#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		
		int m = 1;
		while((m << 1) < n)m <<= 1;

		vector<int> p(n);
		iota(p.begin(), p.end(), 0);
		reverse(p.begin(), p.begin() + m);
		for(int i = 0; i < n; i++){
			cout << p[i] << ' ';
		}
		cout << '\n';
	}

	return 0;
}