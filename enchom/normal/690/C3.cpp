# include <cstdio>
# include <cstring>
# include <vector>

using namespace std;

const int MAX_N = 200024;
const int MAX_M = 200024;

int n, m;
vector <int> v[MAX_N];

int par[MAX_N];
int lvl[MAX_N];

int jump[18][MAX_N];

int enda;
int endb;

void add (int x, int p)
{
	int j;
	par[x] = p;
	lvl[x] = lvl[p] + 1;
	jump[0][x] = p;
	for (j = 1; (1 << j) <= lvl[x]; j ++)
		jump[j][x] = jump[j - 1][jump[j - 1][x]];
}

int lca (int x, int y)
{
	int i, k;
	///printf ("find %d %d %d %d\n", x, y, lvl[x], lvl[y]);
 	while (lvl[x] > lvl[y])
	{
		for (k = 17; k >= 0; k --)
		{
			if (!jump[k][x])
				continue;
			if (lvl[jump[k][x]] >= lvl[y])
				break;
		}
		x = jump[k][x];
	}
	
	///printf ("1 find %d %d %d %d\n", x, y, lvl[x], lvl[y]);
	while (lvl[x] < lvl[y])
	{
		for (k = 17; k >= 0; k --)
		{
			if (!jump[k][y])
				continue;
			if (lvl[jump[k][y]] >= lvl[x])
				break;
		}
		y = jump[k][y];
	}
	
	///printf ("2 find %d %d %d %d\n", x, y, lvl[x], lvl[y]);
	
	if (x == y)
		return x;
	
	while (1)
	{
		///printf ("%d %d\n", x, y);
	
		for (k = 17; k >= 0; k --)
		{
			if (!jump[k][y] || !jump[k][x])
				continue;
			if (jump[k][x] == jump[k][y])
				continue;
			
			break;
		}
		
		if (k != -1)
		{
			x = jump[k][x];
			y = jump[k][y];
		}
		
		if (par[x] == par[y])
			return par[x];
	}
	
}

int main ()
{
	int i, ca, cb, f1, f2, p;
	lvl[1] = 0;
	scanf ("%d", &n);
	enda = 1;
	endb = 1;
	int ans = 0;
	for (i = 2; i <= n; i ++)
	{
		///printf ("%d %d %d\n", enda, endb, ans);
		scanf ("%d", &p);
		///printf ("%d swag\n", p);
		add (i, p);
		
		///printf ("swag\n");
		
		f1 = enda;
		f2 = endb;
		
		ca = lca (enda, i);
		///printf ("%d %d lca %d\n", enda, i, ca);
		
		cb = lca (endb, i);
		
		///printf ("%d %d lca %d\n", endb, i, cb);
		
		if ((lvl[enda] - lvl[ca]) + (lvl[i] - lvl[ca]) > ans)
		{
			ans = (lvl[enda] - lvl[ca]) + (lvl[i] - lvl[ca]);
			f1 = enda;
			f2 = i;
		}
		if ((lvl[endb] - lvl[cb]) + (lvl[i] - lvl[cb]) > ans)
		{
			ans = (lvl[endb] - lvl[cb]) + (lvl[i] - lvl[cb]);
			f1 = endb;
			f2 = i;
		}
		enda = f1;
		endb = f2;
		printf ("%d ", ans);
	}
	printf ("\n");
	return 0;
}