#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;
typedef pair <pii, int> piii;

const int INF = 0x3f3f3f3f;

int a[20][20], deep[210], g[210][210];
int tmp[20][20], vis[20][20], cur[210];
char buf[20];
vector <piii> start, End;
queue <piii> q1, q2;
queue <int> q;
pii pos;
int n, m, t;
int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};

string read(){scanf("%s", buf); return buf;}

bool IN(int x, int y){
	return x >= 0 && x < n && y >= 0 && y < m;
}

int can_out(pii s, pii e){
//	cout << "can_out:" << s.fi << " " << s.se << " " << e.fi << " " << e.se << endl;
	if (s == e) return 1;
	while (!q1.empty()) q1.pop();
	while (!q2.empty()) q2.pop();
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			tmp[i][j] = a[i][j];
		}
	}
	memset(vis, 0, sizeof(vis));
	q1.push(mp(pos, 0));
	q2.push(mp(s, 0)), vis[s.fi][s.se] = 1;
	for (int p = 1; p <= t; p++){
//		cout << "  p:" << p << endl;
		if (tmp[e.fi][e.se]) return 0;
//		cout << "  maybe_out" << endl;
//		cout << "  bfs_of_q2:" << endl;
		while (!q2.empty() && q2.front().se == p - 1){
			piii top = q2.front(); q2.pop();
			int x = top.fi.fi, y = top.fi.se, time = top.se + 1;
			if (tmp[x][y]) continue;
//			cout << "    now:" << x << " " << y << " " << time << endl;
			for (int i = 0; i < 4; i++){
				int xx = x + dir[i][0], yy = y + dir[i][1];
//				cout << "      new:" << xx << " " << yy << " " << time << endl;
				if (!IN(xx, yy) || tmp[xx][yy] || vis[xx][yy]) continue;
//				cout << "        can_go!" << endl;
				vis[xx][yy] = 1, q2.push(mp(mp(xx, yy), time));
//				cout << e.fi << " " << e.se << endl;
				if (mp(xx, yy) == e) return 1;
			}
		}
		while (!q1.empty() && q1.front().se == p - 1){
			piii top = q1.front(); q1.pop();
			int x = top.fi.fi, y = top.fi.se, time = top.se + 1;
			for (int i = 0; i < 4; i++){
				int xx = x + dir[i][0], yy = y + dir[i][1];
				if (!IN(xx, yy) || tmp[xx][yy]) continue;
				tmp[xx][yy] = 1, q1.push(mp(mp(xx, yy), time));
			}
		}
	}
	return 0;
}

bool bfs(int s, int t){
	memset(deep, -1, sizeof(deep));
	q.push(s), deep[s] = 0;
	while (!q.empty()){
		int u = q.front(); q.pop();
		for (int i = 0; i <= t; i++){
			if (~deep[i] || g[u][i] <= 0) continue;
			deep[i] = deep[u] + 1, q.push(i); 
		}
	}
	return deep[t] != -1;
}

int dfs(int x, int flow, int t){
	if (x == t || !flow) return flow;
	long long res = 0;
	for (int i = cur[x]; i <= t; i++, cur[x]++){
		if (deep[i] != deep[x] + 1 || g[x][i] == 0) continue;
		long long tmp = dfs(i, min(flow, g[x][i]), t);
		if (tmp == 0) continue;
		g[x][i] -= tmp, g[i][x] += tmp;
		res += tmp, flow -= tmp;
		if (flow == 0) break;
	}
	return res;
}

int max_flow(int s, int t){
	int ans = 0;
	while (bfs(s, t)){
		memset(cur, 0, sizeof(cur));
		ans += dfs(s, INF, t);
	}
	return ans;
}

int main(){
	scanf("%d%d", &n, &t);
	m = n;
//	cout << "start:" << endl;
	for (int i = 0; i < n; i++){
		string s = read();
//		cout << s << endl;
		for (int j = 0; j < m; j++){
			if (s[j] == 'Z') pos = mp(i, j);
			if (s[j] == 'Y' || s[j] == 'Z') a[i][j] = 1;
			else if (s[j] != '0') start.push_back(mp(mp(i, j), s[j] - '0'));
		}
	}
	for (int i = 0; i < n; i++){
		string s = read();
		for (int j = 0; j < m; j++){
			if (s[j] == 'Y' || s[j] == 'Z') a[i][j] = 1;
			else if (s[j] != '0') End.push_back(mp(mp(i, j), s[j] - '0')); 
		}
	}
	for (int i = 0; i < start.size(); i++){
		pii ps = start[i].fi;
		for (int j = 0; j < End.size(); j++){
			pii pe = End[j].fi;
			if (can_out(ps, pe)) g[i + 1][j + start.size() + 1] = INF;
		}
	}
	int s = 0, t = start.size() + End.size() + 1;
	for (int i = 0; i < start.size(); i++){
		g[s][i + 1] = start[i].se;
	}
	for (int i = 0; i < End.size(); i++){
		g[i + start.size() + 1][t] = End[i].se;
	}
	printf("%d\n", max_flow(s, t));
	return 0;
}