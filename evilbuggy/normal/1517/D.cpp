#include <bits/stdc++.h>
using namespace std;

const int K = 22;
const int N = 505;

int horz[N][N], vert[N][N], ans[N][N], nans[N][N];

inline void umin(int &x, int y){
	if(x > y)x = y;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j < m; j++){
			cin >> horz[i][j];
		}
	}
	for(int i = 1; i < n; i++){
		for(int j = 1; j <= m; j++){
			cin >> vert[i][j];
		}
	}
	if(k&1){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				cout << -1 << ' ';
			}
			cout << '\n';
		}
		exit(0);
	}
	memset(ans, 0, sizeof(ans));
	for(int iter = 1; iter <= (k >> 1); iter++){
		memset(nans, 0x7f, sizeof(nans));
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				if(j + 1 <= m){
					umin(nans[i][j + 1], ans[i][j] + horz[i][j]);
				}
				if(i + 1 <= n){
					umin(nans[i + 1][j], ans[i][j] + vert[i][j]);
				}
				if(j - 1 >= 1){
					umin(nans[i][j - 1], ans[i][j] + horz[i][j - 1]);
				}
				if(i - 1 >= 1){
					umin(nans[i - 1][j], ans[i][j] + vert[i - 1][j]);
				}
			}
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				ans[i][j] = nans[i][j];
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cout << (ans[i][j] << 1) << " ";
		}
		cout << '\n';
	}

	return 0;
}