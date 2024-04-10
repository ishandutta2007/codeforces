#include<bits/stdc++.h>
#define int long long
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n,m;
signed main(){
	n=read();
	for(int i=1;i<=n;i++)
	{
		int a;
		a=read();
		int cnt=0;
		int cww=1;
		int b=0;
		int c=-1;
		int ooo=0;
		int fir=0;
		for(int i=1;i<=a;i++)
		{
			b=read();
			if(i==1)fir=b;
			if(b==c)cnt=1,ooo=i-1;
			if(b!=c&&i!=1)cww=0;
			c=b;
		}
		if(b==fir)
		cnt=1,ooo=-2;
		if(cww)
		{
			printf("1\n");
			for(int i=1;i<a;i++)
			{
				printf("1 ");
			}
			printf("1\n");
			continue;
		}
		if(a%2==0)
		{
			printf("2\n");
			int q=1;
			for(int i=1;i<a;i++)
			{
				printf("%d ",q);
				q=3-q;
			}
			printf("2\n");
			continue;
		}
		if(cnt)
		{
			if(ooo==-2)
			{
				printf("2\n");
			int q=1;
			for(int i=1;i<a;i++)
			{
				printf("%d ",q);
				q=3-q;
			}
			printf("1\n");
			}
			else 
			{
				printf("2\n");
			int q=1;
			for(int i=1;i<a;i++)
			{
				printf("%d ",q);
				q=3-q;
				if(ooo==i)q=3-q;
			}
			printf("2\n");
			}
			continue;
		}
		printf("3\n");
			int q=1;
			for(int i=1;i<a;i++)
			{
				printf("%d ",q);
				q=3-q;
			}
			printf("3\n");
	}
	return 0;
}