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
int n, ans, last, a[maxn + 5];
int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]);
	for(int l = 1,r; l <= n; l = r + 1) {
		r = l;
		while(r + 1 <= n && a[r + 1] == a[l]) r++;
		if(r - l + 1 >= 2) {
			if(a[last] != a[l]) ans += 2;
			else {
				ans++;
				rep(i, last + 1, l - 2) {
					if(a[i - 1] != a[i + 1] && a[i] != a[l]) {
						ans++;
						break;
					}
				}
			}
			last = r;
		}
		else ans++;
	}
	cout << ans << endl;
	return 0;
}