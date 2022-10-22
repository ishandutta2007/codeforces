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
const int maxn = 500;
int n, k, ans, x, tp[maxn + 5];
int main() {
	//freopen("in.txt", "r", stdin);
	scanf("%d%d", &n, &k);
	if(k % 2 == 0 && n % 2 == 1) return cout << -1 << endl, 0;
	int t = (n - 1) / k;
	do {
		t++;
		while((t * k + n - 1) / 2 / n * 2 + 1 > t) t ++;
	}while((t % 2 == 0 && k % 2 == 1 && n % 2 == 1) || (t % 2 == 1 && k % 2 == 1 && n % 2 == 0));
	//cout << (t * k + n - 1) / 2 / n * 2 + 1 << ' ' << t << endl; 
	int c = (t * k - n) / 2 / n * 2 + 1, d = (t * k - n) % (2 * n) / 2;
	//assert(t * k % 2 == n % 2);
	rep(i, 1, n) tp[i] = c + 2 * (i <= d);
	rep(i, 1, t) {
		vector<P> s;
		rep(i, 1, n) s.push_back({tp[i], i});
		sort(all(s)), reverse(all(s));
		cout << "?";
		rep(j, 0, k - 1) cout << ' ' << s[j].se, tp[s[j].se] --;
		cout << endl;
		cin >> x; ans ^= x;
	}
	cout << "! " << ans << endl; 
	return 0;
}