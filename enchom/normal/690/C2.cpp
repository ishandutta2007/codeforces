# include <cstdio>
# include <cstring>
# include <vector>

using namespace std;

const int MAX_N = 200024;
const int MAX_M = 200024;

int n, m;
int pp, qq;
vector <int> v[MAX_N];

int ans[MAX_N];

int rans;

void dfs (int x, int par)
{
	int i, sz = v[x].size (), idxm = -1, idxn = -1;
	for (i = 0; i < sz; i ++)
	{
		if (v[x][i] == par)
			continue;
		dfs (v[x][i], x);
		if (idxm == -1)
			idxm = v[x][i];
		else
		{
			if (ans[idxm] < ans[v[x][i]])
				idxm = v[x][i];
		}
	}
	for (i = 0; i < sz; i ++)
	{
		if (v[x][i] == par)
			continue;
		if (v[x][i] == idxm)
			continue;
		if (idxn == -1)
			idxn = v[x][i];
		else
		{
			if (ans[idxn] < ans[v[x][i]])
				idxn = v[x][i];
		}
	}
	int crr = 0;
	if (idxm != -1)
		crr += ans[idxm] + 1;
	if (idxn != -1)
		crr += ans[idxn] + 1;
	rans = max (rans, crr);
	ans[x] = 0;
	if (idxm != -1)
		ans[x] = ans[idxm] + 1;
	/**
	printf ("%d %d %d\n", x, idxm, idxn);
	if (idxm != -1)
		printf ("%d\n", ans[idxm]);
	if (idxn != -1)
		printf ("%d\n", ans[idxn]);
	printf ("%d %d\n", x, ans[x]); 
	**/
	rans = max (rans, ans[x]);
}

int main ()
{
	int i, j;
	scanf ("%d%d", &n, &m);
	for (i = 1; i <= m; i ++)
	{
		scanf ("%d%d", &pp, &qq);
		v[pp].push_back (qq);
		v[qq].push_back (pp);
	}
	
	dfs (1, -1);
	
	printf ("%d\n", rans);
	
	return 0;
}