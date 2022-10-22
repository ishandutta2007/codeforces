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

const int maxn = 100;
int T, n, k, h[maxn + 5];
int main() {
//	freopen("in.txt", "r", stdin);
	for(scanf("%d", &T); T; T--) {
		scanf("%d%d", &n, &k);h[n + 1] = 0;
		rep(i, 1, n) scanf("%d", &h[i]);
		rep(i, 1, k) {
			int nw = 1;
			while(nw <= n && h[nw] >= h[nw + 1]) nw++;
			if(nw == n + 1) {
				printf("-1\n");
				break;
			} 
			h[nw]++;
			if(i == k) cout << nw << endl;
		}
	} 
	return 0;
}