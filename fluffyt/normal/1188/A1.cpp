#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int d[200005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		d[x]++,d[y]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(d[i]==2)
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}