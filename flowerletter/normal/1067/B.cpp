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
const int maxn = 1e5;

int n, k, deg[maxn + 5], del[maxn + 5], col[maxn + 5];
int cnt[maxn + 5];
vector<int> G[maxn + 5];
int main() {
// 	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	if(k > 30) {
		cout << "No\n";
		return 0;
	}
	if(n <= 2) {
		cout << "No\n";
		return 0;
	}
	rep(i, 2, n) {
		int u, v;
		cin >> u >> v;
		G[u].pb(v), G[v].pb(u);
		deg[u] ++, deg[v] ++;
	}
	rep(t, 0, k) {
		vector<int> p;
		rep(i, 1, n) {
//			if(t == 1) cout << deg[i] << " \n"[i == n];
			if(deg[i] == (t < k)) {
				if(t >= 1 && cnt[i] < 3) {
//					cout << t << ' ' << i << ' ' << deg[i] << ' ' << cnt[i] << '\n';;
					cout << "No\n";
					return 0;
				}
				p.pb(i);
			}
			else if(cnt[i]) {
//				cout << t << ' ' << i << ' ' << deg[i] << '\n';
				cout << "No\n";
				return 0;
			}
		}
		rep(i, 1, n) cnt[i] = 0;
		for(auto i : p) {
			for(auto v : G[i]) if(!del[v]) {
				deg[v] --;
				cnt[v] ++;
			}
			del[i] = 1;
			deg[i] = -1;
		}
	}
	cout << "Yes\n";
	return 0;
}