#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;
typedef pair <pii, pii> piii;

const int INF = 0x3f3f3f3f;

int a[110][110], dp[200][210], res[110][110];
piii last[200][210];
vector <pii> pos;
int n, m, k;
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};

int key(int x, int y){return x * m + y;}
int key(pii x){return x.fi * m + x.se;}

struct Dijkstra{
	int n;
	vector <pii> from[210];
	int dist[210][210];
	int last[210][210];
	priority_queue <pii, vector <pii>, greater <pii> > q;
	void init(int x, int y){
		n = x * y;
		for (int i = 0; i < n; i++){
			from[i].clear();
		}
	}
	void add(int x, int y, int c){from[x].push_back(mp(y, c));}
	void Dij(int s, int *dist, int *last){
		dist[s] = 0, last[s] = -1;
		q.push(mp(dist[s], s));
		while (!q.empty()){
			pii t = q.top(); q.pop();
			int x = t.se, dis = t.fi;
			if (dist[x] != dis) continue;
			for (int i = 0; i < from[x].size(); i++){
				int v = from[x][i].fi, c = from[x][i].se;
				if (dist[v] > dist[x] + c){
					dist[v] = dist[x] + c, last[v] = x;
					q.push(mp(dist[v], v));
				}
			}
		}
	}
	void all_dist(){
		memset(dist, INF, sizeof(dist));
		for (int i = 0; i < n; i++){
			Dij(i, dist[i], last[i]);
		}
	}
	vector <int> get_path(int x, int y){
		vector <int> v;
		while (y != x){
			v.push_back(y);
			res[y / m][y % m] = 1;
			y = last[x][y];
		}
		v.push_back(x);
		res[x / m][x % m] = 1;
		return v;
	}
}D;

int count(int x){
	int res = 0;
	while (x) res += x & 1, x >>= 1;
	return res;
}

void get_ans(int mask, int j){
	if (count(mask) == 1){
		for (int i = 0; i < k; i++){
			if (mask >> i & 1) D.get_path(key(pos[i]), j);
		}
		return ;
	}
	int m1 = last[mask][j].fi.fi, m2 = last[mask][j].se.fi;
	int p1 = last[mask][j].fi.se, p2 = last[mask][j].se.se;
	D.get_path(p1, p2);
	get_ans(m1, p1), get_ans(m2, p2);
}

int main(){
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 0; i < k; i++){
		int x, y; scanf("%d%d", &x, &y);
		pos.push_back(mp(x - 1, y - 1));
	}
	D.init(n, m);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			for (int k = 0; k < 4; k++){
				int x = i + dir[k][0], y = j + dir[k][1];
				if (x < 0 || y < 0 || x >= n || y >= m) continue;
				D.add(key(i, j), key(x, y), a[x][y]);
			}
		}
	}
	D.all_dist();
//	cout << "  " << D.dist[0][7] << endl;
	memset(dp, INF, sizeof(dp));
	for (int i = 0; i < k; i++){
		for (int j = 0; j < n * m; j++){
//			cout << "    " << (1 << i) << " " << j << endl;
			dp[1 << i][j] = D.dist[key(pos[i])][j] + a[pos[i].fi][pos[i].se];
		}
	}
	for (int mask = 0; mask < (1 << k); mask++){
//	cout << "                                                   " << dp[2][1] << endl;
		if (count(mask) <= 1) continue;
		for (int p = 0; p < n * m; p++){
			for (int m1 = 0; m1 < (1 << k); m1++){
//				cout << "  cmp:" << mask << " " << m1 << endl;
//				cout << "    pd:" << ((mask | m1) != mask || mask == m1 || m1 == 0) << endl;
				if ((mask | m1) != mask || mask == m1 || m1 == 0) continue;
				int m2 = mask ^ m1;
				for (int pp = 0; pp < n * m; pp++){
					if (dp[mask][p] > dp[m1][pp] + dp[m2][p] + D.dist[pp][p] - a[p / m][p % m]){
						dp[mask][p] = dp[m1][pp] + dp[m2][p] + D.dist[pp][p] - a[p / m][p % m];
						last[mask][p] = mp(mp(m1, pp), mp(m2, p));
					}
					if (dp[mask][p] > dp[m1][p] + dp[m2][pp] + D.dist[pp][p] - a[p / m][p % m]){
						dp[mask][p] = dp[m1][p] + dp[m2][pp] + D.dist[pp][p] - a[p / m][p % m];
						last[mask][p] = mp(mp(m1, p), mp(m2, pp));
					}
				}
			}
//			cout << mask << " " << p << " " << dp[mask][p] << endl;
		}
	}
	int ans = INF;
	int mask, j;
	for (int i = 0; i < n * m; i++){
		if (ans > dp[(1 << k) - 1][i]){
			ans = dp[(1 << k) - 1][i];
			mask = (1 << k) - 1, j = i;
		}
	}
	printf("%d\n", ans);
	get_ans(mask, j);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			printf(res[i][j] ? "X" : ".");
		}
		printf("\n");
	}
	return 0;
}