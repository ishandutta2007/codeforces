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
		int n=read();
		puts("2");
		if(n==2){puts("1 2");continue;}
		printf("%d %d\n%d %d\n",n-2,n,n-1,n-1);
		for(int i=n-3;i;--i)printf("%d %d\n",i,i+2);
	}
}