#include<bits/stdc++.h>
#define ll long long
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
#define getchar gc
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(op,0);
}
const int xx=1e6+5;
int n,a[xx],b[xx];
ll f[2][4];
int g(int i,int k){return (k&1)*a[i]+(k>>1&1)*b[i];}
signed main(){
	int T=read();
	while(T--)
	{
		n=read();
		ll sum=0;
		for(int i=1;i<=n;i++)b[i]=read(),sum+=b[i];
		for(int i=1;i<=n;i++)a[i]=read();
		//ab 
		//0a1b 
		ll mn=1e18;
		for(int w=1;w<4;w++)
		{
			memset(f,0x3f,sizeof(f));
			f[1][w]=g(1,w);
			for(int i=1;i<n;i++)
			{
				for(int k=1;k<4;k++)
				{
					if(f[i&1][k]>=1e18)continue;
					for(int s=1;s<4;s++)
					{
						if(k==2&&s==1)continue;
						f[(i+1)&1][s]=min(f[(i+1)&1][s],f[i&1][k]+g(i+1,s));
					}
					f[i&1][k]=1e18;
				}
			}
			for(int k=1;k<4;k++)
			{
				if(k==2&&w==1);
				else mn=min(mn,f[n&1][k]);
			}
		}
		if(sum==mn)puts("YES");
		else puts("NO");
	}
	pc('1',1);
	return 0;
}