#include <bits/stdc++.h>
using namespace std;

int n, h, i, j, a, b, pn, points, out;
vector < pair <int,int> > vec;

int main ()
	{
	scanf ("%d%d",&n,&h);
	for (i=0; i!=n; i++)
		{
		scanf ("%d%d",&a,&b);
		vec.push_back(make_pair(a-pn,(b-a)));
		pn+=(b-a);
		}
	points = vec[0].second;
	for (i=0; i!=vec.size(); i++)
		{
		while (j!=vec.size() && vec[j].first-vec[i].first<h)
			{
			j++;
			if (j!=vec.size())
				points+=vec[j].second;
			}
		if (j!=vec.size())
			{
			points-=vec[j].second;
			j--;
			}
		out = max(out,points);
		points -= vec[i].second;
		}
	printf ("%d\n",h+out);
	return 0;
	}