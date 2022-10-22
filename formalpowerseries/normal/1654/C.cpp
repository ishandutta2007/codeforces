/*

DONT NEVER AROUND . //
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
char buf[1<<21],*p1=buf,*p2=buf;
#define getchar() (p1==p2 && (p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
LL read()
{
	LL x=0;
	char c=getchar();
	while(c<'0' || c>'9')	c=getchar();
	while(c>='0' && c<='9')	x=(x<<1)+(x<<3)+(c^'0'),c=getchar();
	return x;
}
void write(LL x)
{
	if(x>9)	write(x/10);
	putchar(x%10+'0');
}
map<LL,LL> M;
LL n,a[200005];
bool dfs(LL s)
{
	if(M[s])
	{
		--M[s];
		return true;
	}
	if(s==1)	return false;
	return dfs(s-s/2) && dfs(s/2);
}
void Solve()
{
	M.clear();
	n=read();
	LL sum=0;
	for(LL i=1;i<=n;++i)	++M[a[i]=read()],sum+=a[i];
	puts(dfs(sum)?"yes":"NO");
}
int main(){
	LL T=read();
	while(T-->0)	Solve();
	return 0;
}