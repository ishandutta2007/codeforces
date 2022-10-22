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
int T, a, b;
vector<int> ans;
int main() {
	//freopen("in.txt", "r", stdin);
	for(cin >> T; T; T --) {
		cin >> a >> b; ans.clear(); 
		if(a < b) swap(a, b);
		rep(i, 0, a + b) {
			int x = abs(a - (a + b) / 2), y = abs(a - (a + b + 1) / 2);
			if(i >= x && (i - x) % 2 == 0 && (i - x) / 2 <= b|| i >= y && (i - y) % 2 == 0 && (i - y) / 2 <= b) ans.push_back(i); 
		}
		cout << sz(ans) << '\n';
		for(auto x : ans) cout << x << ' '; puts("");
	}
	return 0;
}