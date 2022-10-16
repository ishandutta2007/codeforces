//A
#include<bits/stdc++.h>
#define ll long long
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
const int xx=1000006;
int a[xx];
int vis[xx],prim[xx];
void pre(int x)
{
	int cnt=0;
	for(int i=2;i<=x;i++)
	{
		if(!vis[i])
		{
			prim[++cnt]=i;
		}
		for(int j=1;j<=cnt;j++)
		{
			if(i*prim[j]>x)break;
			vis[i*prim[j]]=1;
			if(i%prim[j]==0)break;
		}
	}
}
signed main(){
	pre(1000000);
	int T=read();
	while(T--)
	{
		int n=read();
		int sum=0;
		for(int i=1;i<=n;i++)a[i]=read(),sum+=a[i];
		if(sum&1)
		{
			if(vis[sum])
			{
				cout<<n<<"\n";
				for(int i=1;i<=n;i++)cout<<i<<" ";
				puts("");
			}
			else 
			{
				cout<<n-1<<"\n";
				int op=0;
				for(int i=1;i<=n;i++)
				{
					if((a[i]&1)&&op==0)
					{
						op=1;continue;
					}
					cout<<i<<" ";
				}
				puts("");
			}
		}
		else 
		{
			
				cout<<n<<"\n";
				for(int i=1;i<=n;i++)cout<<i<<" ";
				puts("");
		}
	}
	return 0;
}