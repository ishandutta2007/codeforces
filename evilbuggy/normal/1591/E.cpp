#include <bits/stdc++.h>
using namespace std;

const int maxN = 1000005;

vector<int> g[maxN];
vector<int> qi[maxN];
int arr[maxN], pos[maxN], qk[maxN], ql[maxN];
int n, q, a[maxN], cnt[maxN], freq[maxN], ans[maxN];

void dfs(int v){
	{
		int x = a[v];
		int pos1 = pos[x];
		int pos2 = cnt[freq[x]];
		swap(arr[pos1], arr[pos2]);
		pos[arr[pos1]] = pos1;
		pos[arr[pos2]] = pos2;
		cnt[freq[x]]--; freq[x]++;
	}
	for(int u : g[v]){
		dfs(u);
	}
	for(int i : qi[v]){
		int l = ql[i];
		int k = qk[i];
		if(n < cnt[l - 1] + k)continue;
		ans[i] = arr[cnt[l - 1] + k];
	}
	{
		int x = a[v];
		int pos1 = pos[x];
		int pos2 = cnt[freq[x] - 1] + 1;
		swap(arr[pos1], arr[pos2]);
		pos[arr[pos1]] = pos1;
		pos[arr[pos2]] = pos2;
		freq[x]--; cnt[freq[x]]++;
	}
}

void solve(){
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		arr[i] = i; pos[i] = i;
		g[i].clear(); qi[i].clear();
		freq[i] = 0; cnt[i] = n;
	}
	cnt[0] = n;
	for(int i = 2; i <= n; i++){
		int p;
		cin >> p;
		g[p].emplace_back(i);
	}
	for(int i = 1; i <= q; i++){
		int v;
		cin >> v >> ql[i] >> qk[i];
		qi[v].emplace_back(i);
		ans[i] = -1;
	}
	dfs(1);
	for(int i = 1; i <= q; i++){
		cout << ans[i] << " ";
	}
	cout << '\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--)solve();

	return 0;
}