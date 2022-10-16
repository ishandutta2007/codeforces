#include<bits/stdc++.h>
#define ll long long
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;                                                                              
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int main(){
	int t=read();
	while(t--)
	{
		int a=read(),b=read(),c=read();
		if(a>=10&&b>=10&&c>=10)
		{
			if((a+c)&1)
			{
				puts("1");
			}
			else 
			puts("0");
			continue;
		}
		int ans=1e9;
		for(int i=0;i<=a;i++)
		{
			for(int j=0;j<=b;j++)
			{
				for(int k=0;k<=c;k++)
				{
					ans=min(ans,abs(i+j+j+k+k+k-(a-i)-(b-j)*2-(c-k)*3));
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}