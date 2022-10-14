// Yandex.Algorithm Open 2011 Qualification 1
// Problem E -- Pairs
#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>

#define PB push_back
#define MP make_pair

#define foreach(i, v) for(typeof((v).begin()) i = (v).begin(); i != (v).end(); ++ i)

using namespace std;

typedef vector<int> VI;
typedef pair<int, int> PII;

const int N = 222222;
const PII INF = MP(-1e9, -1e9);

PII operator + (const PII &a, const PII &b){
	return MP(a.first + b.first, a.second + b.second);
}

PII operator - (const PII &a, const PII &b){
	return MP(a.first - b.first, a.second - b.second);
}

int n, m, f[N], s[N], degree[N], queue[N], c[N], tc[N];
VI graph[N];
PII tdp[N][2], cdp[2][N][2];
vector<PII> result;

PII edge(int u, int v){
	return MP(1, (int)(s[u] != s[v]));
}

void dfs(int u){
	foreach(it, graph[u]){
		dfs(*it);
		tdp[u][0] = tdp[u][0] + tdp[*it][1];
		PII tmp = tdp[*it][0] - tdp[*it][1] + edge(u, *it);
		if(tdp[u][1] < tmp){
			tc[u] = *it;
			tdp[u][1] = tmp;
		}
	}
	tdp[u][1] = tdp[u][1] + tdp[u][0];
}

void opt(int u, int w){
	if(w and tc[u]){
		result.PB(MP(u, tc[u]));
	}
	foreach(it, graph[u]){
		opt(*it, w and *it == tc[u]? 0: 1);
	}
}

int main(){
	scanf("%d", &n);
	memset(degree, 0, sizeof(degree));
	for(int i = 1; i <= n; ++ i){
		scanf("%d%d", f + i, s + i);
		degree[f[i]] += 1;
	}
	{
		int head = 0, tail = 0;
		for(int i = 1; i <= n; ++ i){
			if(degree[i] == 0){
				queue[tail ++] = i;
			}
		}
		while(head != tail){
			int u = queue[head ++];
			graph[f[u]].PB(u);
			degree[f[u]] -= 1;
			if(not degree[f[u]]){
				queue[tail ++] = f[u];
			}
		}
	}
	PII total;
	for(int u = 1; u <= n; ++ u){
		if(degree[u]){
			m = 0;
			degree[u] = 0;
			dfs(c[m ++] = u);
			for(int v = f[u]; v != u; v = f[v]){
				degree[v] = 0;
				dfs(c[m ++] = v);
			}
			cdp[0][0][0] = tdp[c[0]][0];
			cdp[0][0][1] = tdp[c[0]][1];
			cdp[1][0][0] = INF;
			cdp[1][0][1] = tdp[c[0]][0] + edge(c[0], c[m - 1]);
			for(int k = 0; k < 2; ++ k){
				for(int i = 1; i < m; ++ i){
					cdp[k][i][0] = cdp[k][i - 1][1] + tdp[c[i]][0];
					cdp[k][i][1] = max(cdp[k][i - 1][1] + tdp[c[i]][1], \
					                   cdp[k][i - 1][0] + tdp[c[i]][0] \
					                   + edge(c[i], c[i - 1]));
				}
			}
			total = total + max(cdp[0][m - 1][1], cdp[1][m - 1][0]);
			{
				int k = cdp[0][m - 1][1] < cdp[1][m - 1][0];
				int j = k xor 1;
				for(int i = m - 1; i > 0; -- i){
					if(j){
						if(cdp[k][i - 1][1] + tdp[c[i]][1] != cdp[k][i][1]){
							result.PB(MP(c[i - 1], c[i]));
							j = 0;
						}
						opt(c[i], j);
					}else{
						opt(c[i], j);
						j = 1;
					}
				}
				if(k){
					opt(c[0], 0);
					result.PB(MP(c[0], c[m - 1]));
				}else{
					opt(c[0], j);
				}
			}
		}
	}
	printf("%d %d\n", total.first, total.second);
	for(int i = 0; i < (int)result.size(); ++ i){
		printf("%d %d\n", result[i].first, result[i].second);
	}
	return 0;
}