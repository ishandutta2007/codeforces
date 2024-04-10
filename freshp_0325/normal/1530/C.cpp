#include<bits/stdc++.h>
using namespace std;
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
int T,n,a[100005],b[100005],sum1[100005],sum2[100005];
int trans(int x){return x-x/4;}
bool check(int add)
{
	int st=n+add;
	int relax=trans(st);
	int waste=n+add-relax;
	int res1=add*100+sum1[n],res2=sum2[min(n,trans(st))];
	if(waste>=n)	res1-=(waste-n+1)*100;
	res1-=sum1[waste];
	return res1>=res2;
}
int main(){
	T=read();
	while(T-->0)
	{
		n=read();
		for(int i=1;i<=n;++i)	a[i]=read();
		for(int i=1;i<=n;++i)	b[i]=read();
		sort(a+1,a+1+n),sort(b+1,b+1+n,greater<int>());
		for(int i=1;i<=n;++i)	sum2[i]=sum2[i-1]+b[i];
		for(int i=1;i<=n;++i)	sum1[i]=sum1[i-1]+a[i];
		int l=0,r=200000,ans=200001;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(check(mid))	ans=mid,r=mid-1;
			else	l=mid+1;
		}
		write(ans),puts("");
	}
	return 0;
}