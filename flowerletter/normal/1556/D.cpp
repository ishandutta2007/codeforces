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
const int maxlg = 30;
const int maxn = 1e4;
int n, k, a[maxn + 5], b[maxn + 5];
inline int ask(int i, int j, int k) {
	if(k) cout << "and " << i << ' ' << j << endl;
	else cout << "or " << i << ' ' << j << endl;
	int x; cin >> x; return x;
}
int main() {
	//freopen("in.txt", "r", stdin);
	cin >> n >> k;
	rep(i, 2, n) a[i] = ask(1, i, 0), b[i] = ask(1, i, 1);
	int x = ask(2, 3, 0);
	rep(i, 0, maxlg) {
		int flag1 = 1, flag2 = 1;
		rep(j, 2, n) {
			if(1 ^ (a[j] >> i) & 1) flag1 = 0;
			if((b[j] >> i) & 1) flag2 = 0;
		}
		if(!flag1) ;
		else if(!flag2) a[1] |= (1 << i);
		else a[1] |= (1 << i) ^ (x & (1 << i));
	}
	rep(i, 2, n) {
		int x = 0;
		rep(j, 0, maxlg) {
			if((a[1] >> j) & 1) x |=  b[i] & (1 << j);
			else x |= a[i] & (1 << j);
		}
		a[i] = x;
	}
	nth_element(a + 1, a + k, a + n + 1);
	cout << "finish " << a[k] << endl;
	return 0;
}