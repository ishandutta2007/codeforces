#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<string> grid(n);
	for(auto &x : grid){
		cin >> x;
	}
	vector<vector<int> > dead(n, vector<int>(n));
	vector<pair<int, int> > vec;
	for(int dx = -n + 1; dx <= n - 1; dx++){
		for(int dy = -n + 1; dy <= n - 1; dy++){
			if(dx == 0 && dy == 0)continue;
			bool flg = true;
			for(int x = 0; x < n; x++){
				for(int y = 0; y < n; y++){
					if(grid[x][y] == 'o' && 0 <= x + dx && x + dx < n && 0 <= y + dy && y + dy < n && grid[x + dx][y + dy] == '.'){
						flg = false;
						break;
					}
				}
				if(!flg)break;
			}
			if(!flg)continue;
			vec.emplace_back(dx, dy);
			for(int x = 0; x < n; x++){
				for(int y = 0; y < n; y++){
					if(grid[x][y] == 'o' && 0 <= x + dx && x + dx < n && 0 <= y + dy && y + dy < n){
						dead[x + dx][y + dy] = 1;
					}
				}
			}
		}
	}
	for(int x = 0; x < n; x++){
		for(int y = 0; y < n; y++){
			if(grid[x][y] == 'x' && !dead[x][y]){
				cout << "NO" << '\n';
				exit(0);
			}
		}
	}
	cout << "YES" << '\n';
	vector<string> ans(2*n - 1);
	for(int i = 0; i < 2*n - 1; i++){
		for(int j = 0; j < 2*n - 1; j++){
			ans[i] += '.';
		}
	}
	ans[n - 1][n - 1] = 'o';
	for(auto x : vec){
		ans[n - 1 + x.first][n - 1 + x.second] = 'x';
	}
	for(int i = 0; i < 2*n - 1; i++){
		cout << ans[i] << '\n';
	}

	return 0;
}