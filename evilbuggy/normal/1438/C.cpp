#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		vector<vector<int> > a(n, vector<int>(m));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> a[i][j];
			}
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if((a[i][j] + i + j)&1){
					a[i][j]++;
				}
				cout << a[i][j] << " ";
			}
			cout << '\n';
		}
	}

	return 0;
}