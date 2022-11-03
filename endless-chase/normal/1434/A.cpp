#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,test,a[11],b[111111],pos[111111],mx,cnt,ans;
bool flg;
pair<int,int> val[666666];
int main()
{
	for (int i=1;i<=6;i++) scanf("%d",&a[i]);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	sort(a+1,a+7);
	reverse(a+1,a+7);
	sort(b+1,b+n+1);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=6;j++)
		{
			val[++cnt]=make_pair(b[i]-a[j],i);
		}
	}
	sort(val+1,val+cnt+1);
	for (int i=1;i<=n;i++) 
	{
		pos[i]=1;
		mx=max(mx,b[i]-a[1]);
	}
	ans=2e9;
	for (int i=1;i<=cnt;i++)
	{
		if (!flg) ans=min(ans,mx-val[i].first);
		pos[val[i].second]++;
		if (pos[val[i].second]==7) flg=1;
		mx=max(mx,b[val[i].second]-a[pos[val[i].second]]);
	}
	printf("%d\n",ans);
	return Accepted;
}