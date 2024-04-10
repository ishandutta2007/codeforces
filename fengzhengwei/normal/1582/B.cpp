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
	int T=read();
	while(T--)
	{
		int n=read();
		int tt=0,tt1=0;
		for(int i=1;i<=n;i++)
		{
			int a=read();
			tt1+=(a==1);
			tt+=(a==0);
		}
		if(!tt1)
		{
			puts("0");
			continue;
		}
//		cout<<tt<<" "<<tt1<<"\n";
		ll ans=1;
		while(tt--)
		{
			ans*=2;
		}
		cout<<ans*tt1<<"\n";
	}
	return 0;
}