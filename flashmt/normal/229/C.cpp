#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	//ios::sync_with_stdio(false);
	int n,m,x,y;
	cin >> n >> m;
	vector <int> d(n+1,0);
	for (int i=0;i<m;i++) scanf("%d%d",&x,&y), d[x]++, d[y]++;
	
	long long ans=0;
	for (int i=1;i<=n;i++)
	{
		ans+=1LL*d[i]*(d[i]-1);
		ans+=1LL*(n-d[i]-1)*(n-d[i]-2);
		ans-=1LL*(n-d[i]-1)*d[i];
	}
	
	cout << ans/6 << endl;
}