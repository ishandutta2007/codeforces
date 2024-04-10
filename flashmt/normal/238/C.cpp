#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <int> a[3333],c[3333];
int n;

int backEdge(int x,int par)
{
	int res=0;
	for (int i=0;i<int(a[x].size());i++)
	{
		int y=a[x][i];
		if (y!=par) res+=backEdge(y,x)+c[x][i];
	}
	return res;
}

int best(int x,int par,int profit)
{
	profit=max(0,profit);
	int res=profit;
	for (int i=0;i<int(a[x].size());i++)
	{
		int y=a[x][i];
		if (y!=par)	res=max(res,best(y,x,profit+(c[x][i]?1:-1)));
	}
	return res;
}

int main()
{
	cin >> n;
	for (int i=0;i<n-1;i++)
	{
		int x,y;
		cin >> x >> y;
		a[x].push_back(y); 
		c[x].push_back(0);
		a[y].push_back(x);
		c[y].push_back(1);
	}
	
	int ans=n;
	for (int i=1;i<=n;i++) ans=min(ans,backEdge(i,0)-best(i,0,0));
	
	cout << ans << endl;
}