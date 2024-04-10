#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
char buf[1<<18],*p1=buf,*p2=buf;
#define getchar() (p1==p2 && (p2=(p1=buf)+fread(buf,1,1<<18,stdin),p1==p2)?EOF:*p1++)
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
LL n,m,K;
LL a[50005],b[50005];
void Solve()
{
	n=read(),m=read();
	for(LL i=1;i<=n;++i)	a[i]=read();
	K=read();
	for(LL i=1;i<=K;++i)	b[i]=read();
	vector<pair<LL,LL>> A,B;
	#define mp make_pair
	for(LL i=n;i;--i)	A.push_back(mp(a[i],1));
	for(LL i=K;i;--i)	B.push_back(mp(b[i],1));
	while(!A.empty() && !B.empty())
	{
		pair<LL,LL> aa=A.back(),bb=B.back();
		A.pop_back(),B.pop_back();
		while(aa.first%m==0)
		{
			aa.second*=m;
			aa.first/=m;
		}
		while(bb.first%m==0)
		{
			bb.second*=m;
			bb.first/=m;
		}
		if(aa.first^bb.first)
		{
			puts("No");
			return ;
		}
		LL c=min(aa.second,bb.second);
		aa.second-=c;
		bb.second-=c;
		if(aa.second)	A.push_back(aa);
		if(bb.second)	B.push_back(bb);
	}
	puts(A.empty() && B.empty()?"Yes":"No");
}
int main(){
	LL T=read();
	while(T-->0)Solve();
	return 0;
}