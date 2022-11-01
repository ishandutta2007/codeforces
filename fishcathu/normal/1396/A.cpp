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
long long a[N];
int main()
{
    int n=read();
    if(n==1)
    {
    	int t=read();
    	printf("1 1\n0\n1 1\n0\n1 1\n%d",-t);
    	return 0;
	}
    printf("%d %d\n",1,n-1);
    for(int i=1;i<=n;++i)
    {
    	a[i]=read();
    	if(i!=n)printf("%lld ",a[i]*(n-1)),a[i]+=a[i]*(n-1);
	}
	printf("\n%d %d\n%lld\n%d %d\n",n,n,-a[n],1,n);
	a[n]=0;
	for(int i=1;i<=n;++i)printf("%lld ",-a[i]);
	return 0;
}