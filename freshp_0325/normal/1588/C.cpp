#include<bits/stdc++.h>
using namespace std;
char buf[1<<21],*p1=buf,*p2=buf;
#define getchar() (p1==p2 && (p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
typedef long long LL;
LL read()
{
	LL x=0,f=1;
	char c=getchar();
	while(c<'0' || c>'9')
	{
		if(c=='-')	f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9')	x=(x<<1)+(x<<3)+(c^'0'),c=getchar();
	return x*f;
}
void write(LL x)
{
	if(x>9)	write(x/10);
	putchar(x%10+'0');
}
typedef pair<LL,LL> P;
#define mp make_pair
LL n,a[300005];
void Solve()
{
	n=read();
	for(LL i=1;i<=n;++i)	a[i]=read();
	map<LL,LL> M;
	LL ans=0,dce=0;
	for(LL i=1;i<=n;++i)
	{
		if(i&1)
		{
			dce+=a[i];
			++M[a[i]-dce];
			while(!M.empty())
			{
				auto it=M.begin();
				if((*it).first+dce<0)	M.erase(M.begin());
				else	break;
			}
		}
		else
		{
			dce-=a[i];
			++M[-a[i]-dce];
			while(!M.empty())
			{
				auto it=prev(M.end());
				if((*it).first+dce>0)	M.erase(prev(M.end()));
				else	break;
			}
		}
		ans+=M[-dce];
	}
	write(ans),puts("");
}
int main(){
	LL T=read();
	while(T-->0)	Solve();
	return 0;
}