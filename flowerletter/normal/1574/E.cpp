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
#define mk(s, t) make_pair(s, t)
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
const int maxn = 1e6;
const int mod = 998244353;
int n, m, k, cntx[maxn + 5][2], cnty[maxn + 5][2], totx, toty, okx, oky, all[2];
int fpw[maxn + 5];
map<P, int> mp;
inline int add(int a, int b) {return (a += b) >= mod ? a - mod : a;}
inline int sub(int a, int b) {return (a -= b) < 0 ? a + mod : a;}
void del(int x, int y, int c) {
	all[x + y + c & 1] --;
	int s = y + c & 1; 
	if(-- cntx[x][s] == 0) {
		if(cntx[x][!s] == 0) okx ++;
		else totx --;
	}
	int t = x + c & 1;
	if(-- cnty[y][t] == 0) {
		if(cnty[y][!t] == 0) oky ++;
		else toty --;
	}
}
void add(int x, int y, int c) {
	all[x + y + c & 1] ++;
	int s = y + c & 1; 
	if(cntx[x][s] ++ == 0) {
		if(cntx[x][!s] == 0) okx --;
		else totx ++;
	}
	int t = x + c & 1;
	if(cnty[y][t] ++ == 0) {
		if(cnty[y][!t] == 0) oky --;
		else toty ++;
	}
}
int getans() {
	int res = 0;
	if(totx == 0) res = add(res, fpw[okx]);
	if(toty == 0) res = add(res, fpw[oky]);
	res = sub(res, !all[0] + !all[1]); 
	return res;
}
int main() {
	//freopen("in.txt", "r", stdin);
	cin >> n >> m >> k;
	okx = n, oky = m;
	fpw[0] = 1;
	rep(i, 1, max(n, m)) fpw[i] = add(fpw[i - 1], fpw[i - 1]);
	rep(i, 1, k) {
		int x, y, opt;
		cin >> x >> y >> opt;
		if(opt == -1) {
			if(mp.count({x, y})) {
				del(x, y, mp[{x, y}]);
				mp.erase({x, y});
			}
		}
		else if(opt == 0) {
			if(mp.count({x, y})) del(x, y, mp[{x, y}]);
			add(x, y, 0);
			mp[{x, y}] = 0;
		}
		else if(opt == 1) {
			if(mp.count({x, y})) del(x, y, mp[{x, y}]);
			add(x, y, 1);
			mp[{x, y}] = 1;
		}
		cout << getans() << '\n';
	}
	return 0;
}