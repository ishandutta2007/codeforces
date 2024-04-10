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
typedef set<pair<int, int>> :: iterator sit;

template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
const int maxn = 2000;
int n, m, q, x, l, r, cnt[maxn + 5];
set<P> s1, s2;
bitset<maxn> a[maxn + 5], null;
void check(int x, int y) {
	if((a[x] & a[y]) != a[x]) {
		if(s2.find({x, y}) != s2.end()) s2.erase({x, y});
		else s2.insert({x, y});
	}
}
void del(int x) {
	sit rit = s1.erase(s1.find({a[x].count(), x})), lit = rit;
	if(lit != s1.begin() && rit != s1.end()) lit --, check(lit -> se, rit -> se), check(lit -> se, x);
	else if(lit != s1.begin()) lit --, check(lit -> se, x);
	if(rit != s1.end()) check(x, rit -> se);
}
void add(int x) {
	sit lit = s1.insert({a[x].count(), x}).fi, rit = lit;
	if(++rit != s1.end() && lit != s1.begin()) lit--, check(lit -> se, rit -> se), check(lit -> se, x);
	else if(lit != s1.begin()) lit --, check(lit -> se, x);
	if(rit != s1.end()) check(x, rit -> se);
} 
int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d%d%d", &n, &m, &q);
	rep(i, 1, n) s1.insert({0, i});
	rep(i, 1, q) {
		scanf("%d%d%d", &x, &l, &r);
		del(x);
		a[x] = a[x] ^ (((~null) >> maxn - r + l - 1) << l - 1);
		add(x);
		if(s2.empty()) puts("-1");
		else {
			int x1 = s2.begin() -> fi, x2 = s2.begin() -> se;
			bitset<maxn> z = a[x1] & a[x2];
			int y1 = (a[x1] ^ z)._Find_first() + 1, y2 = (a[x2] ^ z)._Find_first() + 1;
			printf("%d %d %d %d\n", min(x1, x2), min(y1, y2), max(x1, x2), max(y1, y2));			
		}
	}
	return 0;
}