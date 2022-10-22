#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= int(b); i ++)
#define per(i, a, b) for(int i = (a); i >= int(b); i --)
#define fi first
#define se second
#define all(s) s.begin(), s.end()
#define trv(i, u, v) for(int i = head[u], v = e[i].to; i; v = e[i = e[i].nxt].to)
#define sz(s) (int)(s.size())
#define lb(s) ((s) & (-s))
#define mk make_pair
#define pb push_back
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
template <int T> using A = array<int, T>;
inline int read() {
	int x = 0, f = 1; char c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-')  f = 0;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}
const int maxn = 1e3;
int n, d, cnt, fa[maxn + 5], siz[maxn + 5];
int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
multiset<int> s;
int getans() {
	auto it = -- s.end();
	int res = 0;
	rep(i, 0, cnt) {
		res += *it;
		if(it == s.begin()) return res - 1;
		it --;
	}
	return res - 1;
}
int main() {
//	freopen("in.txt", "r", stdin);
	n = read(), d = read();
	rep(i, 1, n) fa[i] = i, siz[i] = 1, s.insert(1);
	rep(i, 1, d) {
		int x = read(), y = read();
		int fx = find(x), fy = find(y);
		if(fx != fy) {
			fa[fx] = fy;
			s.erase(s.find(siz[fx]));
			s.erase(s.find(siz[fy]));
			siz[fy] += siz[fx];
			s.insert(siz[fy]);
		}
		else {
			cnt ++;
		}
		cout << getans() << '\n';
	}
	return 0;
}