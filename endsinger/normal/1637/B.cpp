#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,a[N],s[N],ans;
void sol()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+(a[i]==0);
	ans=0;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			ans+=j-i+1+s[j]-s[i-1];
	printf("%d\n",ans);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}