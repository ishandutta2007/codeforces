#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cstdlib>

#include <algorithm>
#include <numeric>
#include <limits>
#include <functional>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <queue>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 100010, M = 1000010, P = 1000000007, B = 233;

int hsh[M], pw[M];
char s[N], t[M];
int n, m, a, b;
int ch[2], len[2];

int main() {
#ifdef LBT
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	scanf("%s%s", s + 1, t + 1);
	n = strlen(s + 1);
	m = strlen(t + 1);
	for (int i = 1; i <= m; ++i)
		hsh[i] = (hsh[i - 1] * (ll)B + (t[i] - 'a')) % P;
	pw[0] = 1;
	for (int i = 1; i <= m; ++i)
		pw[i] = pw[i - 1] * (ll)B % P;
	a = count(s + 1, s + n + 1, '0');
	b = n - a;
	int cnt = 0;
	for (int x = 1; m - a * x > 0; ++x) {
		if ((m - a * x) % b == 0) {
			int y = (m - a * x) / b;
			len[0] = x;
			len[1] = y;
//			LOG("(%d, %d)(%d, %d)=%d\n", x, y,a ,b,m);
			int cur = 0;
			memset(ch, -1, sizeof(ch));
			for (int i = 1; i <= n; ++i) {
				int hs = ((hsh[cur + len[s[i] - '0']] - pw[len[s[i] - '0']] * (ll)hsh[cur]) % P + P) % P;
				if (ch[s[i] - '0'] == -1)
					ch[s[i] - '0'] = hs;
				else if (hs != ch[s[i] - '0'])
					break;
				cur += len[s[i] - '0'];
			}
			if (cur == m && (x != y || ch[0] != ch[1]))
				++cnt;
		}
	}
	printf("%d\n", cnt);

#ifdef LBT
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}