#include <map>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef pair <int, int> Pii;
#define mp make_pair

int n, k, u, v, x, y, z;
map <Pii, Pii> Map;

inline bool cmp(int a_1, int b_1, int c_1, int a_2, int b_2, int c_2)
{
	if (a_1 > b_1) swap(a_1, b_1);
	if (a_1 > c_1) swap(a_1, c_1);
	if (a_2 > b_2) swap(a_2, b_2);
	if (a_2 > c_2) swap(a_2, c_2);
	return a_1 < a_2;
}

inline void Update(int a, int b, int c, int id)
{
	if (!k || cmp(x, y, z, a, b, c))
	{
		k = 1;
		x = a, y = b, z = c, u = id;
	}
	if (Map.find(mp(a, b)) != Map.end())
	{
		Pii t = Map[mp(a, b)];
		if (!k || cmp(x, y, z, a, b, c + t.first))
		{
			k = 2;
			x = a, y = b, z = c + t.first;
			u = t.second, v = id;
		}
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if (a > b) swap(a, b);
		if (b > c) swap(b, c);
		if (a > b) swap(a, b);
		Update(a, b, c, i);
		Update(a, c, b, i);
		Update(b, c, a, i);
		if (Map[mp(a, b)] < mp(c, i)) Map[mp(a, b)] = mp(c, i);
		if (Map[mp(a, c)] < mp(b, i)) Map[mp(a, c)] = mp(b, i);
		if (Map[mp(b, c)] < mp(a, i)) Map[mp(b, c)] = mp(a, i);
	}
	printf("%d\n%d", k, u);
	if (k > 1) printf(" %d\n", v);
	return 0;
}