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
const int maxn = 1e5;
int k, n, m, type, p, c;
ll a[maxn + 5];
P b[maxn + 5];
struct Node {
	int type,id;
	__float128 c;
};
vector<Node> s[maxn + 5];
int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d%d%d", &k, &n, &m);
	rep(i, 1, k) scanf("%d", &a[i]);
	rep(i, 1, n) {
		scanf("%d%d%d", &type, &p, &c);
		if(type == 1) chkmx(b[p], {c, i});
		else if(type == 2) s[p].push_back((Node){2, i, c});
		else s[0].push_back((Node){3, i, c});
	}
	rep(i, 1, k) if(b[i].fi > a[i]) s[i].push_back((Node){1, b[i].se, b[i].fi - a[i]});
	rep(i, 1, k) {
		sort(all(s[i]), [&] (Node x, Node y) {return x.c > y.c;});
		for(auto u : s[i]) s[0].push_back({u.type, u.id, (__float128)(a[i] + u.c) / a[i]}), a[i] += u.c; 
	}
	sort(all(s[0]), [&] (Node x, Node y) {return x.c > y.c;});
	chkmn(m, sz(s[0]));
	sort(s[0].begin(), s[0].begin() + m, [&] (Node x, Node y) {return x.type < y.type;});
	printf("%d\n", m);
	rep(i, 0, m - 1) printf("%d ", s[0][i].id);
	return 0;
}