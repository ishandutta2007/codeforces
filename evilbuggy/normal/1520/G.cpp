#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

long long a[N][N], st[N][N], en[N][N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	long long w;
	cin >> n >> m >> w;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}
	queue<int> qx, qy;
	qx.push(0);
	qy.push(0);
	memset(st, -1, sizeof(st));
	st[0][0] = 0;
	while(!qx.empty()){
		int x = qx.front(); qx.pop();
		int y = qy.front(); qy.pop();
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx < 0 || ny < 0 || nx >= n || ny >= m || a[nx][ny] == -1 || st[nx][ny] != -1)continue;
			st[nx][ny] = st[x][y] + w;
			qx.push(nx);
			qy.push(ny);
		}
	}
	qx.push(n - 1);
	qy.push(m - 1);
	memset(en, -1, sizeof(en));
	en[n - 1][m - 1] = 0;
	while(!qx.empty()){
		int x = qx.front(); qx.pop();
		int y = qy.front(); qy.pop();
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx < 0 || ny < 0 || nx >= n || ny >= m || a[nx][ny] == -1 || en[nx][ny] != -1)continue;
			en[nx][ny] = en[x][y] + w;
			qx.push(nx);
			qy.push(ny);
		}
	}
	long long ans = -1;
	if(en[0][0] != -1)ans = en[0][0];
	long long mn1 = -1, mn2 = -1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(st[i][j] != -1 && a[i][j] > 0){
				if(mn1 == -1 || mn1 > st[i][j] + a[i][j]){
					mn1 = st[i][j] + a[i][j];
				}
			}
			if(en[i][j] != -1 && a[i][j] > 0){
				if(mn2 == -1 || mn2 > en[i][j] + a[i][j]){
					mn2 = en[i][j] + a[i][j];
				}
			}
		}
	}
	if(mn1 != -1 && mn2 != -1){
		if(ans == -1 || ans > mn1 + mn2)ans = mn1 + mn2;
	}
	cout << ans << '\n';

	return 0;
}