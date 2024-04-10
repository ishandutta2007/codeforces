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
const int maxn = 2e5;
ll T, n, a[maxn + 5];
map<ll, ll> mp;
int main() {
//	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	for(cin >> T; T; T --) {
		mp.clear();
		cin >> n;
		rep(i, 1, n) cin >> a[i], mp[a[i]] ++;
		ll sum = 0;
		rep(i, 1, n) sum += a[i];
		ll flg = 1; //cout << sum << '\n';
		ll c0 = 1 - mp[sum], c1 = 0;
		if(c0 < 0) flg = 0;
		mp[sum] = 0;
		while(sum) {
			if(sum & 1) c1 = c1 * 2 + c0; 
			else c0 = c0 * 2 + c1;
			sum /= 2;
			if(sum == 2) {
//				cout << sum << ' ' << c0 << ' ' << c1 << '\n';
				c1 -= mp[3];
				if(c1 < 0) {flg = 0; break;}
				c0 += c1;
				c0 -= mp[2];
				mp[3] = mp[2] = 0;
				if(c0 < 0) {flg = 0; break;}
				c0 += c1, c1 = 0;
//				cout << sum << ' ' << c0 << ' ' << c1 << '\n';
//				break;
			}
			if(sum == 1) {
				c1 -= mp[2];
				if(c1 < 0) {flg = 0; break;}
				c0 += c1 * 2;
				c1 = 0;
				c0 -= mp[1];
				mp[1] = mp[2] = 0;
				if(c0 < 0) {flg = 0; break;}
				break;
			}
			c0 -= mp[sum], c1 -= mp[sum + 1];
			if(c0 < 0 || c1 < 0) {flg = 0;break;}
			mp[sum] = 0;
			mp[sum + 1] = 0;
		}
		for(auto x : mp) if(x.se > 0) flg = 0;
		cout << (flg ? "Yes\n" : "No\n");
	}
	return 0;
}