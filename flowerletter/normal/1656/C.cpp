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
const int maxn = 1e5;
int T, n, a[maxn + 5];
int main() {
	//freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	for(cin >> T; T; T --) {
		cin >> n;
		rep(i, 1, n) cin >> a[i];
		sort(a + 1, a + n + 1);
		if(!count(a + 1, a + n + 1, 1)) cout << "Yes\n";
		else {
			int flag = 1;
			rep(i, 2, n) if(a[i - 1] + 1 == a[i]) flag = 0;
			cout << (a[1] != 0 && flag ? "Yes\n" : "No\n");
		}
	}
	return 0;
}