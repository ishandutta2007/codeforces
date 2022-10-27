#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int b[N][N], ans[N][N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		vector<array<int, 3> > vec;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> b[i][j]; ans[i][j] = -1;
				vec.push_back({b[i][j], i, j});
			}
		}
		sort(vec.begin(), vec.end());
		for(int i = 0; i < m; i++){
			int x = vec[i][1];
			int v = vec[i][0];
			ans[x][i] = v;
		}
		for(int i = m; i < (int)vec.size(); i++){
			int x = vec[i][1];
			for(int j = 0; j < m; j++){
				if(ans[x][j] == -1){
					ans[x][j] = vec[i][0];
					break;
				}
			}
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cout << ans[i][j] << ' ';
			}
			cout << '\n';
		}
	}

	return 0;
}