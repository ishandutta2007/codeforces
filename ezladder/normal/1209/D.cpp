#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int n, k;

vector<int> g[100007];

bool was[100007];
int sz = 0;

void dfs(int v){
	was[v] = 1;
	sz++;
	for (int to : g[v]) if (!was[to]) dfs(to);
}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;	

	for (int i = 0; i < k; i++){
		int w1, w2;
		cin >> w1 >> w2;
		w1--; w2--;
		g[w1].pb(w2);
		g[w2].pb(w1);
	}

	int ans = 0;

	for (int i = 0; i < n; i++) if (!was[i]){
		sz = 0;
		dfs(i);
		ans += sz - 1;
	}

	cout << k - ans;
}