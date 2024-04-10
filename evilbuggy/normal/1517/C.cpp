#include <bits/stdc++.h>
using namespace std;

const int N = 505;
int p[N], ans[N][N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> p[i];
	}
	memset(ans, -1, sizeof(ans));
	for(int i = 1; i <= n; i++){
		ans[i][i] = p[i];
		int x = i, y = i;
		for(int j = 1; j < p[i]; j++){
			if(y - 1 >= 1 && ans[x][y - 1] == -1){
				ans[x][y - 1] = p[i];
				y = y - 1;
			}else{
				assert(ans[x + 1][y] == -1);
				ans[x + 1][y] = p[i];
				x = x + 1;
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){
			cout << ans[i][j] << " ";
		}
		cout << '\n';
	}

	return 0;
}