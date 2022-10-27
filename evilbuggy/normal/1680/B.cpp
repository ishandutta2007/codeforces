#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		int n; cin >> n;
		int m; cin >> m;
		vector<string> s(n);
		for(int i = 0; i < n; i++){
			cin >> s[i];
		}
		int r = n;
		int c = m;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(s[i][j] == 'R'){
					r = min(r, i);
					c = min(c, j);
				}
			}
		}
		if(s[r][c] == 'R'){
			cout << "YES" << '\n';
		}else{
			cout << "NO" << '\n';
		}
	}

	return 0;
}