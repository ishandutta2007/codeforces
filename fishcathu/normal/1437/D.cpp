#include<cstdio>
#include<cstring>
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
		a[0]=0;
		int n=read(),l=read(),s=0;
		while(--n)
		{
			int t=read();
			if(t>l)++a[s];
			else a[++s]=1; 
			l=t;
		}
		int sum=1,ans=1;
		for(l=0;s-l>=sum;++ans)
		{
			int t=0;
			for(int i=sum;i--;++l)t+=a[l];
			sum=t;
		}
		printf("%d\n",ans);
	} 
}