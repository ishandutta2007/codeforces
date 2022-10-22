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
const int maxn = 3e5;
int T, n, m, x[maxn + 5], type[maxn + 5], id[maxn + 5], ans[maxn + 5];
char t[2];
stack<int> s[2];
inline bool cmp(int a, int b) {
	return x[a] < x[b];
}
inline int get(int i, int j) {
	if(i < 0) return (x[-i] + x[j]) / 2;
	else return (x[j] - x[i]) / 2;
}
int main() {
//	freopen("in.txt", "r", stdin);
	for(scanf("%d", &T); T; T--) {
		scanf("%d%d", &n, &m);
		rep(i, 1, n) scanf("%d", &x[i]), id[i] = i;
		rep(i, 1, n) scanf("%s", t), type[i] = (t[0] == 'R');
		sort(id + 1, id + n + 1, cmp);
		rep(i, 1, n) {
			int t = x[id[i]] & 1;
			if(type[id[i]]) s[t].push(id[i]);
			else {
				if(s[t].empty()) s[t].push(-id[i]);
				else ans[abs(s[t].top())] = ans[id[i]] = get(s[t].top(), id[i]), s[t].pop(); 
			}
		}
		rep(k, 0, 1) {
			while(s[k].size() >= 2) {
				int j = s[k].top(), i;
				s[k].pop(), i = s[k].top(), s[k].pop();
				if(i < 0) i = -i, x[i] = -x[i];
				if(j < 0) j = -j, x[j] = -x[j];
				ans[i] = ans[j] = (2 * m - x[j] - x[i]) / 2;
			}
			if(!s[k].empty()) ans[abs(s[k].top())] = -1, s[k].pop();
		}
		rep(i, 1, n) printf("%d%c", ans[i], " \n"[i == n]);
	}
	return 0;
}