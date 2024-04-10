#include <bits/stdc++.h>
using namespace std;

struct Node{
	int x, y;
	Node(){}
	Node(int _x, int _y){x = _x, y = _y;}
};

char a[510][510];
int n, m, k, vis[510][510], dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
stack <Node> s;
queue <Node> q;

void bfs(int x, int y){
	while (!q.empty()) q.pop();
	q.push(Node(x, y)), s.push(Node(x, y)), vis[x][y] = 1;
	while (!q.empty()){
		Node t = q.front(); q.pop();
		for (int i = 0; i < 4; i++){
			int xx = t.x + dir[i][0], yy = t.y + dir[i][1];
			if (xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
			if (vis[xx][yy] || a[xx][yy] == '#') continue;
			q.push(Node(xx, yy)), vis[xx][yy] = 1, s.push(Node(xx, yy));
		}
	}
}

int main(){
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++){
		scanf("%s", a[i]);
	}
	int pi = -1, pj = -1;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (a[i][j] == '.'){
				pi = i, pj = j;
				goto END;
			}
		}
	}
	END:;
	bfs(pi, pj);
	for (int i = 0; i < k; i++){
		if (s.size() == 0) break;
		int x = s.top().x, y = s.top().y; s.pop();
		a[x][y] = 'X';
	}
	for (int i = 0; i < n; i++){
		printf("%s\n", a[i]);
	}
	return 0;
}