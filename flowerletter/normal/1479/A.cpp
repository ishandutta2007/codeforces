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
typedef pair<int,int> P;

template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
const int maxn = 1e5;
int n, a[maxn + 5];
int ask(int x) {
	if(a[x]) return a[x];
	cout << "? " << x << endl;
	cin >> a[x];
	return a[x];
}
int check(int x) {
	int u = ask(x - 1), v = ask(x);
	return u < v;
}
int main() {
	//freopen("in.txt", "r", stdin);
	cin >> n;
	a[0] = a[n + 1]	= 1e9;
	int l = 1, r = n, ans = -1;
	while(l <= r) {
		int mid = l + r >> 1;
		int nw = check(mid);
		if(nw) r = mid - 1;
		else ans = mid, l = mid + 1;
	}
	cout << "! " << ans << endl;
	return 0;
}