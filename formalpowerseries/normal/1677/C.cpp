#include <iostream>
using namespace std;
typedef long long LL;
int n;
int a[100005], b[100005], p[100005];
bool vis[100005];
int seq[100005], cnt;
void Solve()
{
	cin >> n;
	for (int i = 1; i <= n; ++ i) cin >> a[i];
	for (int i = 1; i <= n; ++ i) cin >> b[i];
	for (int i = 1; i <= n; ++ i) p[a[i]] = b[i];
	for (int i = 1; i <= n; ++ i) vis[i] = false;
	cnt = 0;
	for (int i = 1; i <= n; ++ i) {
		if (!vis[i]) {
			int now = i;
			int siz = 0;
			while (!vis[now]) {
				vis[now] = true;
				now = p[now];
				++ siz;
			}
			seq[++ cnt] = siz - (siz & 1);
		}
	}
	LL ans = 0;
	int res = n;
	for (int i = 1; i <= cnt; ++ i) {
		int v = seq[i] - (seq[i] & 1);
		ans += (LL)(res - v / 2) * v;
		res -= v; 
	}
	cout << ans << endl;
}
int main() {
	int T;
	cin >> T;
	while (T) --T, Solve();
	return 0;
}