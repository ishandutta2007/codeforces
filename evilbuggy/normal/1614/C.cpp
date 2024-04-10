#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		int answer = 0;
		for(int i = 0; i < m; i++){
			int l, r, x;
			cin >> l >> r >> x;
			answer = answer | x;
		}
		answer %= mod;
		for(int i = 1; i < n; i++){
			answer <<= 1;
			if(answer >= mod)answer -= mod;
		}
		cout << answer << '\n';
	}

	return 0;
}