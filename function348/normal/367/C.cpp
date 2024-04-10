#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
int n,m;
int w[100010];
int main()
{
	scanf("%d%d",&n,&m);
	int x;
	for (int i=1;i<=m;i++) scanf("%d%d",&x,&w[i]);
	sort(w+1,w+1+m,greater<int>());
	LL tot=0;
	LL ans=0;
	for (int i=1;i<=m;i++)
	{
		LL t=1LL*i*(i-1)/2+1;
		tot+=w[i];
		if (i%2==0) t+=i/2-1;
		if (t<=n) ans=max(ans,tot);
	}
	cout<<ans<<endl;
	return 0;
}