#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int dat[15];
void solve()
{
	rep1(i, 10) dat[i] = -1;
	int n, x, y, s = 0;
	scanf("%d", &n);
	rep(i, n) {
		scanf("%d%d", &x, &y);
		dat[y] = max(dat[y], x);
	}
	rep1(i, 10) if(dat[i] == -1) {
		printf("MOREPROBLEMS\n"); return;
	} else s += dat[i];
	printf("%d\n", s);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}