#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,ans1,ans0,cnt0,cnt1;
int a[100005],b[100005];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&a[i]);
		if(a[i]&1) ans1++;
		else ans0++;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&b[i]);
		if(b[i]&1) cnt1++;
		else cnt0++;
	}
	printf("%d",min(ans1,cnt0)+min(cnt1,ans0));
	return 0;
}