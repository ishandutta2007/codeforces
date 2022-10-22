#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ld = long double;
#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
using pd2 = pair<ld, ld>;
#define all(v) v.begin(),v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() )

// #define DEBUG

typedef pair<pl2, pl2> pl4;
pl4 arr[200020];
vector<int> adj[200020];
bool chk[200020];

ll res = 1e15;
void dfs(int now){
	chk[now] = 1; res = min(res, arr[now].fr.sc);
	for (int nxt : adj[now]){
		if (chk[nxt]){ continue; }
		dfs(nxt);
	}
}

void Main(){
	int t; cin >> t;
	while (t--){
		int n; ll k; cin >> n >> k;
		for (int i = 1; i <= n; i++){
			cin >> arr[i].sc.fr >> arr[i].sc.sc >> arr[i].fr.sc;
			arr[i].fr.fr = i;
		}
		sort(arr+1, arr+n+1, [](pl4 a, pl4 b){
			if (a.sc.fr == b.sc.fr){ return a.sc.sc < b.sc.sc; }
			return a.sc.fr < b.sc.fr;
		});
		for (int i = 1; i < n; i++){
			if (arr[i].sc.fr != arr[i+1].sc.fr){ continue; }
			ll dis = arr[i+1].sc.sc - arr[i].sc.sc;
			int v1 = arr[i].fr.fr, v2 = arr[i+1].fr.fr;
			if (dis <= k){
				adj[v1].push_back(v2);
				adj[v2].push_back(v1);
			}
		}
		sort(arr+1, arr+n+1, [](pl4 a, pl4 b){
			if (a.sc.sc == b.sc.sc){ return a.sc.fr < b.sc.fr; }
			return a.sc.sc < b.sc.sc;
		});
		for (int i = 1; i < n; i++){
			if (arr[i].sc.sc != arr[i+1].sc.sc){ continue; }
			ll dis = arr[i+1].sc.fr - arr[i].sc.fr;
			int v1 = arr[i].fr.fr, v2 = arr[i+1].fr.fr;
			if (dis <= k){
				adj[v1].push_back(v2);
				adj[v2].push_back(v1);
			}
		}
		sort(arr+1, arr+n+1);
		vector<ll> v;
		for (int i = 1; i <= n; i++){
			if (chk[i]){ continue; }
			res = 1e15; dfs(i);
			v.push_back(res);
		}
		int vl = v.size(); sort( all(v) );
		ll ans = 0;
		for (int i = 0; i < vl; i++){
			ll res = min(v[i], (ll)vl-1 - i);
			ans = max(ans, res);
		}
		cout << ans << endl;
		for (int i = 1; i <= n; i++){
			adj[i].clear();
			arr[i] = { {0, 0}, {0, 0} };
			chk[i] = 0;
		}
	}
}

int main(){
#ifndef DEBUG
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	cout.setf(ios::fixed);
	cout.precision(0);
	Main();
}