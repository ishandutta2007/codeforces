#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

const int INF = INT_MAX / 10;

int main(){

	int n = nxt(), m = nxt();
	vector<vector<int>> a(n);
	for (int i = 0; i < m; i++){
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		// a[v].push_back(u);
	}

	vector<vector<pair<int, int>>> in_d(n);
	vector<vector<pair<int, int>>> out_d(n);
	vector<vector<int>> dd;
	for (int i = 0; i < n; i++){
		vector<int> d(n, INF);
		d[i] = 0;
		queue<int> q;
		q.push(i);
		while (!q.empty()){
			int v = q.front();
			q.pop();
			for (auto x : a[v]){
				if (d[x] > d[v] + 1){
					d[x] = d[v] + 1;
					q.push(x);
				}
			}
		}
		for (int j = 0; j < n; j++){
			if (d[j] > n + n || j == i)
				continue;
			out_d[i].emplace_back(d[j], j);
			in_d[j].emplace_back(d[j], i);
		}
		dd.push_back(d);
	}

	for (int i = 0; i < n; i++){
		sort(all(in_d[i]));
		reverse(all(in_d[i]));
		sort(all(out_d[i]));
		reverse(all(out_d[i]));
	}

	int ans = 0;
	vector<int> res;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (i == j)
				continue;
			if (dd[i][j] > n + n)
				continue;
			for (int ii = 0; ii < 4; ii++){
				if (ii >= in_d[i].size())
					break;
				for (int jj = 0; jj < 4; jj++){
					if (jj >= out_d[j].size())
						break;
					int u = in_d[i][ii].second;
					int v = out_d[j][jj].second;
					if (u != j && u != v && v != i){
						int tmp = dd[i][j] + in_d[i][ii].first + out_d[j][jj].first;
						if (tmp > ans){
							ans = tmp;
							res = {u, i, j, v};
						}
					}
				}
			}
		}
	}

	for (auto x : res)
		cout << x + 1 << " ";
	cout << "\n";

	return 0;
}