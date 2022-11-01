#include<cstdio>
#include<cstring>
const int N=1E5+10;
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
int main()
{
    for(int x=read();x--;)
	{
		int	n=read(),a=0,b=0,c=0;
		if(n%3==1)
		{
			if(n<7){puts("-1");continue;}
			else ++c,n-=7;
		}
		else if(n%3==2)
		{
			if(n<5){puts("-1");continue;}
			else ++b,n-=5;
		}
		a=n/3;
		printf("%d %d %d\n",a,b,c);
	}
}