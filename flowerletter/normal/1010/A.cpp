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
const double eps = 1e-6;
int n, m, a[maxn + 5], b[maxn + 5];
bool check(double x) {
	rep(i, 1, n) {
		x -= (x + m) / a[i];
		if(x < -1e-10) return false; 
		x -= (x + m) / b[i + 1];
		if(x < -1e-10) return false;
	}
	return true;
}
int main() {
	//freopen("in.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	rep(i, 1, n) scanf("%d", &a[i]);
	rep(i, 1, n) scanf("%d", &b[i]);
	b[n + 1] = b[1];
	if(!check(1e9)) return puts("-1"), 0;
	double l = 0, r = 1e9;
	while(r - l > eps) {
		double mid = (l + r) / 2;
		if(check(mid)) r = mid;
		else l = mid;
	}
	printf("%.10lf", r);
	return 0;
}