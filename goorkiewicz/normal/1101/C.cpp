#include <bits/stdc++.h>
using namespace std;

int q, n, i, j, l, r, bil;
vector < pair <int,int> > v;
bool occ [200001];
bool out [200001];

int main ()
	{
	scanf ("%d",&q);
	while (q--)
		{
		scanf ("%d",&n);
		fill (out, out+n, false);
		fill (occ, occ+n, false);
		v.clear();
		for (i=0; i<n; i++)
			{
			scanf ("%d%d",&l,&r);
			v.push_back({l, i});
			v.push_back({r, i});
			}
		sort (v.begin(),v.end());
		bil = 0;
		for (i=0; i<v.size(); i++)
			{
			j = v[i].second;
			if (occ[j]==false)
				{
				bil++;
				occ[j]=true;
				out[j]=true;
				}
			else
				{
				occ[j]=false;
				bil--;
				if (bil==0 && i!=v.size()-1 && v[i+1].first>v[i].first)
					break;
				}
			}
		if (i==v.size())
			{
			printf ("-1\n");
			continue;
			}
		for (i=0; i<n; i++)
			printf ("%d ",out[i]==true ? 1 : 2);
		printf ("\n");
		}
	return 0;
	}