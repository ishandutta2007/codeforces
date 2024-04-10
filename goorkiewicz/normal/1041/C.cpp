#include <bits/stdc++.h>
using namespace std;

int n, x, m, d, i;
set < pair <int,int> > Set;
set < pair <int,int> >::iterator it;
vector < pair <int,int> > del;
int out [200001];

int main ()
	{
	scanf ("%d%d%d",&n,&m,&d);
	for (i=0; i!=n; i++)
		{
		scanf ("%d",&x);
		Set.insert(make_pair(x,i));
		}
	int day = 1;
	while (!Set.empty())
		{
		int p = -1000000001;
		do
			{
			it=Set.upper_bound(make_pair(d+p+1,(-1)));
			del.push_back((*it));
			out[(*it).second]=day;
			p=(*it).first;
			} while (it!=Set.end());
		for (auto a : del)
			Set.erase(a);
		del.clear();
		day++;
		}
	printf ("%d\n",day-1);
	for (i=0; i!=n; i++)
		printf ("%d ",out[i]);
	printf ("\n");
	return 0;
	}