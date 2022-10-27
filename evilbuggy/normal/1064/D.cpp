#include <bits/stdc++.h>
using namespace std;

const int maxN = 2005;
const int inf = (int)1e8;
const int dx[] = {0, -1, 1, 0};
const int dy[] = {-1, 0, 0, 1};

char grid[maxN][maxN];
int vis[maxN][maxN];
int dist[maxN][maxN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	int r, c;
	int x, y;
	cin >> n >> m;
	cin >> r >> c;
	cin >> x >> y;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> grid[i][j];
			vis[i][j] = 0;
			dist[i][j] = inf;
		}
	}
	dist[r][c] = 0;
	deque<int> qx, qy;
	qx.emplace_back(r);
	qy.emplace_back(c);
	while(!qx.empty()){
		int a = qx.front(); qx.pop_front();
		int b = qy.front(); qy.pop_front();
		for(int i = 0; i < 4; i++){
			int na = a + dx[i];
			int nb = b + dy[i];
			if(na < 1 || nb < 1 || na > n || nb > m || grid[na][nb] == '*')continue;
			if(i != 0 && dist[na][nb] > dist[a][b]){
				dist[na][nb] = dist[a][b];
				qx.push_front(na);
				qy.push_front(nb);
			}
			if(i == 0 && dist[na][nb] > dist[a][b] + 1){
				dist[na][nb] = dist[a][b] + 1;
				qx.push_back(na);
				qy.push_back(nb);
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(dist[i][j] == inf)continue;
			int lft = dist[i][j];
			int rgt = lft + j - c;
			if(lft <= x && rgt <= y)ans++;
		}
	}
	cout << ans << '\n';

	return 0;
}