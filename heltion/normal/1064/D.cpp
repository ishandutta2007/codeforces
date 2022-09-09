#include<bits/stdc++.h>
#define maxn 2400
using namespace std;
int n, m, sx, sy, l, r;
char s[maxn][maxn];
bool check(int x, int y){
	return x >= 0 && x < n && y >= 0 && y < m && s[x][y] == '.';
}
int d[maxn][maxn];
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1}, cost[4] = {0, 0, 1, 0};
int main(){
	scanf("%d %d %d %d %d %d", &n, &m, &sx, &sy, &l, &r);
	for(int i = 0; i < n; i += 1) scanf("%s", s[i]);
	for(int i = 0; i < n; i += 1)
		for(int j = 0; j < m; j += 1)
			d[i][j] = maxn * maxn;
	queue<pair<int, int> > q;
	sx -= 1, sy -= 1;
	d[sx][sy] = 0;
	q.push(make_pair(sx, sy));
	while(q.empty() == false){
		pair<int, int> p = q.front();
		q.pop();
		int x = p.first, y = p.second;
		for(int i = 0; i < 4; i += 1)
			if(check(x + dx[i], y + dy[i])){
				//printf("%d %d\n", x, y);
				if(cost[i] + d[x][y] < d[x + dx[i]][y + dy[i]]){
					//printf("%d %d\n", x, y);
					d[x + dx[i]][y + dy[i]] = cost[i] + d[x][y];
					q.push(make_pair(x + dx[i], y + dy[i]));
				}
			}
	}
	//for(int i = 0; i < n; i += 1){
	//	for(int j = 0; j < m; j += 1)
	//		printf("%d ", d[i][j]);
	//	printf("\n");
	//}
	int ans = 0;
	for(int i = 0; i < n; i += 1)
		for(int j = 0; j < m; j += 1)
			if(d[i][j] != maxn * maxn && d[i][j] <= l && d[i][j] + j - sy <= r) ans += 1;
	printf("%d\n", ans);
}