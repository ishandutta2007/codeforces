#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		int h, w;
		cin >> h >> w;
		vector<vector<int> > answer(h, vector<int>(w));
		for(int x : {0, h - 1}){
			for(int y : {0, w - 1}){
				answer[x][y] = 1;
			}
		}
		for(int i = 2; i + 2 < w; i += 2){
			answer[0][i] = answer[h - 1][i] = 1;
		}
		for(int i = 2; i + 2 < h; i += 2){
			answer[i][0] = answer[i][w - 1] = 1;
		}
		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				cout << answer[i][j];
			}
			cout << '\n';
		}
		cout << '\n';
	}

	return 0;
}