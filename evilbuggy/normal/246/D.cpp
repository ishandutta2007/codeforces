#include <bits/stdc++.h>
using namespace std;

const int maxN = 100005;

int c[maxN], cnt[maxN];
vector<int> Q[maxN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	int m; cin >> m;
	memset(cnt, 0, sizeof(cnt));
	for(int i = 1; i <= n; i++){
		cin >> c[i];
		cnt[c[i]]++;
	}
	for(int i = 1; i <= m; i++){
		int u; cin >> u;
		int v; cin >> v;
		if(c[u] != c[v]){
			Q[c[u]].emplace_back(c[v]);
			Q[c[v]].emplace_back(c[u]);
		}
	}
	int ind = -1, val = -1;
	for(int i = 1; i < maxN; i++){
		if(!cnt[i])continue;
		sort(Q[i].begin(), Q[i].end());
		int card = unique(Q[i].begin(), Q[i].end()) - Q[i].begin();
		if(card > val){
			ind = i;
			val = card;
		}
	}
	assert(ind != -1);
	cout << ind << '\n';


	return 0;
}