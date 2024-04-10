#include<bits/stdc++.h>
using namespace std;
char buf[1<<21],*p1=buf,*p2=buf;
#define getchar() (p1==p2 && (p2=(p1=buf)+fread(buf,1,1<<18,stdin),p1==p2)?EOF:*p1++)
typedef long long LL;
typedef pair<int,int> P;
#define mp make_pair
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
int n,a[200005];
bool used[200005];
void Solve()
{
	n=read();
	for(int i=1;i<=n;++i)	a[i]=read();
	for(int i=1;i<=n;++i)	used[i]=false;
	int pos=1;
	for(int i=1;i<=n;++i)
	{
		if(a[i]!=a[i-1])	write(a[i]),used[a[i]]=true;
		else	write(pos),used[pos]=true;
		putchar(i==n?'\n':' ');
		while(used[pos])	++pos;
	}
	set<int,greater<int>> S;
	for(int i=1;i<=n;++i)	S.insert(i);
	for(int i=1;i<=n;++i)
	{
		if(a[i]!=a[i-1])	write(a[i]),S.erase(a[i]);
		else
		{
			auto st=S.upper_bound(a[i]);
			write(*st),S.erase(st);
		}
		putchar(i==n?'\n':' ');
	}
}
int main(){
	int T=read();
	while(T-->0)	Solve();
	return 0;
}