# include <cstdio>
# include <cstring>
# include <vector>

using namespace std;

const int MAX_N = 1024;
const int MAX_M = 1024;

int n, m;
int pp[MAX_M], qq[MAX_M];
int used[MAX_N];

vector <int> v[MAX_N];
vector <int> idx[MAX_N];

int ban;
int cnt;

void dfs (int x)
{
	int i, sz = v[x].size ();
	used[x] = 1;
	cnt ++;
	for (i = 0; i < sz; i ++)
		if (!used[v[x][i]] && idx[x][i] != ban)
			dfs (v[x][i]);
}

int main ()
{
	int i, j;
	scanf ("%d%d", &n, &m);
	for (i = 1; i <= m; i ++)
	{
		scanf ("%d%d", &pp[i], &qq[i]);
		v[pp[i]].push_back (qq[i]);
		idx[pp[i]].push_back (i);
		v[qq[i]].push_back (pp[i]);
		idx[qq[i]].push_back (i);
	}
	
	ban = 0;
	memset (used, 0, sizeof (used));
	cnt = 0;
	dfs (1);
	if (cnt < n)
	{
		printf ("no\n");
		return 0;
	}
	
	for (i = 1; i <= m; i ++)
	{
		ban = i;
		memset (used, 0, sizeof (used));
		cnt = 0;
		dfs (1);
		if (cnt == n)
		{
			///printf ("%d\n", ban);
			printf ("no\n");
			return 0;
		}
	}
	
	printf ("yes\n");
	
	return 0;
}