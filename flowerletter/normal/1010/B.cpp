/*mjytxdy!*/
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= int(b); i ++)
#define per(i, a, b) for(int i = (a); i >= int(b); i --)
#define fi first
#define se second
#define all(s) s.begin(),s.end()
#define trv(i, u, v) for(int i = head[u], v = e[i].to; i; v = e[i = e[i].next].to)
#define sz(s) (int)(s.size())
#define lb(s) ((s) & (-s))
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
const int maxn = 30;
int n, m, cnt, p[maxn + 5];
inline int ask(int x) {
	cout << x << endl;
	int t; cin >> t;
	return t;
}
int main() {
	//freopen("in.txt", "r", stdin);
	cin >> m >> n;
	rep(i, 1, n) if(!(p[i] = ask(m))) return 0;
	int l = 1, r = m, ans = -1;
	while(l <= r) {
		int mid = l + r >> 1, k = ask(mid);
		if(!k) return 0;
		if(k == p[++cnt]) r = mid - 1;
		else l = mid + 1;
		cnt %= n;
	}
	return 0;
}