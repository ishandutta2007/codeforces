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
const int xx=1e5+5;
char s[xx];
ll sum[xx+xx];
int cr[xx][2];
int main(){
	int T=read();
	while(T--)
	{
		int n=read();
		for(int i=1;i<=n;i++)sum[i]=sum[i-1]+read();
		for(int i=1;i<=n;i++)cr[i][1]=1;
		for(int ans=2;;ans++)
		{
			for(int j=1;j<=n;j++)cr[j][ans&1]=0;
			ll smx=-1e18;
			int vs=0;
			for(int j=n-ans+1;j>=1;j--)
			{
				if(sum[j+ans-1]-sum[j-1]<smx)cr[j][ans&1]=1,vs=1;
				if(cr[j+ans-1][!(ans&1)])
				{
					smx=max(smx,sum[j+ans-1+ans-1-1]-sum[j+ans-2]);
				}
			}
			if(!vs)
			{
				cout<<ans-1<<"\n";
				break;
			}
		}
	}
	return 0;
}