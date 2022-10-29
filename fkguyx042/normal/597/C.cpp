#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>

#define N 100005
#define K 11
using namespace std;
unsigned long long tree[K][N];
unsigned long long i,j,m,n,p,k,ans;
unsigned long long lowbit(unsigned long long x) { return x&-x; }
void update(unsigned long long k,unsigned long long x,unsigned long long y)
{	 
  for (;x<=n;x+=lowbit(x)) tree[k][x]+=y;
}
unsigned long long ask(unsigned long long k,unsigned long long x)
{
	 unsigned long long sum=0;
	 for (;x;x-=lowbit(x)) sum+=tree[k][x];
	 return sum;
}
int main()
{
	scanf("%d%d",&n,&k); ++k;
	update(0,1,1);
	for (i=1;i<=n;++i)
{
	 int x;
	 scanf("%d",&x);
	 ans+=ask(k-1,x);
	 for (j=k-1;j;--j) update(j,x,ask(j-1,x));
}
cout<<ans<<endl;
}