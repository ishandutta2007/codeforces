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
int n, m, opt, x, a[maxn + 5], cnt[2];
int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	rep(i, 1, n) scanf("%d", &a[i]), cnt[a[i]]++;
	rep(i, 1, m) {
		scanf("%d%d", &opt, &x);
		if(opt == 1) cnt[a[x]]--, cnt[a[x] ^= 1]++;
		else puts(cnt[1] >= x ? "1" : "0");
	}
	return 0;
}