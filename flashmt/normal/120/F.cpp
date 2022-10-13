#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int re,n,r;
vector <int> a[111];

int visit(int x,int par)
{
	int m1=0,m2=0;
	for (int i=0;i<int(a[x].size());i++)
	{
		int y=a[x][i];
		if (y==par) continue;
		int z=visit(y,x)+1;
		if (z>m1) m2=m1, m1=z;
		else if (z>m2) m2=z;
	}
	r=max(m1+m2,r);
	return m1;
}

int main()
{
	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	int test;
	cin >> test;
	while (test--)
	{
		cin >> n;
		for (int i=1;i<=n;i++) a[i].clear();
		for (int i=1;i<n;i++)
		{
			int x,y;
			cin >> x >> y;
			a[x].push_back(y);
			a[y].push_back(x);
		}
		r=0;
		visit(1,0);
		re+=r;
	}
	cout << re << endl;
}