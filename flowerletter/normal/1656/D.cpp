#include<bits/stdc++.h>
#define rep(i, l, r) for(ll i = (l); i <= (r); i ++)
#define per(i, r, l) for(ll i = (r); i >= (l); i --)
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
ll T, n;
bool chk(ll x) {
	if(x == 1) return 0;
	if(x > sqrt(3 * n)) return 0; 
	ll tmp = n - x * (x - 1) / 2;
	return tmp > 0 && tmp % x == 0;
}
int main() {
//	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	for(cin >> T; T; T --) {
		cin >> n;;
		ll tmp = n;
		while(tmp % 2 == 0) tmp /= 2;
		if(tmp == 1) {
			cout << -1 << '\n';
			continue;
		}
		else {
			ll cur = n, ret = 1, flag = 1;
			while(cur % 2 == 0) {
				ret *= 2, cur /= 2;
				if(chk(ret)) {
					cout << ret << '\n';
					flag = 0;
					break;
				}
			}
			if(!flag) continue;
			if(chk(ret * 2)) {
				cout << ret * 2 << '\n';
				continue;
			}
			cout << cur << '\n';
			assert(chk(cur));
		}
	}
	return 0;
}