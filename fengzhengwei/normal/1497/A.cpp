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
int n;
const int xx=105;
int a[xx];
int t[xx];
int main(){
//	freopen("a.in","r",stdin);
	int T=read();
	while(T--)
	{
		memset(a,0,sizeof(a));
		memset(t,0,sizeof(t));
		n=read();
		for(int i=1;i<=n;i++)a[i]=read(),t[a[i]]++;
		for(int i=0;i<=100;i++)if(t[i])cout<<i<<" ",t[i]--;
		for(int i=0;i<=100;i++)while(t[i])cout<<i<<" ",t[i]--;
		puts("");
	}
	return 0;
}