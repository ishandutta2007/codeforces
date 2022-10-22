/*mjytxdy!*/
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= int(b); i++)
#define per(i, a, b) for(int i = (a); i >= int(b); i--)
#define fir first
#define sec second
#define sz(s) int(s.size())
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const int maxn = 1e6 + 10;

int T, n, k, a[maxn + 5], sum[maxn + 5];
char s[maxn + 5];
vector<int> v;
int main() {
//	freopen("in.txt", "r", stdin);
	for(scanf("%d", &T); T; T--) {
		v.clear();
		scanf("%d%d%s", &n, &k, s + 1);
		rep(i, 1, n) a[i] = s[i] == '1' ? 0 : 1;
		rep(i, 1, n) sum[i] = sum[i - 1] + a[i];
		int lim = min((int)log2(n - k + 1) + 1, k);
		rep(i, 1, n - k + 1) {
			int j = i + k - 1, l = j - lim;
			if(sum[l] - sum[i - 1] == 0) {
				int nw = 0;
				rep(k, l + 1, j) nw |= (a[k] << j - k);
				v.push_back(nw);
			}
		}
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(),v.end()), v.end());
		int flag = 1;
		rep(i, 0, sz(v) - 1) {
			if(v[i] != i) {
				puts("YES");
				per(j, k - 1, lim) putchar('0');
				per(j, lim - 1, 0) printf("%d", (i >> j) & 1);
				puts(""), flag = 0;
				break;
			}
		}
		if(flag && ((k <= 20 && (1 << k) > sz(v)) || (k > 20))) {
			puts("YES"); 
			per(j, k - 1, lim) putchar('0');
			per(j, lim - 1, 0) printf("%d", (sz(v) >> j) & 1);
			puts("");
		}
		else if(flag) {
			puts("NO");
		}
	}
	return 0;
}