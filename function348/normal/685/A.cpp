#include<cstdio>
#include<iostream>
using namespace std;
typedef long long LL;
int n,m,t,k1,k2;
int a[100],b[100],c[100],v[100];
LL ans;
void chk(int n)
{
//	for (int i=1;i<=n;i++) printf("%d ",c[i]);printf("\n");

	int d=7,cn=0;
	for (int i=0;i<=9;i++) v[i]=0;
	for (int i=1;i<=n;i++)
	if (c[i]==-1) cn++;
	else if (v[c[i]]==0) v[c[i]]=1,d--;
	else return;
	if (cn>d) return;
	LL res=1;
	for (int i=d;i>=d-cn+1;i--) res=1LL*res*i;
	ans+=res;
}
int main()
{
	scanf("%d%d",&n,&m);
	n--,m--;
	t=n;while (t) a[++k1]=t%7,t/=7;
	t=m;while (t) b[++k2]=t%7,t/=7;
	if (n==0) k1++;
	if (m==0) k2++;
	a[1]++,b[1]++;
	for (int i=1;i<=k1;i++)
	{
		for (int j=k1;j>i;j--) c[j]=a[j];
		for (int j=1;j<i;j++) c[j]=-1;
		for (int j=0;j<a[i];j++) 
		{
			c[i]=j;
			for (int ii=1;ii<=k2;ii++)
			{
				for (int jj=1;jj<ii;jj++) c[jj+k1]=-1;
				for (int jj=k2;jj>ii;jj--) c[jj+k1]=b[jj];
				for (int jj=0;jj<b[ii];jj++)
				{
					c[ii+k1]=jj;
					chk(k1+k2);
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}