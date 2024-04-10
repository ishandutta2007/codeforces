#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,a[111],sum,cur,pos;
pair<int,int> b[111];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
		b[i]=make_pair(a[i],i);
	}
	sort(b+2,b+n+1);cur=a[1];
	pos=n;
	for (int i=2;i<=n;i++)
	{
		if (b[i].first*2<=a[1]) cur+=b[i].first;
		else 
		{
			pos=i-1;
			break;
		}
	}
	if (cur*2>sum)
	{
		printf("%d\n",pos);
		printf("1 ");
		for (int i=2;i<=pos;i++) printf("%d ",b[i].second);
	}
	else printf("0\n");
	return Accepted;
}