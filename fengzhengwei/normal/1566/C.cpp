#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return*s++;}
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
char s[xx],c[xx];
int f[xx];
signed main(){
	int T=read();
	while(T--)
	{
		int n=read();
		scanf("%s",s+1);
		scanf("%s",c+1);
		memset(f,0,sizeof(f[0])*(n+1));
		f[0]=0;
		int t1=0,t0=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='1'||c[i]=='1')t1=i;
			if(s[i]=='0'||c[i]=='0')t0=i;
			if(t1&&t0)f[i]=f[min(t1,t0)-1]+2;
			if(t0)f[i]=max(f[i],f[t0-1]+1);
			f[i]=max(f[i],f[i-1]);
//			cout<<i<<" sss "<<f[i]<<"\n";
		}
		cout<<f[n]<<"\n";
	}
	return 0;
}