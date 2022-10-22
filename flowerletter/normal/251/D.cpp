#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= int(b); i ++)
#define per(i, a, b) for(int i = (a); i >= int(b); i --)
#define fi first
#define se second
#define all(s) s.begin(),s.end()
#define trv(i, u, v) for(int i = head[u], v = e[i].to; i; v = e[i = e[i].next].to)
#define sz(s) (int)(s.size())
#define lb(s) ((s) & (-s))
#define mk(s, t) make_pair(s, t)
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
template <int T> using A = array<int, T>;
const int maxn = 1e5;
const int lg = 61;
int n, ans[maxn + 5];
ll a[maxn + 5], sum;
bitset<maxn + 5> b[lg + 5];
map<int, bitset<maxn + 5>> mp;
void insert(bitset<maxn + 5> u) {
	rep(i, 1, n) if(u[i]) {
		if(mp.count(i)) u ^= mp[i];
		else {
			mp[i] = u;
			break;
		}
	}
}
int main() {
	//freopen("in.txt", "r", stdin);
	cin >> n;
	rep(i, 1, n) cin >> a[i], sum ^= a[i];
	per(i, lg, 0) rep(j, 1, n) b[i][j] = a[j] >> i & 1;
	rep(i, 0, lg) b[i][n + 1] = 1;
	per(i, lg, 0) if(!(sum >> i & 1)) insert(b[i]);
	per(i, lg, 0) if(sum >> i & 1) insert(b[i]); 
	rep(i, 1, n) if(!mp.count(i)) ans[i] = 0;
	per(i, n, 1) if(mp.count(i)) {
		ans[i] = mp[i][n + 1];
		rep(j, i + 1, n) if(mp[i][j]) ans[i] ^= ans[j];
	}
	rep(i, 1, n) cout << ans[i] + 1 << ' ';
	return 0;
}