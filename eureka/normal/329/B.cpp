#include<stdio.h>
#include<string.h>
#include<iostream>
#include<queue>
#include<utility>

using namespace std;
const int N = 1100;
char ch[N][N];
int h, w;
int si, sj, ti, tj;
int d[N][N];
bool mark[N][N];
int vx[] = {-1, 1, 0, 0};
int vy[] = {0, 0, -1, 1};
void dfs(int i, int j, int dis){
	queue<pair<int, int> > q;
	q.push(make_pair(i, j));
	d[i][j] = 0;
	memset(mark, 0, sizeof(mark));
	while(!q.empty()){
		int x = q.front().first, y = q.front().second;
		q.pop();
		if (ch[x][y] == 'T' || mark[x][y] == true) continue;
		mark[x][y] = true;
		for (int i=0; i<4; ++i){
			int tx = x + vx[i], ty = y + vy[i];
			q.push(make_pair(tx, ty));
			d[tx][ty] = min(d[tx][ty], d[x][y]+1);
		}
	}
}

int main(){
	cin >> h >> w;
	memset(ch, 'T', sizeof(ch));
	for (int i=1; i<=h; ++i){
		scanf("%s", &ch[i][1]);
		ch[i][w+1] = 'T';
	}
	for (int i=1; i<=h; ++i) for (int j=1; j<=w; ++j){
		if (ch[i][j] == 'S'){
			si = i, sj = j;
		}else if (ch[i][j] == 'E'){
			ti = i, tj = j;
		}
	}
	memset(d, 0x3f, sizeof(d));
	dfs(si, sj, 0);
	int dis = d[ti][tj];
	memset(d, 0x3f, sizeof(d));
	dfs(ti, tj, 0);
	int ans = 0;
	for (int i=1; i<=h; ++i) for (int j=1; j<=w; ++j){
		if (ch[i][j] <= '9' && ch[i][j] >= '1' && d[i][j] <= dis){
			ans += ch[i][j] - '0';
		}
	}
	cout << ans << endl;
	return 0;
}