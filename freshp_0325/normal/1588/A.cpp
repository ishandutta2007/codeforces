#include<bits/stdc++.h>
using namespace std;
char buf[1<<21],*p1=buf,*p2=buf;
#define getchar() (p1==p2 && (p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0' || c>'9')
	{
		if(c=='-')	f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9')	x=(x<<1)+(x<<3)+(c^'0'),c=getchar();
	return x*f;
}
void write(int x)
{
	if(x>9)	write(x/10);
	putchar(x%10+'0');
}
unordered_map<int,int> M;
int n,a[105],b[105];
void Solve()
{
	n=read();
	M.clear();
	for(int i=1;i<=n;++i)	a[i]=read();
	for(int i=1;i<=n;++i)	b[i]=read();
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	for(int i=1;i<=n;++i)	if(a[i]+1!=b[i] && a[i]!=b[i])	{puts("NO");return ;}
	puts("YES");
}
int main(){
	int T=read();
	while(T-->0)	Solve();
	return 0;
}