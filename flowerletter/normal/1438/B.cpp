/*mjytxdy!*/
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
const int maxn = 1000;
const int maxm = 1e6;
int T, n, a[maxn + 5];
struct Hash {
	int mod, sum[maxn + 5];
	inline int pw(ll a, ll b, ll ans = 1) {
		for(; b; b >>= 1, a = a * a % mod) if(b & 1) ans = ans * a % mod;
		return ans;
	}
	void init() {
		rep(i, 1, n) sum[i] = (sum[i - 1] + pw(2, a[i])) % mod; 
	}
	int get(int l, int r) {return (sum[r] - sum[l - 1] + mod) % mod;}
}hlt, tlh;
struct Hash_table {
	int head[maxm], next[maxm]; P sta[maxm];
	int Nodecnt;
	bool find(P s) {
		int x = s.fi % maxm;
		for(int i = head[x]; i; i = next[i]) if(sta[i] == s) return true;
		return false;
	}
	void insert(P s) {
		int x = s.fi % maxm;
		next[++Nodecnt] = head[x], sta[Nodecnt] = s, head[x] = Nodecnt;
	}
	void clear() {
		rep(i, 1, Nodecnt) next[i] = 0, sta[i] = {0, 0};
		memset(head, 0, sizeof head); 
		Nodecnt = 0;
	}
}mjy;
int main() {
//	freopen("in.txt", "r", stdin);
	hlt.mod = 998244353, tlh.mod = 1e9 + 7;
	for(scanf("%d", &T); T; T--) {
		int flag = 1;mjy.clear();
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i]);
		hlt.init(), tlh.init();
		rep(i, 1, n) rep(j, i, n) {
			P s = {hlt.get(i, j), tlh.get(i, j)};
			if(flag && mjy.find(s)) {puts("YES"), flag = 0; break;}
			else mjy.insert(s);
		}
		if(flag) puts("NO");
	}
	return 0;
}