#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>

#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair <int, int>
#define f first
#define s second
#define INF 1000000007

using namespace std;

struct e {
	int i, j, t;
	e(){
		i = 0; j = 0; t = 0;
	}
	e(int i1, int j1, int t1){
		i = i1; j = j1; t = t1;
	}
};


int n, k, c[2], cnt[2], dp[105][105], d[2][105][105], cnk[55][55], clc[2][105][105];

vector < vector < vector <e> > > g[2];

ll calc (e v){
	ll ans = 0;
	if (v.i == v.j && v.i == 0 && v.t == 0) return 1;
	for (int i = 0; i < g[v.t][v.i][v.j].size(); i++){
		e to = g[v.t][v.i][v.j][i];
		if(d[to.t][to.i][to.j] == d[v.t][v.i][v.j] - 1) {
			ll t;
			if (clc[to.t][to.i][to.j] == -1) t = calc(to);
			else t = clc[to.t][to.i][to.j];
			if (v.t == 1) t = (((t * cnk[c[0] - to.i][abs(v.i - to.i)]) % INF) * cnk[c[1] - to.j][abs(v.j - to.j)]) % INF;
			else  t = (((t * cnk[to.i][abs(v.i - to.i)]) % INF) * cnk[to.j][abs(v.j - to.j)]) % INF;
			ans = (ans + t) % INF;
		}
	}
	clc[v.t][v.i][v.j] = ans;
	return ans;
}


int main(){

	for (int i = 0; i < 55; i++){
		for (int j = 0; j <= i; j++){
			if (i == 0) cnk[i][j] = 1;
			else if (j != 0) cnk[i][j] = (cnk[i - 1][j] + cnk[i - 1][j - 1]) % INF;
			else  cnk[i][j] = cnk[i - 1][j];
		}
	}
	c[0] = c[1] = 0;
	cin >> n >> k;
	int t;
	for (int i = 0; i < n; i++) {
		cin >> t;
		if (t == 50) c[0]++;
		else c[1]++;
	}
	cnt[0] = k / 50; cnt[1] = k / 100;

	g[0].assign (c[0] + 1, vector < vector <e> > (c[1] + 1, vector <e> (0)) );
	g[1].assign (c[0] + 1, vector < vector <e> > (c[1] + 1, vector <e> (0)) );

	for (int i = 0; i <= c[0]; i++){
		for (int j = 0; j <= c[1]; j++){
			dp[i][j] = 0;
			for (int q = 0; q <= cnt[0]; q++){
				for (int w = 0; w <= (k - 50  * q) / 100; w++){
					if (q + w && i + q <= c[0] && j + w <= c[1]) {
						g[0][i][j].pb(e(i + q, w + j, 1));
						g[1][i + q][j + w].pb(e(i, j, 0));
					}
				}
			}
		}
	}
	queue <e> q;
	q.push(e(0, 0, 0));
	int used[2][105][105];
	for (int i = 0; i < 105; i++)
		for (int j = 0; j < 105; j++){
			clc[0][i][j] = clc[1][i][j] = -1;
			d[0][i][j] = d[1][i][j] = INF;
			used[0][i][j] = used[1][i][j] = 0;
		}

	d[0][0][0] = 0;
	while (!q.empty()){
		e v = q.front();
		q.pop();
		used[v.t][v.i][v.j] = 0;
		for (int i = 0; i < g[v.t][v.i][v.j].size(); i++){
			e to = g[v.t][v.i][v.j][i];
			if (d[to.t][to.i][to.j] > d[v.t][v.i][v.j] + 1){
				d[to.t][to.i][to.j] = d[v.t][v.i][v.j] + 1;
				if (!used[to.t][to.i][to.j]){
					q.push(to);
					used[to.t][to.i][to.j] = 1;
				}
			}
		}
	}
	if (d[1][c[0]][c[1]] == INF) cout << "-1\n0";
	else {
		cout << d[1][c[0]][c[1]] << '\n';
		cout << calc(e(c[0], c[1], 1)) % INF;
	}

	return 0;
}