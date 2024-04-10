/*mjytxdy!*/
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= int(b); i++)
#define per(i, a, b) for(int i = (a); i >= int(b); i--)
#define fi first
#define se second
#define all(s) s.begin(),s.end()
#define trv(i, u) for(int i = head[u]; i; i = e[i].next)
#define sz(s) (int)(s.size())
#define lb(s) ((s) & (-s))
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
const int maxw = 250;
const int mod = 1e9 + 7;
int n, m, k, mask, lim, ans;
inline void upd(int &x) {x = (x >= mod) ? (x - mod) : x;}
struct Mat {
	int a[maxw][maxw];
	Mat() {memset(a, 0, sizeof a);}
	inline int* operator [] (int x) {return a[x];}
	inline friend Mat operator * (Mat x, Mat y) {
		Mat ans;
		rep(i, 0, lim) rep(j, 0, lim) rep(k, 0, lim) upd(ans[i][j] += 1ll * x[i][k] * y[k][j] % mod);
		return ans;
	}
}x, y;
Mat fpw(Mat a, int b) {
	Mat ans = a; b--;
	for(; b; b >>= 1, a = a * a) if(b & 1) ans = ans * a;
	return ans;	 
}
inline int id(int i, int j) {return i * (mask + 1) + j;}
int main() {
	//freopen("in.txt", "r", stdin);
	scanf("%d%d%d", &n, &k, &m), mask = (1 << m) - 1, lim = (k + 1) * (mask + 1) - 1;
	rep(i, 0, mask) rep(j, 0, k - 1) y[id(j, i)][id(j + 1, (1 | ((i << 1) & mask)))] = 1 + __builtin_popcount(i);
	rep(i, 0, mask) rep(j, 0, k) y[id(j, i)][id(j, ((i << 1) & mask))] = 1;
	x[0][0] = 1, x = x * fpw(y, n);
	rep(i, id(k, 0), lim) upd(ans += x[0][i]);
	printf("%d\n", ans);
	return 0;
}