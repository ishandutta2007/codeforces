#include <bits/stdc++.h>
#define endl '\n'
#define fr first
#define sc second
#define all(v) v.begin(),v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() )
#define bout(x) cout << bitset<sizeof(x)*8>(x) << endl
#define mkp(a,b) make_pair(a,b)
#define gcd(a,b) __gcd(a,b)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using cpl = complex<ld>;
const ld pi = 3.14159265358979323846264338327950288;
const ld tau = 2 * pi;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, ddy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int nx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, ny[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

// #define DEBUG

int arr[100020];
vector<int> adj[100020];
map<int, int> mp[100020]; int mx[100020]; ll ans[100020];

void dfs(int now, int par){
	for (int nxt : adj[now]){
		if (nxt == par){ continue; }
		dfs(nxt, now);
		int s1 = mp[now].size(), s2 = mp[nxt].size();
		if (s1 < s2){
			swap(mp[now], mp[nxt]);
			swap(mx[now], mx[nxt]);
			ans[now] = ans[nxt];
		}
		for (pii p : mp[nxt]){
			if (mp[now].count(p.fr) == 0){ mp[now][p.fr] = 0; }
			mp[now][p.fr] += p.sc;
			if (mp[now][p.fr] > mx[now]){
				ans[now] = p.fr;
				mx[now] = mp[now][p.fr];
			}
			else if (mp[now][p.fr] == mx[now]){
				ans[now] += p.fr;
			}
		}
		mp[nxt].clear();
	}
}

void Main(){
	int n; cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> arr[i];
		mp[i][ arr[i] ] = 1;
		mx[i] = 1; ans[i] = arr[i];
	}
	for (int i = 1; i < n; i++){
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, -1);
	for (int i = 1; i <= n; i++){
		cout << ans[i] << ' ';
	}
}

int main(){
#ifndef DEBUG
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	cout.setf(ios::fixed);
	cout.precision(1);
	Main();
}