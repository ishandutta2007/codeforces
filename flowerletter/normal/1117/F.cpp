#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= int(b); i ++)
#define per(i, a, b) for(int i = (a); i >= int(b); i --)
#define fi first
#define se second
#define all(s) s.begin(), s.end()
#define trv(i, u, v) for(int i = head[u], v = e[i].to; i; v = e[i = e[i].nxt].to)
#define sz(s) (int)(s.size())
#define lb(s) ((s) & (-s))
#define mk make_pair
#define pb push_back
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
template <int T> using A = array<int, T>;
inline int read() {
	int x = 0, f = 1; char c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-')  f = 0;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}
const int maxn = 1e5;
const int maxp = 17;
const int maxs = 1 << 17;
int n, p, m, cnt[maxp + 5], id[maxp + 5], a[maxp + 5][maxp + 5], nxt[maxn + 5][maxp + 5], dp[maxs + 5];
bitset<maxs + 5> can[maxp + 5][maxp + 5];
char s[maxn + 5];
int main() {
//	freopen("in.txt", "r", stdin);
	cin >> n >> p >> s + 1; m = p - 1;
	rep(i, 0, m) rep(j, 0, m) a[i][j] = read();
	rep(i, 0, m) nxt[n + 1][i] = n + 1;
	per(i, n, 1) {
		cnt[s[i] -= 'a'] ++;
		rep(j, 0, m) nxt[i][j] = nxt[i + 1][j];
		rep(j, 0, m) id[j] = j;
		sort(id, id + m + 1, [&] (int x, int y) {return nxt[i][x] < nxt[i][y];});
		int t = 0;
		rep(j, 0, m) if(nxt[i][id[j]] <= n){
			if(!a[s[i]][id[j]]) {
				can[s[i]][id[j]][t] = 1; 
				can[id[j]][s[i]][t] = 1;
			}
			t |= 1 << id[j];
		}
		nxt[i][s[i]] = i;
	}
	rep(i, 0, m) rep(j, 0, m) {
		rep(s, 0, (1 << p) - 1) {
			if(s >> j & 1) continue;
			rep(k, 0, m) if(s >> k & 1) {
				can[i][j][s] = can[i][j][s] | can[i][j][s ^ 1 << k];
			}
		}
	}
	dp[0] = 1;
	int ans = 0;
	rep(s, 1, (1 << p) - 1) {
		rep(i, 0, m) if(s >> i & 1) dp[s] |= dp[s ^ 1 << i];
		rep(i, 0, m) rep(j, 0, m) if(!(s >> i & 1) && !(s >> j & 1) && can[i][j][s]) dp[s] = 0;
		if(!dp[s]) continue;
		int res = 0;
		rep(i, 0, m) if(s >> i & 1) res += cnt[i];
		chkmx(ans, res);
	}
	cout << n - ans << '\n';
	return 0;
}