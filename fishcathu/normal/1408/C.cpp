#include<cstdio>
#include<cstring>
using namespace std;
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
int a[N];double b[N],c[N];
int main()
{
    for(int x=read();x--;)
    {
    	int n=read(),j=n+1;
    	a[n+1]=read(),c[j]=0;
    	for(int i=1;i<=n;++i)a[i]=read();
    	for(int i=1;i<=n+1;++i)b[i]=b[i-1]+((a[i]-a[i-1])*1.0/i);
    	while(c[j]<b[j])c[j-1]=c[j]+((a[j]-a[j-1])*1.0/(n-j+2)),--j;
    	printf("%.6f\n",(a[j+1]-a[j]+b[j]*(j+1)+c[j+1]*(n-j+1))/(n+2));
	}
	return 0;
}