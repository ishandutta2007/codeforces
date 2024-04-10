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
const int maxn = 2e5;
int n, m[maxn + 5], k[maxn + 5], k_[maxn + 5], id[maxn + 5];
ll s[maxn + 5];
vector<int> out;
int main() {
//	freopen("in.txt", "r", stdin);
	n = read();
	rep(i, 1, n) m[i] = read(), k[i] = read(), s[m[i]] += k[i];
	ll sum = 0, cnt = 0, ans = -1, ret = 0;
	rep(i, 1, maxn) id[i] = i;
	sort(id + 1, id + maxn + 1, [&] (int x, int y) {return s[x] > s[y];});
	rep(i, 1, 20) sum += s[id[i]];
	rep(i, 21, maxn) {
		sum += s[id[i]];
		if(ans == -1 || ans * i < sum * ret) {
			ans = sum, ret = i;
		}
	}
	out = vector<int>(id + 1, id + ret + 1);
	rep(i, 1, 20) {
		rep(j, 1, maxn) s[j] = 0, id[j] = j;
		rep(j, 1, n) k_[j] = min(k[j], i), s[m[j]] += k_[j];
		nth_element(id + 1, id + i + 1, id + maxn + 1, [&] (int x, int y) {return s[x] > s[y];});
		sum = 0;
		rep(j, 1, i) sum += s[id[j]];
		if(ans == -1 || ans * i < sum * ret) {
			out = vector<int> (id + 1, id + i + 1);
			ans = sum, ret = i;
		}
	}
	cout << sz(out) << '\n';
	for(auto x : out) cout << x << ' ';
	return 0;
}