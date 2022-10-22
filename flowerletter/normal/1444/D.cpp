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
const int maxn = 1000;
const int maxw = 5e5;
int T, n, m, a[maxn + 5], b[maxn + 5];
bitset<maxw> dp[maxn + 5];
vector<int> x[2], y[2];
bool check(int a[], vector <int> &x, vector<int> &y) {
	int sum = 0;
	rep(i, 1, n) sum += a[i], dp[i].reset();
	if(sum & 1) return 0;
	sum >>= 1, dp[0].set(0);
	rep(i, 1, n) dp[i] = dp[i - 1] | (dp[i - 1] << a[i]);
	if(!dp[n][sum]) return 0;
	per(i, n, 1) 
		if(!dp[i - 1][sum]) x.push_back(a[i]), sum -= a[i];
		else y.push_back(a[i]);
	return 1;
}
int main() {
	//freopen("in.txt", "r", stdin);
	for(scanf("%d", &T); T; T--) {
		scanf("%d", &n), x[0].clear(), x[1].clear(), y[0].clear(), y[1].clear();
		rep(i, 1, n) scanf("%d", &a[i]);
		scanf("%d", &m);
		rep(i, 1, m) scanf("%d", &b[i]);
		if(n != m) {puts("NO"); continue;}
		if(!check(a, x[0], x[1]) || !check(b, y[0], y[1])) {puts("NO"); continue;}
		puts("YES");
		sort(all(x[0])), sort(all(x[1]));
		sort(all(y[0])), sort(all(y[1])); 
		int nwx = 0, nwy = 0;;
		if(sz(x[0]) > sz(y[0])) swap(x[0], x[1]), swap(y[0], y[1]);
		rep(i, 0, sz(x[0]) - 1) {
			nwx += x[0][sz(x[0]) - 1 - i];
			cout << nwx << ' ' << nwy << endl;
			nwy -= y[0][sz(y[0]) - sz(x[0]) + i];
			cout << nwx << ' ' << nwy << endl;
		}
		rep(i, 0, sz(y[0]) - sz(x[0]) - 1) {
			nwx -= x[1][sz(y[1]) + i];
			cout << nwx << ' ' << nwy << endl;
			nwy -= y[0][sz(y[0]) - sz(x[0]) - i - 1];
			cout << nwx << ' ' << nwy << endl; 
		} 
		rep(i, 0, sz(y[1]) - 1) {
			nwx -= x[1][sz(y[1]) - i - 1];
			cout << nwx << ' ' << nwy << endl;
			nwy += y[1][i];
			cout << nwx << ' ' << nwy << endl;
		}
	}
	return 0;
}