#include <bits/stdc++.h>
using namespace std;

const int N = 2005;

int dist[N][N], vis[N];
long long ans[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	int mn = 1000000000;
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			cin >> dist[i][j];
			dist[j][i] = dist[i][j];
			mn = min(mn, dist[i][j]);
		}
		dist[i][i] = 0;
	}
	for(int i = 1; i <= n; i++){
		ans[i] = 1e18;
		for(int j = 1; j <= n; j++){
			if(i != j){
				dist[i][j] -= mn;
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i != j)ans[i] = min(ans[i], 2LL*dist[i][j]);
		}
	}
	for(int iter = 1; iter < n; iter++){
		long long mini = 1e18;
		int vert = -1;
		for(int i = 1; i <= n; i++){
			if(vis[i])continue;
			if(mini > ans[i]){
				mini = ans[i];
				vert = i;
			}
		}
		vis[vert] = true;
		for(int i = 1; i <= n; i++){
			if(ans[i] > ans[vert] + dist[vert][i]){
				ans[i] = ans[vert] + dist[vert][i];
			}
		}
	}
	for(int i = 1; i <= n; i++){
		ans[i] += mn*1LL*(n - 1);
		cout << ans[i] << '\n';
	}

	return 0;
}