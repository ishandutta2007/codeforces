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
inline int id(int r, int angle) {
//	assert(r * 360 + angle < 22 * 360);
	return r * 360 + angle;
}
int main() {
// 	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T;
	for(cin >> T; T; T --) {
		int n;
		vector<int> s(360 * 22), c(360 * 22), fa(360 * 22);
		iota(all(fa), 0);
		cin >> n;
		for(int i = 0; i < n; i ++) {
			string str;
			cin >> str;
			if(str == "S") {
				int r1, r2, angle;
				cin >> r1 >> r2 >> angle;
				rep(i, r1, r2 - 1) s[id(i, angle)] = 1;
			}
			else {
				int r, angle1, angle2;
				cin >> r >> angle1 >> angle2;
				angle2 = (angle2 + 359) % 360;
				if(angle1 <= angle2) rep(i, angle1, angle2) c[id(r, i)] = 1;
				else {
					rep(i, angle1, 359) c[id(r, i)] = 1;
					rep(i, 0, angle2) c[id(r, i)] = 1;
				}
			}
		}
		function<int(int)> find = [&] (int u) {return fa[u] == u ? u : fa[u] = find(fa[u]);};
		auto merge = [&] (int u, int v) {
			u = find(u), v = find(v);
			fa[u] = v;
		};
		rep(i, 0, 20) {
			rep(j, 0, 359) {
				int k = (j + 1) % 360;
				if(!s[id(i, k)]) merge(id(i, j), id(i, k)); 
				if(!c[id(i + 1, j)]) merge(id(i, j), id(i + 1, j));
			}
		}
		int flag = 0;
		rep(i, 0, 359) flag |= find(id(0, 0)) == find(id(21, i));
		cout << (flag ? "YES\n" : "NO\n");
	}
	return 0;
}