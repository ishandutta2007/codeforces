#include <bits/stdc++.h>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define mset(x, y) memset(x, y, sizeof x)
#define mcpy(x, y) memcpy(x, y, sizeof x)
using namespace std;

typedef long long LL;
typedef pair <int, int> pii;

inline int Read()
{
	int x = 0, f = 1, c = getchar();
	for (; !isdigit(c); c = getchar())
		if (c == '-')
			f = -1;
	for (;  isdigit(c); c = getchar())
		x = x * 10 + c - '0';
	return x * f;
}

const int MAXN = 15;
const int mod = 1e9 + 7;

int n, m, k, use[MAXN], a[MAXN][MAXN], s[MAXN][MAXN];

inline int Dfs(int x, int y){
	if (x == n + 1)
		return 1;
	if (y == m + 1)
		return Dfs(x + 1, 1);
	int p = s[x - 1][y] | s[x][y - 1], cur = -1, ret = 0;
	if (n + m - x - y + 1 > k - __builtin_popcount(p))
		return 0;
	if (~a[x][y]){
		if (p >> a[x][y] & 1)
			return 0;
		s[x][y] = p | 1 << a[x][y];
		return Dfs(x, y + 1);
	}
	else
		for (int i = 0; i < k; i ++)
			if (!(p >> i & 1)){
				s[x][y] = p | 1 << i;
				if (!use[i] ++){
					if (!~cur)
						cur = Dfs(x, y + 1);
					ret = (ret + cur) % mod;
				}
				else
					ret = (ret + Dfs(x, y + 1)) % mod;
				use[i] --;
			}
	return ret;
}

int main(){
	n = Read(), m = Read(), k = Read();
	if (n + m > k + 1)
		return puts("0"), 0;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			if (~(a[i][j] = Read() - 1))
				use[a[i][j]] ++;
	return printf("%d\n", Dfs(1, 1)), 0;
}