#include<cstdio>
#include<iostream>
using namespace std;
const int N=200010;
int a[N],bit[N];
int n,m,L,sh,rev;
void C(int i,int dlt) { for (;i<=sh+L;i+=i&-i) bit[i]+=dlt;}
int  Q(int i) { int ans=0;for (;i;i-=i&-i) ans+=bit[i];return ans;}
int main()
{
	scanf("%d%d",&n,&m);
	L=n;
	for (int i=1;i<=L;i++) a[i]=1,bit[i]=i&-i;
	sh=1,rev=0;
	while (m--)
	{
		int kd;
		scanf("%d",&kd);
		if (kd==1)
		{
			int k;
			scanf("%d",&k);
			if (2*k>L) 
			{
				if (rev)
				{
					for (int i=L-k;i<2*(L-k);i++)
					{
						a[sh+i]+=a[sh+2*(L-k)-1-i];
						C(sh+i,a[sh+2*(L-k)-1-i]);
						C(sh+2*(L-k)-1-i,-a[sh+2*(L-k)-1-i]);
						a[sh+2*(L-k)-1-i]=0;
					}
					sh+=L-k;
				}
				else
				{
					for (int i=k;i<L;i++)
					{
						a[sh+2*k-1-i]+=a[sh+i];
						C(sh+2*k-1-i,a[sh+i]);
						C(sh+i,-a[sh+i]);
						a[sh+i]=0;
					}
					
				}
				rev^=1;
				L=k;
			}
			else
			{
				if (rev) 
				{
					for (int i=L-k;i<L;i++) 
					{
						a[2*(L-k)-1-i+sh]+=a[i+sh];
						C(2*(L-k)-1-i+sh,a[i+sh]);
						C(i+sh,-a[i+sh]);
						a[i+sh]=0;
					}
				}
				else
				{
					for (int i=0;i<k;i++)
					{
						a[(2*k-1)-i+sh]+=a[i+sh];
						C((2*k-1)-i+sh,a[i+sh]);
						C(i+sh,-a[i+sh]);
						a[i+sh]=0;
					}
					sh+=k;
				}
				L-=k;
			}
		}
		else
		{
			int l,r;
			scanf("%d%d",&l,&r);
			if (rev) { swap(l,r);l=L-l;r=L-r;};
			l+=sh;r+=sh;
			printf("%d\n",Q(r-1)-Q(l-1));
		}
	}
	return 0;
}