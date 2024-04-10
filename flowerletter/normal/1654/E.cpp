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
const int maxn = 1e5;
const int B =  312;
const int S = maxn / B + 10;
int n, a[maxn + 5];
ll b[maxn + 5];
int main() {
// 	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	int ans = 0;
	rep(k, -S, S) {
		rep(i, 1, n) b[i] = a[i] - 1ll * i * k; 
		sort(b + 1, b + n + 1);
		for(int l = 1, r; l <= n; l = r) {
			r = l;
			while(r <= n && b[r] == b[l]) r ++;
			chkmx(ans, r - l);
		}
	}
	rep(i, 1, n) {
		int tot = 0;
		rep(j, max(1, i - B - 10), i - 1) {
			if((a[i] - a[j]) % (i - j) == 0) {
				ll k = (a[j] - a[i]) / (j - i);
				b[++ tot] = k;
			}
		}
		sort(b + 1, b + tot + 1);
		for(int l = 1, r; l <= tot; l = r) {
			r = l;
			while(r <= tot && b[r] == b[l]) r ++;
			chkmx(ans, r - l + 1);
		}
	}
	cout << n - ans << '\n';
	return 0;
}