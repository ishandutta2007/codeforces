#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int c[110],s[1100000];bool bk[1100000];
void fen(int x)
{
	int t=sqrt(x);
	for(int i=2;i<=t;i++)
	{
		if(x%i==0)
		{
			c[++c[0]]=i;
			while(x%i==0) x/=i;
		}
	}
	if(x!=1) c[++c[0]]=x;
}
int main()
{
	int n;scanf("%d",&n);c[0]=0;fen(n);
	memset(bk,true,sizeof(bk));bk[1]=false;
	for(int i=2;i<=n;i++)
	{
		if(bk[i]==true)
		{
			for(int j=i;j<=n/i;j++) bk[i*j]=false;
		}
	}
	s[0]=0;
	for(int i=2;i<=n;i++) if(bk[i]==true) s[++s[0]]=i;
	int ans=999999999;
	for(int i=1;i<=c[0];i++)
	{
		for(int j=1;j<=s[0];j++)
		{
			int l=n-c[i],r=n;
			if(l/s[j]!=r/s[j]&&bk[r/s[j]*s[j]]==false)
			{
				int temp=(l/s[j]+1)*s[j]-s[j]+1;
				if(ans>temp) ans=temp;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}