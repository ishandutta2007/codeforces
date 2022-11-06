#include <cstdio>
#include <algorithm>
using namespace std;
#define mp make_pair

int X[9], Y[9], Ord[5], x, y, r;
bool ok;

int main()
{
	for (int i = 1; i <= 8; i ++)
		scanf("%d%d", X + i, Y + i);
	for (int i = 1; i <= 4; i ++)
		Ord[i] = i;
	sort(Ord + 1, Ord + 4 + 1, [&](int u, int v){
		return mp(X[u], Y[u]) < mp(X[v], Y[v]);
	});
	x = (X[5] + X[6] + X[7] + X[8]) / 4;
	y = (Y[5] + Y[6] + Y[7] + Y[8]) / 4;
	r = max(abs(x - X[5]), abs(y - Y[5]));
	for (int i = X[Ord[1]]; !ok && i <= X[Ord[4]]; i ++)
		for (int j = Y[Ord[1]]; !ok && j <= Y[Ord[4]]; j ++)
			ok = (abs(i - x) + abs(j - y) <= r);
	puts(ok ? "YES" : "NO");
	return 0;
}