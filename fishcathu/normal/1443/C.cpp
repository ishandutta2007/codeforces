#include<cstdio>
#include<cstring> 
#include<algorithm>
const int N=2E5+10;
int read() 
{ 	
	int a; 
    scanf("%d",&a);
	return a; 
} 
void write(int x) 
{
    if(x<0)putchar('-'),x=-x; 
    char a[10],s=0; 
    do a[s++]=x%10|48;while(x/=10); 
    do putchar(a[--s]);while(s);
}
struct st
{
	int l,r;
	bool operator<(const st m)const
	{
		if(l==m.l)return r>m.r;
		return l<m.l;
	}
}a[N];
int main()
{
	for(int x=read();x--;)
	{
		int n=read();
		long long sum=0;
		for(int i=1;i<=n;++i)a[i].l=read();
		for(int i=1;i<=n;++i)sum+=a[i].r=read();
		std::sort(a+1,a+1+n);
		long long ans=sum;
		for(int i=1;i<=n;++i)
		{
			sum-=a[i].r;
			long long t=a[i].l>sum?a[i].l:sum;
			if(t<ans)ans=t;
		}
		printf("%lld\n",ans);
	} 
}