#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef pair<int, int> Pii;
#define N 2000000 + 5
#define Mod 998244353
 
int n, m, k, cr, cc, sr, sc, C[2], Row[N][2], Col[N][2], Pow[N];
map<Pii, int> Map;
 
inline int GetCol(int x, int y)
{
	Pii p = make_pair(x, y);
	if (Map.count(p) == 0)
		return -1;
	return Map.at(p);
}
 
inline void Del(int x, int y, int t)
{
	int r = (y & 1) ^ t, c = (x & 1) ^ t, w = ((x + y) & 1) ^ t;
	Row[x][r] --, Col[y][c] --, C[w] --;
	if (Row[x][r] == 0 && Row[x][r ^ 1] != 0)
		sr --;
	if (Col[y][c] == 0 && Col[y][c ^ 1] != 0)
		sc --;
	if (Row[x][r] == 0 && Row[x][r ^ 1] == 0)
		cr --;
	if (Col[y][c] == 0 && Col[y][c ^ 1] == 0)
		cc --;
	Map.erase(make_pair(x, y));
}
 
inline void Add(int x, int y, int t)
{
	int r = (y & 1) ^ t, c = (x & 1) ^ t, w = ((x + y) & 1) ^ t;
	if (Row[x][r] == 0 && Row[x][r ^ 1] != 0)
		sr ++;
	if (Col[y][c] == 0 && Col[y][c ^ 1] != 0)
		sc ++;
	if (Row[x][r] == 0 && Row[x][r ^ 1] == 0)
		cr ++;
	if (Col[y][c] == 0 && Col[y][c ^ 1] == 0)
		cc ++;
	Row[x][r] ++, Col[y][c] ++, C[w] ++;
	Map.emplace(make_pair(x, y), t);
}
 
inline int GetAns()
{
	if (sr && sc)
		return 0;
	if (sr)
		return Pow[m - cc];
	if (sc)
		return Pow[n - cr];
	return (LL(Pow[m - cc]) + Pow[n - cr] + Mod - (C[0] == 0 ? 1 : 0) - (C[1] == 0 ? 1 : 0)) % Mod;
}
 
int main()
{
	scanf("%d%d%d", &n, &m, &k);
	Pow[0] = 1;
	for (int i = 1; i <= n + m; i ++)
		Pow[i] = 2 * Pow[i - 1] % Mod;
	for (int i = 1, x, y, t; i <= k; i ++)
	{
		scanf("%d%d%d", &x, &y, &t);
		int col = GetCol(x, y);
		if (col != -1)
			Del(x, y, col);
		if (t != -1)
			Add(x, y, t);
		printf("%d\n", GetAns());
	}
	return 0;
}