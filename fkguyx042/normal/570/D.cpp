#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<map>
#include<set>
#include<ctime>
#define eps 1e-6
#define LL long long
#define pii (pair<int, int>)
//#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;

const int maxn = 500000+1000;
//const int INF = 0x3f3f3f3f;
vector<int> G[maxn];
vector<int> Depth[maxn], su[maxn];
int w[maxn];
int dep[maxn], tim[maxn][2], desdep[maxn];
int n, m, clock_cnt;
char str[maxn];

void dfs(int cur) {
    desdep[cur] = dep[cur];
	tim[cur][0] = ++clock_cnt;
	for(int i = 0; i < G[cur].size(); i++) {
		int u = G[cur][i];
		dep[u] = dep[cur] + 1;
		Depth[dep[u]].push_back(u);
		dfs(u);
		desdep[cur] = max(desdep[cur], desdep[u]);
	}
	tim[cur][1] = ++clock_cnt;
}

void init() {
	int d = 1;
	while(1) {
		int sz = Depth[d].size();
		if(!sz) break;
		for(int i = 0; i < sz; i++) {
			int t = w[Depth[d][i]];
			int tmp = su[d][i];
			su[d].push_back(tmp^(1<<t));
		}
		d++;
	}
}

bool check(int dep, int ql, int qr) {
	int palin = su[dep][qr]^su[dep][ql];
	int cnt = 0;
	for(int i = 0; i < 26; i++) {
		if((1<<i)&palin) cnt++;
	}
	if(cnt>1) return false;
	return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
	while(scanf("%d%d", &n, &m) == 2) {
		for(int i = 1; i <= n; i++) G[i].clear(), Depth[i].clear(), su[i].clear();
		for(int i = 1; i <= n; i++) su[i].push_back(0);
		clock_cnt = 0;
		for(int i = 2; i <= n; i++) {
			int t; scanf("%d", &t);
			G[t].push_back(i);
		}
		Depth[1].push_back(1), dep[1] = 1;
		scanf("%s", str);
		for(int i = 1; i <= n; i++) w[i] = str[i-1]-'a';
		dfs(1);
		init();
		//for(int i = 1; i <= n; i++) cout << tim[i][0] << " " << tim[i][1] << endl;
		for(int i = 0; i < m; i++) {
			int u, v; scanf("%d%d", &u, &v);
			if(dep[u] >= v) printf("Yes\n");
			else if(desdep[u] < v) printf("Yes\n");
			else {
				int ql, qr;
				int L = 0, R = Depth[v].size()-1;
				while(L < R) {
					int M = (L+R)>>1;
					int tmp = Depth[v][M];
					if(tim[tmp][0] > tim[u][0]) R = M;
					else L = M+1;
				}
				ql = R;
				L = 0, R = Depth[v].size()-1;
				while(L <= R) {
					int M = (L+R)>>1;
					int tmp = Depth[v][M];
					if(tim[tmp][1] > tim[u][1]) R = M-1;
					else L = M+1;
				}
				qr = R;
				if(check(v, ql, qr+1)) printf("Yes\n");
				else printf("No\n");
			}
		}
	}
    return 0;
}