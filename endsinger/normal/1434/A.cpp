#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,a[N],b[N],c[N],mx,ans=2e9;
vector<pair<int,int>>v;
int main()
{
	for(int i=1;i<=6;i++)
	{
		scanf("%d",&a[i]);
		a[i]=-a[i];
	}
	sort(a+1,a+7);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	sort(b+1,b+n+1);
	for(int i=1;i<=6;i++)	
		for(int j=1;j<=n;j++)
			v.emplace_back(a[i]+b[j],j);
	sort(v.begin(),v.end());
	mx=a[1]+b[n];
	for(auto it:v)
	{
		int x=it.first,j=it.second,i=c[j]+1;
		ans=min(ans,mx-x);
		c[j]++;
		if(i==6)
			break;
		mx=max(mx,a[i+1]+b[j]);
	}
	printf("%d\n",ans);
	return 0;
}