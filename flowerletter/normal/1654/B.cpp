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
char s[maxn + 5];
int T, n, cnt[26];
int main() {
//	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	for(cin >> T; T; T --) {
		cin >> s + 1;
		n = strlen(s + 1);
		rep(i, 0, 25) cnt[i] = 0;
		rep(i, 1, n) {
			cnt[s[i] - 'a'] ++;
		}
		int flg = 1;
		rep(i, 1, n) if(cnt[s[i] - 'a'] == 1) {
			cout << s + i << '\n';
			flg = 0;
			break;
		} else {
			cnt[s[i] - 'a'] --;
		}
		if(flg) cout << s[n] << '\n';
	}
	return 0;
}