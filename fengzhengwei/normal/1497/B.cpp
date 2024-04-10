#include<bits/stdc++.h>
using namespace std;
char gc()
{
	static char buf[1<<16],*S,*T;
	if(S==T)
	{
		T=(S=buf)+fread(buf,1,1<<16,stdin);
		if(S==T)return EOF;
	}
	return *S++;
}
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
int n,m;
const int xx=1e5+5;
int t[xx];
int main(){
//	freopen("a.in","r",stdin);
	int T=read();
	while(T--)
	{
		n=read();
		m=read();
		for(int i=0;i<=m;i++)t[i]=0;
		for(int i=1;i<=n;i++)t[read()%m]++;
		int sum=0;
		for(int i=0;i<=m;i++)
		{
			while(t[i])
			{
				sum++;
				int now;
				if(t[i]>=t[(m-i)%m])now=i;
				else now=(m-i)%m;
				while(t[now])
				{
					t[now]--;
					now=m-now;
					now%=m;
				}
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}