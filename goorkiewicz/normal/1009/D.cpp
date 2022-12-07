#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, i, j;
int inx [100001];
vector < pair <int,int> > out;

int main ()
	{
	scanf ("%d%d",&n,&m);
	for (i=1; i<=n && out.size()<m; i++)
		for (j=(i+1); j<=n && out.size()<m; j++)
			if (__gcd(i,j)==1)
				out.push_back({i,j});
	if (out.size()<m || m<(n-1))
		printf ("Impossible\n");
	else
		{
		printf ("Possible\n");
		for (i=0; i!=out.size(); i++)
			printf ("%d %d\n",out[i].first,out[i].second);
		}
	return 0;
	}