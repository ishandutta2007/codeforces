#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= int(b); i++)
#define per(i, a, b) for(int i = (a); i >= int(b); i--)
#define fi first
#define se second
#define all(s) s.begin(),s.end()
#define trv(i, u) for(int i = head[u]; i; i = e[i].next)
#define sz(s) (int)(s.size())
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}

const int maxn = 26;
const int maxm = 1000;
const int maxs = pow(3, 15);
const int mod = 1e6;
int n, m;
ll ans[maxm + 5];
ll a[maxm + 5], b[maxm +5], pw[maxn + 5], vis[maxm + 5];

struct Hash_table {
	int head[mod + 5], next[maxs + 5], sta[maxs + 5];
	ll val[maxs + 5];
	int Nodecnt;
	void insert(int s, ll w) {
		int x = (w % mod + mod) % mod;
		for(int i = head[x]; i; i = next[i]) {
			if(val[i] == w) return ;
		}
		val[++Nodecnt] = w, sta[Nodecnt] = s, next[Nodecnt] = head[x];
		head[x] = Nodecnt;
	}
	int find(ll w) {
		int x = (w % mod + mod) % mod;
		for(int i = head[x]; i; i = next[i]) {
			if(val[i] == w) return sta[i];
		}
		return -1;
	}
}mjy;
void dfs1(int l, int r, int s, ll w) {
	if(l > r) {
		mjy.insert(s, w);
		return ;
	}
	dfs1(l + 1, r, s * 3, w);
	dfs1(l + 1, r, s * 3 + 1, w + a[l]);
	dfs1(l + 1, r, s * 3 + 2, w - a[l]);
}
void dfs2(int l, int r,int s, ll w) {
	if(l > r) {
		int t = mjy.find(-w);
		if(t == -1 || !s || !t) return ;
		vector<ll> S, T;
		rep(i, 1, n / 2) {
			int nw = t / pw[n / 2 - i] % 3;
			if(nw == 0) vis[i] = 1;
			else if(nw == 1) S.push_back(i);
			else if(nw == 2) T.push_back(i);
		}
		rep(i, n / 2 + 1, n) {
			int nw = s / pw[n - i] % 3;
			if(nw == 0) vis[i] = 1;
			else if(nw == 1) S.push_back(i);
			else if(nw == 2) T.push_back(i); 
		} 
		assert(sz(S) == sz(T));
		b[1] = 0;int cnt = 1;
		rep(i, 0, sz(S) - 1) {
			cnt++, b[cnt] = a[S[i]] - 1e15 - b[cnt - 1];
			cnt++, b[cnt] = a[T[i]] - 1e15 - b[cnt - 1];
		}
		cnt--;
		rep(i, 1, n) if(vis[i]) b[++cnt] = a[i] - 1e15;
		rep(i, n + 1, m) b[++cnt] = a[i];
		puts("Yes");
		rep(i, 1, m) printf("%lld%c", b[i], " \n"[i == m]);
		exit(0);
	}
	dfs2(l + 1, r, s * 3, w);
	dfs2(l + 1, r, s * 3 + 1, w + a[l]);
	dfs2(l + 1, r, s * 3 + 2, w - a[l]);
}
inline int check(int k) {
	int res = 0;
	rep(i, 1, n) if(a[i] % 2 == k) res ++;
	return res;
}
int main() {
	cin >> n, pw[0] = 1;m = n;
	rep(i, 1, m) cin >> a[i];
	random_shuffle(a + 1, a + n + 1);
	if(n == 2) {
		if(a[1] == a[2]) cout << "YES\n" << a[1] << ' ' << 0 << '\n';
		else cout << "NO\n";
		return 0; 
	}
	if(check(0) >= 3) {
		ll x = -1, y = -1, z = -1;
		rep(i, 1, n) {
			if(a[i] % 2 == 0) {
				if(x == -1) x = a[i], vis[i] = 1;
				else if(y == -1) y = a[i], vis[i] = 1;
				else if(z == -1) z = a[i], vis[i] = 1;
			}
		}
		b[1] = (x + y - z) / 2;
		b[2] = x - b[1];
		b[3] = y - b[1];
		int cnt = 3;
		rep(i, 1, m) if(!vis[i]) b[++cnt] = (a[i] - b[1]);
		puts("Yes");
		rep(i, 1, m) printf("%lld%c", b[i], " \n"[i == m]);
		exit(0);
	}
	else if(check(0) >= 1 && check(1) >= 2) {
		ll x = -1, y = -1, z = -1;
		rep(i, 1, n) {
			if(a[i] % 2 == 1) {
				if(x == -1) x = a[i], vis[i] = 1;
				else if(y == -1) y = a[i], vis[i] = 1;
			}
			else {
				if(z == -1) z = a[i], vis[i] = 1;
			}
		}
		b[1] = (x + y - z) / 2;
		b[2] = x - b[1];
		b[3] = y - b[1];
		int cnt = 3;
		rep(i, 1, m) if(!vis[i]) b[++cnt] = a[i] - b[1];
		puts("Yes");
		rep(i, 1, m) printf("%lld%c", b[i], " \n"[i == m]);
		exit(0);
	}
	n = min(26, n);
	rep(i, 1, n) a[i] += 1e15, pw[i] = pw[i - 1] * 3;
	dfs1(1, n/ 2, 0, 0), dfs2(n / 2 + 1, n, 0, 0);
	puts("NO");
	return 0;
}