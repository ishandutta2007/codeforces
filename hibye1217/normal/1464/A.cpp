#include <bits/stdc++.h>
#define endl '\n'
#define fr first
#define sc second
#define all(v) v.begin(),v.end()
#define bout(x) cout << bitset<sizeof(x)*8>(x) << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, ddy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int nx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, ny[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int nxt[100020];
int bef[100020];
int cnt = 0;

bool chk[100020];
bool dfs(int now){
	cnt += 1;
	chk[now] = true;
	if (nxt[now] == 0 || nxt[now] == now) return false;
	if (chk[ nxt[now] ]) return true;
	return dfs(nxt[now]);
}

void Main(){
	int t;
	cin >> t;
	while (t--){
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= m; i++){
			int x, y;
			cin >> x >> y;
			nxt[x] = y;
			bef[y] = x;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++){
			if (chk[i] || bef[i] != 0) continue;
			cnt = 0;
			bool cyc = dfs(i);
			if (cyc) cnt += 1;
			else cnt -= 1;
			//cout << i << ' ' << cnt << endl;
			ans += max(cnt, 0);
		}
		for (int i = 1; i <= n; i++){
			if (chk[i]) continue;
			cnt = 0;
			bool cyc = dfs(i);
			if (cyc) cnt += 1;
			else cnt -= 1;
			//cout << i << ' ' << cnt << endl;
			ans += max(cnt, 0);
		}
		cout << ans << endl;
		for (int i = 1; i <= n; i++){
			nxt[i] = bef[i] = 0;
			chk[i] = false;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(0);
	Main();
}