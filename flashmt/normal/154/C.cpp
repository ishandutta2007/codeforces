#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

long long p[1000100],h[1000100],g[1000100],ans;

int main()
{
	int m,n,x,y;
	
	cin >> n >> m;
	for (int i=0;i<=n;i++) p[i]=(i?p[i-1]*1162789:1);
	
	while (m--)
	{
		scanf("%d%d",&x,&y);
		h[x]+=p[y];
		h[y]+=p[x];
	}
	
	for (int i=1;i<=n;i++) g[i]=h[i]+p[i];
	sort(h+1,h+n+1);
	for (int i=1,cnt=0;i<=n;i++)
		if (h[i]==h[i-1]) ans+=cnt++;
		else cnt=1;
	
	sort(g+1,g+n+1);
	for (int i=1,cnt=0;i<=n;i++)
		if (g[i]==g[i-1]) ans+=cnt++;
		else cnt=1;
		
	cout << ans << endl;
}