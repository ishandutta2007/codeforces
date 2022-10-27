#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
const int mod = 1000000007;

bool g[N][N];
string pos[N];
pair<int, int> arr[N];
vector<int> comp[N], uwu[N], vec;
int n, a, b, scc[N], vis[N], orig[N], fake[N], s[N], gs[N], ncr[N][N];

void dfs1(int u){
	if(vis[u])return;
	vis[u] = 1;
	for(int i = 1; i <= n; i++){
		if(g[u][i]){
			dfs1(i);
		}
	}
	vec.emplace_back(u);
}

void dfs2(int u, int cc){
	if(!vis[u])return;
	scc[u] = cc;
	vis[u] = 0;
	for(int i = 1; i <= n; i++){
		if(i != u && !g[u][i]){
			dfs2(i, cc);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> a >> b;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			char ch;
			cin >> ch;
			g[i][j] = ch - '0';
		}
	}
	memset(ncr, 0, sizeof(ncr));
	for(int i = 0; i <= n; i++){
		ncr[i][0] = 1;
		for(int j = 1; j <= i; j++){
			ncr[i][j] = ncr[i - 1][j] + ncr[i - 1][j - 1];
			if(ncr[i][j] >= mod)ncr[i][j] -= mod;
		}
	}
	memset(vis, 0, sizeof(vis));
	for(int i = 1; i <= n; i++){
		dfs1(i);
	}
	int iter = 0;
	while(!vec.empty()){
		int u = vec.back();
		vec.pop_back();
		if(vis[u]){
			dfs2(u, ++iter);
		}
	}
	for(int i = 1; i <= n; i++){
		cin >> s[i] >> pos[i];
		
		orig[i] = 0;
		for(int j = 0; j < s[i]; j++){
			if(pos[i][j] == '1')orig[i]++;
		}
	}
	memset(gs, 0, sizeof(gs));
	for(int i = 1; i <= n; i++){
		comp[scc[i]].emplace_back(i);
		gs[scc[i]] = __gcd(gs[scc[i]], s[i]);
	}
	for(int i = 1; i <= iter; i++){
		uwu[i] = vector<int>(gs[i], 0);
	}
	for(int i = 1; i <= iter; i++){
		for(int u : comp[i]){
			for(int j = 0, k = 0; j < s[u]; j++, k++){
				if(k == gs[i])k = 0;
				if(pos[u][j] == '1'){
					uwu[i][k] = 1;
				}
			}
		}
		if(i + 1 <= iter){
			int gg = __gcd(gs[i], gs[i + 1]);
			vector<int> owo(gg, 0);
			for(int j = 0, k = 0; j < gs[i]; j++, k++){
				if(k == gg)k = 0;
				if(uwu[i][j]){
					owo[k] = 1;
				}
			}
			for(int j = 0, k = 0; j < gs[i + 1]; j++, k++){
				if(k == gg)k = 0;
				if(owo[k]){
					uwu[i + 1][j] = 1;
				}
			}
		}
	}
	for(int i = 1; i <= n; i++){
		fake[i] = 0;
		int c = scc[i];
		int g = gs[scc[i]];
		for(int j = 0; j < g; j++){
			if(uwu[c][j])fake[i]++;
		}
		fake[i] *= (s[i]/g);
		fake[i] -= orig[i];
		arr[i] = {orig[i], orig[i] + fake[i]};
	}
	sort(arr + 1, arr + n + 1, [&](pair<int, int> p, pair<int, int> q){
		return p.second > q.second;
	});
	int answer = 0;
	for(int i = 1; i <= n; i++){
		int cnt = 0;
		for(int j = 1; j < i; j++){
			if(arr[j].first > arr[i].second)cnt++;
		}
		int n1 = cnt, n2 = i - cnt - 1;
		for(int k1 = cnt - a + b; k1 <= cnt; k1++){
			int k2 = b - 1 - k1;
			if(k1 < 0 || k2 < 0 || k1 > cnt || k2 > i - cnt - 1)continue;
			answer += ncr[cnt][k1]*1LL*ncr[i - cnt - 1][k2]%mod;
			if(answer >= mod)answer -= mod;
		}
	}
	cout << answer << '\n';

	return 0;
}