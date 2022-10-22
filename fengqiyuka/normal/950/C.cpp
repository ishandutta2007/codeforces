#include<cstdio>
#include<cstring>
using namespace std;
struct printans{
	int l,r;
}ans[210000];int anslen[210000];
char s[210000];int a[210000],f[210000];
int b[210000],c[210000];bool bk[210000];
int main()
{
	scanf("%s",s+1);int len=strlen(s+1);
	int sum1=0;
	for(int i=1;i<=len;i++) sum1+=(s[i]=='1');
	for(int i=1;i<=len;i++) a[i]=s[i]-'0';
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	int id=1,sum=0;
	for(int i=1;i<=len;i++)
	{
		if(a[i]==0)
		{
			id++;
			while((id<=i||a[id]==0)&&id<=len) id++;
			if(id<=len) sum++,b[i]=id;
			else break;
		}
	}
	if(sum!=sum1)
	{
		printf("-1\n");
		return 0;
	}
	id=1;sum=0;
	for(int i=1;i<=len;i++)
	{
		if(a[i]==1)
		{
			id++;
			while((id<=i||a[id]==1)&&id<=len) id++;
			if(id<=len) sum++,c[i]=id;
			else break;
		}
	}
	if(sum!=sum1)
	{
		printf("-1\n");
		return 0;
	}
	for(int i=1;i<=len;i++)
	{
		if(b[i]==0) b[i]=i;
	}
	int anssum=0;anslen[0]=0;
	memset(bk,true,sizeof(bk));
	for(int i=1;i<=len;i++)
	{
		if(bk[i]==true)
		{
			ans[++anssum].l=anslen[0]+1;
			anslen[++anslen[0]]=i;
			int temp=i;bk[i]=false;
			while(b[temp]!=temp)
			{
				int t=b[temp];
				anslen[++anslen[0]]=t;
				anslen[++anslen[0]]=c[t];
				temp=c[t];bk[t]=bk[temp]=false;
			}
			ans[anssum].r=anslen[0];
		}
	}
	printf("%d\n",anssum);
	for(int i=1;i<=anssum;i++)
	{
		printf("%d ",ans[i].r-ans[i].l+1);
		for(int j=ans[i].l;j<ans[i].r;j++)
		{
			printf("%d ",anslen[j]);
		}
		printf("%d\n",anslen[ans[i].r]);
	}
	return 0;
}