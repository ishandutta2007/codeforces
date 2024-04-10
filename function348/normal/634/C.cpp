#include<cstdio>
#include<iostream>
using namespace std;
const int N=200010;
int n,k,a,b,q;
int c[N];
int bit1[N],bit2[N];
void C(int *a,int i,int d) { for (;i<=n;i+=i&-i) a[i]+=d;}
int  Q(int *a,int i) { int res=0;for (;i;i-=i&-i) res+=a[i];return res;}
int main()
{
	scanf("%d%d%d%d%d",&n,&k,&a,&b,&q);
	for (int i=1;i<=q;i++)
	{
		int kd,x,y;
		scanf("%d%d",&kd,&x);
		if (kd==1)
		{
			scanf("%d",&y);
			
			C(bit1,x,-min(c[x],b)),C(bit2,x,-min(c[x],a));
			c[x]+=y;
			C(bit1,x, min(c[x],b)),C(bit2,x, min(c[x],a));
		}
		else
		{
			int ans=Q(bit1,x-1)+Q(bit2,n)-Q(bit2,x+k-1);
			printf("%d\n",ans);
		}
	}
	return 0;
}