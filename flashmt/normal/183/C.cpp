#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define N 100100
using namespace std;

int n,d[N],ans,vs[N];
vector <int> a[N],c[N];

int gcd(int x,int y)
{
	return x && y?gcd(y,x%y):x+y;
}

void visit(int x,int D)
{
	vs[x]=1; d[x]=D;
	for (int i=0;i<int(a[x].size());i++)
	{
		int y=a[x][i];
		if (!vs[y]) visit(y,D+c[x][i]);
		else ans=gcd(ans,abs(D+c[x][i]-d[y]));
	}
}

int main()
{
	int m,x,y;
	cin >> n >> m;
	for (int i=0;i<m;i++)
	{
		cin >> x >> y;
		a[x].push_back(y); c[x].push_back(1);
		a[y].push_back(x); c[y].push_back(-1);
	}
	
	for (int i=1;i<=n;i++)
		if (!vs[i]) visit(i,1);
	
	if (!ans) ans=n;		
	cout << ans << endl;
}