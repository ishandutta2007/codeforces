#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		string grid[3];
		for(int i = 0; i < 3; i++){
			cin >> grid[i];
		}
		while(grid[0].size()%3 != 1){
			for(int i = 0; i < 3; i++){
				grid[i] += '.';
			}
		}
		vector<int> pos(3, 0);
		for(int i = 0; i < 3; i++){
			if(grid[i][0] == 's'){
				pos[i] = 1;
				grid[i][0] = '.';
			}
		}
		auto check = [&](int x, int y)->bool{
			return grid[x][y] == '.';
		};
		for(int i = 0; i + 1 < (int)grid[0].size(); i += 3){
			vector<int> npos(3, 0);
			for(int j = 0; j < 3; j++){
				if(!pos[j] || !check(j, i + 1))continue;
				if(check(j, i + 1) && check(j, i + 2) && check(j, i + 3))npos[j] = 1;
				if(j > 0 && check(j - 1, i + 1) && check(j - 1, i + 2) && check(j - 1, i + 3))npos[j - 1] = 1;
				if(j < 2 && check(j + 1, i + 1) && check(j + 1, i + 2) && check(j + 1, i + 3))npos[j + 1] = 1;
			}
			pos = npos;
		}
		if(pos[0] || pos[1] || pos[2]){
			cout << "YES" << '\n';
		}else{
			cout << "NO" << '\n';
		}
	}

	return 0;
}