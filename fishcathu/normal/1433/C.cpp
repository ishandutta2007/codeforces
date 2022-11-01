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
	for(int x=read();x--;)
	{
		int n=read(),ans,mx=0,k=0;
		for(int i=1;i<=n;++i)
		{
			a[i]=read();
			if(a[i]>mx)mx=a[i];
			if(a[i]!=a[1])k=1;
		}	
		if(k==0)
		{
			puts("-1");
			continue;
		}
		int i=1;
		for(;i<=n;++i)if(a[i]==mx&&(i>1&&a[i]>a[i-1]||a[i]>a[i+1]))break;
		printf("%d\n",i);
	} 
}