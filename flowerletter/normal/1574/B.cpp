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
#define mk(s, t) make_pair(s, t)
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
int T, a[3],  m;
int main() {
//	freopen("in.txt", "r", stdin);
	for(cin >> T; T; T --) {
		cin >> a[0] >> a[1] >> a[2] >> m;
		sort(a, a + 3);
		if(m > max(0, a[0] - 1) + max(0, a[1] - 1) + max(0, a[2] - 1) || m < max(0, a[2] - a[1] - a[0] - 1)) puts("NO");
		else puts("YES");
	}
	return 0;
}