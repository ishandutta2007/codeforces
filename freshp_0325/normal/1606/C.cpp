#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
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
int n,k,a[15],pw[15];
void Solve()
{
	n=read(),k=read()+1;
	for(int i=1;i<=n;++i)	a[i]=read();
	for(int i=1;i<=n;++i)
	{
		if(i==n)
		{
			write(k);
			for(int j=0;j<a[i];++j)	putchar('9');
			puts("");
			return ;
		}
		int st=pw[a[i+1]-a[i]]-1;
		if(k<=st)
		{
			write(k);
			for(int j=0;j<a[i];++j)	putchar('9');
			puts("");
			return ;
		}
		k-=st;
	}
}
int main(){
	int T=read();
	pw[0]=1;
	pw[1]=10;
	pw[2]=100;
	pw[3]=1000;
	pw[4]=10000;
	pw[5]=100000;
	pw[6]=1000000;
	pw[7]=10000000;
	pw[8]=100000000;
	pw[9]=1000000000;
	while(T-->0)	Solve();
	return 0;
}