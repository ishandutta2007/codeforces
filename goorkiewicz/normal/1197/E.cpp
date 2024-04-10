#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
const int N = 200005;
int n, i, r, x, p, space, ways, out1, out2;
bool t;
int a [N];
int b [N];
int ans1 [N];
int ans2 [N];
vector < pair < int, pair <bool,int> > > V;

int main ()
	{
	scanf ("%d",&n);
	for (i=1; i<=n; i++)
		{
		scanf ("%d%d",&b[i],&a[i]);
		V.push_back({a[i],{1,i}});
		V.push_back({b[i],{0,i}});
		r = max(r,a[i]);
		}
	sort(V.begin(), V.end());
	p = 0;
	ways = 1;
	for (auto A : V)
		{
		x = A.first;
		i = A.second.second;
		t = A.second.first;
		space += x-p;
		p = x;
		if (t==1)
			{
			ans1[i] = space;
			ans2[i] = ways;
			}
		if (t==0)
			{
			if (ans1[i]<space)
				{
				space = ans1[i];
				ways = ans2[i];
				}
			else if (ans1[i]==space)
				{
				ways += ans2[i];
				if (ways>=mod)
					ways-=mod;
				}
			}
		}
	out1 = 1000000001;
	for (i=1; i<=n; i++)
		if (b[i]>r)
			out1 = min(out1, ans1[i]);
	for (i=1; i<=n; i++)
		if (b[i]>r)
			if (ans1[i]==out1)
				{
				out2+=ans2[i];
				if (out2>=mod)
					out2-=mod;
				}
	printf ("%d\n",out2);
	return 0;
	}