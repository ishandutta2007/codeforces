#include<cstdio>
using namespace std;
int n,r[105],c[105],cnt1,cnt2;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&r[i]);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	for(int i=1;i<=n;i++)
	{
		if(r[i] && !c[i]) cnt1++;
		if(c[i] && !r[i]) cnt2++;
	} 
	if(cnt1==0) printf("-1");
	for(int i=1;i<=1000;i++)
	{
		if(i*cnt1>cnt2)
		{
			printf("%d\n",i);
			return 0;
		}
	}
}