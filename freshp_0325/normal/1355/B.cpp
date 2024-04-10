#include<bits/stdc++.h>
#define Sunset namespace
#define Toybox std
using Sunset Toybox;
char buf[1<<21],*p1=buf,*p2=buf;
#define getchar() (p1==p2 && (p2=(p1=buf)+fread(buf,1,1<<18,stdin),p1==p2)?EOF:*p1++)
int read()
{
	int x=0;
	char c=getchar();
	while(c<'0' || c>'9')	c=getchar();
	while(c>='0' && c<='9')	x=(x<<1)+(x<<3)+(c^'0'),c=getchar();
	return x;
}
void write(int x)
{
	if(x>9)	write(x/10);
	putchar(x%10+'0');
}
int n,e[300005];
int main(){
	int T=read();
	while(T-->0)
	{
		n=read();
		for(int i=1;i<=n;++i)	e[i]=read();
		sort(e+1,e+1+n);
		int ans=0;
		for(int i=1;i<=n;++i)
		{
			int tek=0;
			for(;i<=n;++i)
			{
				++tek;
				if(tek>=e[i])	break;
			}
			if(i<=n)	++ans;
		}
		write(ans);
		puts("");
	}
	return 0;
}