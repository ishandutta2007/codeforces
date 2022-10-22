#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i ++)
#define per(i, r, l) for(int i = (r); i >= (l); i --)
#define trv(i, u, v) for(int i = head[u], v = e[i].to; i; v = e[i = e[i].nxt].to)
#define fi first
#define se second
#define all(s) s.begin(), s.end()
#define sz(s) (int)(s.size())
#define lb(s) ((s) & -(s))
#define pb push_back
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
mt19937_64 hua(time(0));
template<typename T> inline bool chkmx(T &x, T y) {return x < y ? x = y, 1 : 0;}
template<typename T> inline bool chkmn(T &x, T y) {return y < x ? x = y, 1 : 0;}
const int maxn = 1000;
const int maxm = 1e6;
const int d[8][2] = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
int n, m, l, vis[maxn + 5][maxn + 5];
P id[maxm + 5];
bool chk(int n) {
	rep(i, 0, l) rep(j, 0, l) vis[i][j] = 0;
	queue<P> q;
	rep(i, 1, n) {
		q.push(id[i]);
		vis[id[i].fi][id[i].se] = 4;
	} 
	int cnt = 0;
	while(!q.empty()) {
		P u = q.front(); q.pop();
		cnt ++;
		rep(i, 0, 7) {
			P x = {u.fi + d[i][0], u.se + d[i][1]};
			if(x.fi >= 0 && x.fi <= l && x.se >= 0 && x.se <= l) {
				if(++ vis[x.fi][x.se] == 4) {
					q.push(x);
				}
			}
		}
	}
	return cnt >= n * n / 10;
}
int main() {
// 	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	if(n <= 40) {
		l = max(10, n / 3 + 3);
		rep(i, 1, l) rep(j, 1, l) id[++ m] = {i, j};
		while(1) {
			random_shuffle(id + 1, id + m + 1);
			if(chk(n)) {
				rep(i, 1, n) cout << id[i].fi << ' ' << id[i].se << '\n';
				break;
			}
		}
	}
	else {
		int tot = 0, m = n / 3 - 3; 
		id[++ tot] = {1, 3};
		id[++ tot] = {3, 3};
		id[++ tot] = {2, 2 * m + 2};
		id[++ tot] = {1, 2};
		id[++ tot] = {2, 2};
		id[++ tot] = {3, 2};
		id[++ tot] = {1, 2 * m + 3};
		id[++ tot] = {2, 2 * m + 3};
		id[++ tot] = {3, 2 * m + 3};
		rep(i, 1, m) id[++ tot] = {1, 2 * i + 2};
		rep(i, 1, m) id[++ tot] = {2, i * 2 + 1};
		rep(i, 1, m) id[++ tot] = {3, i * 2 + 2};
		rep(i, 1, n % 3) id[++ tot] = {n + i, n + i};
		rep(i, 1, n) cout << id[i].fi << ' '<< id[i].se << '\n'; 
	}
	 return 0;
}