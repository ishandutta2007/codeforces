/*mjytxdy!*/
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= int(b); i++)
#define per(i, a, b) for(int i = (a); i >= int(b); i--)
#define fi first
#define se second
#define all(s) s.begin(),s.end()
#define trv(i, u) for(int i = head[u]; i; i = e[i].next)
#define sz(s) (int)(s.size())
#define lb(s) (s & -s)
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
int q, u, v;
int main() {
//	freopen("in.txt", "r", stdin);
	for(scanf("%d", &q); q; q--) {
		scanf("%d%d", &u, &v);
		if(u > v) {
			puts("NO");
			continue;
		}
		int nw = 0;
		rep(i, 0, 29) {
			nw += (u >> i & 1), nw -= (v >> i & 1);
			if(nw < 0) {puts("NO"); nw = -1; break;}
		}
		if(nw != -1) puts("YES");
	}
	return 0;
}