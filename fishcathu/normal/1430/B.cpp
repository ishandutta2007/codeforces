#include<cstdio>
#include<cstring>
#include<algorithm>
const int N=2E5+10;
int read()
{
    int a=0;char b=1,c;
    do if((c=getchar())==45)b=-1;while(!(c&16));
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())&16);
    return a*b;
}
void write(int x)
{
    if(x<0)putchar('-'),x=-x;
    char a[10],s=0;
    do a[s++]=x%10|48;while(x/=10);
    do putchar(a[--s]);while(s);
}
int a[N];
int main()
{
    for(int x=read();x--;)
	{
		int n=read(),m=read();
		long long sum=0;
		for(int i=0;i<n;++i)a[i]=read();
		std::sort(a,a+n);
		for(int i=1;i<=m+1;++i)sum+=a[n-i];
		printf("%lld\n",sum);
	}
}