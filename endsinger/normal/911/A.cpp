#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int a[N],n,m=1e9;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		m=min(m,a[i]);
	}
	int ans=1e9,l=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==m)
		{
			if(l)
				ans=min(ans,i-l);
			l=i;
		}
	}
	printf("%d\n",ans);
	return 0;
}