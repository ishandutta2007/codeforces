#include<bits/stdc++.h>
#define ll long long
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;                                                                              
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int v[31];
int main(){
	int T=read();
	while(T--)
	{
		int n=read();
			for(int j=0;j<=30;j++)v[j]=0;
		for(int i=1;i<=n;i++)
		{
			int o=read();
			for(int j=0;j<=30;j++)
			{
				if(o>>j&1)
				v[j]++;
			}
		}
		for(int i=1;i<=n;i++)
		{
			int vs=1;
//			cout<<v[1]<<"!!!\n";
			for(int j=0;j<=30;j++)
			{
				if(v[j]%i!=0)
				{
					vs=0;
					break;
				}
			}
			if(vs)
			{
				cout<<i<<" ";
			}
		}
		puts("");
	}
	return 0;
}