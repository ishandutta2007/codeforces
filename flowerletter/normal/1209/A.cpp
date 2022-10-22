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
const int maxn = 100;
int n, a[maxn + 5];
int ans, vis[maxn + 5];
int main() {
	//freopen("in.txt", "r", stdin);
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]);
	sort(a + 1, a + n +1);
	rep(i, 1, n) if(!vis[i]) {
		vis[i] = 1, ans ++;
		rep(j, i + 1, n) if(a[j] % a[i] == 0) vis[j] = 1;
	}
	cout << ans << endl;
	return 0;
}