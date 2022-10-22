#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
int n, m, cnt, ed, mark[20][20];
char s[20][20];

set <long long> ss;

struct Node{
	int t[9], h, dis;
	long long hash(){
		long long ret = 0;
		for (int i = 0, j = h; i < n; i++){
			ret = ret * 37 + t[j];
			j++;
			if (j == n) j = 0;
		}
		return ret;
	}
};

queue <Node> Q;

bool in(int x, int y){
	return x >= 0 && x < n && y >= 0 && y < m ;
}

void check(int &ans, int x, int y, int edx, int edy, int L){
	int que[15 * 15][2], g, h, d[20][20];
	g = 0, h = 1;
	que[0][0] = x, que[0][1] = y;
	d[x][y] = L;
	while (g < h){
		x = que[g][0], y = que[g][1];
		g++;
		for (int i = 0; i < 4; i++){
			int p = x + dir[i][0], q = y + dir[i][1];
			if (!in(p, q)) continue;
			if (mark[p][q] == 0){
				mark[p][q] = -1;
				que[h][0] = p; 
				que[h][1] = q; 
				d[p][q] = d[x][y] + 1;
				h++;
			}
		}
	}
	if (mark[edx][edy] == -1)
		if (ans == -1 || ans > d[edx][edy]) ans = d[edx][edy];
	for (int i = 1; i < h; i++){
		mark[que[i][0]][que[i][1]] = 0;
	}
}

int solve(){
	int ans = -1;
	cnt = 0;
	Node start;
	ss.clear();
	for (int i = 0; i < n; i++){
		for (int j = 0; j<m; j++){
			if (s[i][j] == '@') ed = (i << 5) | j;
			else if (isdigit(s[i][j])){
				cnt = max(cnt, (int)s[i][j] - '0');
				start.t[(int)s[i][j] - '1'] = (i << 5) | j;
			}
			else if (s[i][j] != '.') mark[i][j] = -1;
		}
	}
	start.h = start.dis = 0;
	Q.push(start);
	ss.insert(start.hash());
	while (!Q.empty()){
		Node tmp = Q.front(); Q.pop();
		for (int i = 0, j = tmp.h; i < cnt; i++){
			mark[tmp.t[j] >> 5][tmp.t[j] & 31] = i + 1;
			j++;
			if (j == cnt) j = 0;
		}
		int x = tmp.t[tmp.h] >> 5, y = tmp.t[tmp.h] & 31;
		check(ans, x, y, ed >> 5, ed & 31, tmp.dis);
		for (int i = 0; i < 4; i++){
			int g = x + dir[i][0], h = y + dir[i][1];
			if (in(g, h) && (mark[g][h] == cnt || mark[g][h] == 0)){
				Node k = tmp;
				k.h--;
				if (k.h < 0) k.h = cnt - 1;
				k.t[k.h] = (g << 5) | h;
				k.dis = tmp.dis + 1;
				if (k.t[k.h] == ed) return k.dis;
				long long hash = k.hash();
				if (ss.find(hash) != ss.end() || ss.size() == 600) continue;
				Q.push(k), ss.insert(hash);
			}
		}
		for (int i = 0, j = tmp.h; i < cnt; i++){
			mark[tmp.t[j] >> 5][tmp.t[j] & 31] = 0;
			j++;
			if (j == cnt) j = 0;
		}
	}
	return ans;
}
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++){
		scanf("%s", s[i]);
	}
	printf("%d\n" , solve());
}