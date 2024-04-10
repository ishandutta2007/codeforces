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
const int maxn = 2000;
const int inf = 1e9;
int n, d[maxn + 5][maxn + 5];
vector<P> ans;
int main() {
	//freopen("in.txt", "r", stdin);
	scanf("%d", &n);
	cout << "? 1" << endl;
	rep(i, 1, n) cin >> d[1][i]; 
	int cnt[2] = {0, 0}, type;
	rep(i, 2, n) cnt[d[1][i] & 1] ++;
	type = cnt[1] < cnt[0];
	if(type == 0) {
		rep(i, 1, n) if(d[1][i] == 1) ans.push_back({1, i});
	}
	rep(u, 2, n) if((d[1][u] & 1) == type) {
		cout << "? " << u << endl;
		rep(i, 1, n) cin >> d[u][i]; 
		rep(i, 1, n) if(d[u][i] == 1) ans.push_back({u, i});
	}
	cout << "!\n";
	for(auto x : ans) printf("%d %d\n", x.fi, x.se); 
	return 0;
}