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
typedef unsigned long long ull;
typedef pair<int,int> P;
 
template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
 
const int maxn = 5000;
int n, x[maxn + 5], y[maxn + 5], id[maxn + 5];
ull dis[maxn + 5][maxn + 5];
bool check(int i, int j, int k) {
	ull c = dis[i][j];
	ull a = dis[j][k];
	ull b = dis[i][k];
	return a + c <= b; 
}
int main() {
	//freopen("in.txt", "r", stdin);
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d%d", &x[i], &y[i]), id[i] = i;
	rep(i, 1, n) rep(j, 1, n) dis[i][j] = 1ll * (x[i] - x[j]) * (x[i] - x[j]) + 1ll * (y[i] - y[j]) * (y[i] - y[j]);
	while(true) {
		int flag = 1;
		rep(j, 1, n - 2) {
			if(check(id[j], id[j + 1], id[j + 2])) swap(id[j + 1], id[j + 2]), flag = 0;
		}
		if(flag) break;
	}
	rep(i, 1, n) printf("%d ", id[i]);
	return 0;
}