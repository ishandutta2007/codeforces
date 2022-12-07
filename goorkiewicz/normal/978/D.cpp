#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000001;
int n, i, out;
int t [100001];
int r [100001];

int check (int d1, int d2)
	{
	int res=0;
	for (i=0; i!=n; i++)
		r[i]=t[i];
	if (d1!=0)
		res++;
	if (d2!=0)
		res++;
	r[0]+=d1;
	r[1]+=d2;
	int f = (r[0]-r[1]);
	for (i=2; i<n; i++)
		{
		if (r[i-1]-r[i]!=f)
			{
			if (abs(r[i]-(r[i-1]-f))==1)
				{
				res++;
				r[i]=(r[i-1]-f);
				}
			else
				return inf;
			}
		}
	return res;
	}

int main ()
	{
	scanf ("%d",&n);
	for (i=0; i!=n; i++)
		scanf ("%d",&t[i]);
	out=inf;
	out=min(out,check(-1,-1));
	out=min(out,check(-1, 0));
	out=min(out,check(-1, 1));
	out=min(out,check( 0,-1));
	out=min(out,check( 0, 0));
	out=min(out,check( 0, 1));
	out=min(out,check( 1,-1));
	out=min(out,check( 1, 0));
	out=min(out,check( 1, 1));
	if (out==inf)
		printf ("-1\n");
	else
		printf ("%d\n",out);
	return 0;
	}