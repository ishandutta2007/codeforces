#include<cstdio>
#include<iostream>
using namespace std;
typedef long long LL;
const int N=1000100;
int n;
LL c[N];
void mk(int l,int r,int a,int t)
{
//	printf("%d %d %d %d\n",l,r,a,t);
	c[l]+=a;
	c[l+1]+=t-a;
	c[r+1]-=a+(r-l+1)*t;
	c[r+2]+=a+(r-l)*t;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		if (a>=i)
		{
			mk(1,i,a-i,1);
			mk(i+1,n+i+1-a,n-a,-1);
			mk(n+i+2-a,n,1,1);
		}
		else
		{
			mk(1,i-a+1,i-a,-1);
			mk(i-a+2,i,1,1);
			mk(i+1,n,n-a,-1);
		}
	}
	for (int i=1;i<=n;i++) c[i]+=c[i-1];
	for (int i=1;i<=n;i++) c[i]+=c[i-1];
	int k=1;
//	for (int i=1;i<=n;i++) cout<<c[i]<<' ';cout<<endl;
	for (int i=1;i<=n;i++)
	if (c[i]<c[k]) k=i;
	printf("%I64d ",c[k]);
	printf("%d\n",(n+1-k)%n);
	return 0;
}