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
template<int T> using A = array<int, T>;

inline int read() {
	int x = 0, f = 1; char c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-')  f = 0;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}
const int maxn = 4e5;
const int maxm = 8e5;
unordered_map<int, int> mp;
int n, deg[maxn + 5], vis[maxn + 5], use[maxm + 5];
int tot[maxn + 5];
vector<int> a[maxn + 5]; 
vector<int> s[maxn + 5];
struct Edge {
	int to, nxt;
}e[maxm + 5];
int head[maxn + 5], cnt = 1;
int stk[maxm + 5], tp;
void add(int u, int v) {
	e[++ cnt] = {v, head[u]}, head[u] = cnt;
}
void dfs(int u) {
	vis[u] = 1;
	for(int &i = head[u], v = e[i].to; i; v = e[i = e[i].nxt].to) {
		if(use[i]) continue;
		use[i] = 1, use[i ^ 1] = 1;
		dfs(v);
	}
	stk[++ tp] = u;
}
int main() {
// 	freopen("in.txt", "r", stdin);
	n = read();
	int ncnt = n;
	rep(i, 1, n) {
		a[i].resize(read());
		for(auto &x : a[i]) {
			x = read();
			if(!mp.count(x)) mp[x] = ++ ncnt;
			x = mp[x];
			add(i, x), add(x, i);
			deg[x] ++; 
		}
	}
	rep(i, 1, ncnt) {
		if(deg[i] & 1) {
			puts("NO\n");
			return 0;
		}
	}
	puts("YES");
	rep(i, 1, n) {
		if(!vis[i]) dfs(i);
	}
	rep(i, 1, tp - 1) {
		if(stk[i] <= n && stk[i + 1] > n) {
			s[stk[i]].pb(stk[i + 1] - n);
		}
	}
	rep(i, 1, n) {
		for(auto x : s[i]) {
			tot[x] ++;
		}
		for(auto x : a[i]) {
			if(tot[x - n]) tot[x - n] --, putchar('L');
			else putchar('R');
		}
		putchar('\n');
	}
	return 0;
}