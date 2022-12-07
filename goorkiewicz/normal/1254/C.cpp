#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, i, r1, r2;
ll dis [1005];

ll RES;
ll Q (int x, int a, int b, int c)
	{
	printf ("%d %d %d %d\n", x, a, b, c);
	fflush(stdout);
	scanf ("%lld", &RES);
	return RES;
	}

bool cmp (int a, int b){
	return dis[a]<dis[b];
	}

vector <int> v1, v2, v11, v12, v21, v22;

int main ()
	{
	scanf ("%d",&n);
	
	for (i=3; i<=n; i++)
		{
		if (Q(2, 1, i, 2)==1)
			v1.push_back(i);
		else
			v2.push_back(i);
		dis[i] = Q(1, 1, 2, i);
		}

	r1 = 0;
	for (int u : v1)
		if (r1==0 || dis[u]>dis[r1])
			r1 = u;

	r2 = 0;
	for (int u : v2)
		if (r2==0 || dis[u]>dis[r2])
			r2 = u;

	for (int u : v1)
		{
		if (u==r1) continue;
		if (Q(2, 1, u, r1)==1)
			v11.push_back(u);
		else
			v12.push_back(u);
		}

	for (int u : v2)
		{
		if (u==r2) continue;
		if (Q(2, 1, u, r2)==1)
			v21.push_back(u);
		else
			v22.push_back(u);
		}

	sort(v11.begin(), v11.end(), cmp);
	sort(v12.begin(), v12.end(), cmp);
	sort(v21.begin(), v21.end(), cmp);
	sort(v22.begin(), v22.end(), cmp);

	reverse(v12.begin(), v12.end());
	reverse(v22.begin(), v22.end());

	printf ("0 1 ");
	for (int u : v11) printf ("%d ", u);
	if (r1!=0) printf ("%d ", r1);
	for (int u : v12) printf ("%d ", u);
	printf ("2 ");
	for (int u : v21) printf ("%d ", u);
	if (r2!=0) printf ("%d ", r2);
	for (int u : v22) printf ("%d ", u);
	printf ("\n");
	fflush(stdout);
	return 0;
	}