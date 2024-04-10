/*mjytxdy!*/
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= int(b); i++)
#define per(i, a, b) for(int i = (a); i >= int(b); i--)
#define fi first
#define se second
#define all(s) s.begin(),s.end()
#define trv(i, u) for(int i = head[u]; i; i = e[i].next)
#define sz(s) (int)(s.size())
#define lb(s) ((s) & (-s))
using namespace std;
 
typedef long long ll;
typedef pair<int,int> P;
typedef unsigned long long ull;
 
template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
const int maxn = 1500;
const ull base = 724; 
int n, m, a[maxn + 5][maxn + 5], b[maxn + 5][maxn + 5], nxt[maxn + 5][maxn + 5];
int ans[maxn + 5], cnt[maxn + 5], used[maxn + 5], match[maxn + 5];
vector<P> s;
unordered_map<ull, vector<int>> mp; 
bool is(int i, int l, int r) {return nxt[i][l] < r;} 
void update(int l, int r, int k) {
	rep(i, 1, m) cnt[i] += k * is(i, l, r);
}
int main() {
	//freopen("in.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	rep(i, 1, n) rep(j, 1, m) scanf("%d", &a[j][i]);
	rep(i, 1, n) rep(j, 1, m) scanf("%d", &b[j][i]);
	rep(i, 1, m) {
		int nw = n;
		per(j, n, 1) {
			if(b[i][j] > b[i][j + 1]) nw = j;
			nxt[i][j] = nw;
		}
		cnt[i] = (nxt[i][1] != n);
	}
	s.push_back({1, n});
	rep(i, 1, m + 1) {
		rep(j, 1, m) if(!used[j] && !cnt[j]) {
			vector<P> t;
			for(auto u : s) {
				int l = u.fi, r = u.se; 
				if(b[j][l] == b[j][r]) {
					t.push_back({l, r});
					continue;
				}
				update(l, r, -1);
				for(int p = l, q = l - 1; p <= r; p = q + 1) {
					while(q < r && b[j][q + 1] == b[j][p]) q++;
					t.push_back({p, q}), update(p, q, 1);
				}
			}
			used[j] = 1, ans[i] = j, s = t;
			break;
		}
		if(ans[i]) continue;
		rep(i, 1, n) {
			ull hsh = 0;
			rep(j, 1, m) hsh = hsh * base + a[j][i]; 
			mp[hsh].push_back(i);
		}
		per(i, n, 1) {
			ull hsh = 0;
			rep(j, 1, m) hsh = hsh * base + b[j][i];
			if(!sz(mp[hsh])) return puts("-1"), 0;
			match[i] = mp[hsh].back(), mp[hsh].pop_back();
		}
		for(auto u : s) {
			int l = u.fi, r = u.se; 
			rep(i, l, r - 1) if(match[i] > match[i + 1])  return puts("-1"), 0;
		}
		printf("%d\n", i - 1);
		per(j, i - 1, 1) printf("%d ", ans[j]);
		return 0;
	}
	return 0;
}