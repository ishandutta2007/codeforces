#include<cstdio>
const int N=6000;
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
		int n=read(),l1=0,r1,l2=0,r2;
		for(int i=1;i<=n;++i)
		{
			a[i]=read();
			if(!l1)l1=a[i],r1=i;
			else if(!l2&&a[i]!=l1)l2=a[i],r2=i;
		}
		if(!l2)
		{
			puts("NO");
			continue;
		}
		puts("YES");
		printf("%d %d\n",r1,r2);
		for(int i=1;i<=n;++i)if(i!=r1&&i!=r2)
		{
			printf("%d %d\n",i,a[i]==l1?r2:r1);	
		} 
	} 
}