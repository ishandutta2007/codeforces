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

int T;
ll n, k;
int main() {
//	freopen("in.txt", "r", stdin);
	for(scanf("%d", &T); T; T--) {
		scanf("%lld%lld", &n, &k);
		if(n % k == 0) printf("%lld\n", n / k * k / n);
		else printf("%lld\n", ((n / k + 1) * k + n - 1)/ n);
	}
	return 0;
}