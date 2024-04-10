#include<cstdio>
const int N=3E5+10; 
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
	int n=read(),s=0;
	long long sum=0;
	for(int i=n;i--;)sum+=a[i]=read();
	for(int i=0,k=0;i<n;++i)
	{
		if(a[i]&1)
		{
			k?--s:++s;
			k=!k;
		}
		else if(s)k=!k;
	}
	printf("%lld",sum-s>>1);
	return 0;
}