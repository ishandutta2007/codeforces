#include<cstdio>
const int N=300;
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
int a[7];
int nc(int x){return (x+1)%6?(x+1)%6:6;}
int nt(int x){return (x+2)%6?(x+2)%6:6;}
int main()
{
	for(int x=read();x--;)
	{
		int m=read(),n=read();
		for(int i=1;i<=6;++i)a[i]=read();
		for(int i=1;i<=6;++i)if(a[i]+a[nt(i)]<a[nc(i)])a[nc(i)]=a[i]+a[nt(i)];
		if(m>=0&&n>=0)
		{
			if(m<n)printf("%lld\n",m*1ll*a[1]+(n-m)*1ll*a[2]);
			else printf("%lld\n",n*1ll*a[1]+(m-n)*1ll*a[6]);
		}
		else if(m<=0&&n<=0)
		{
			if(m<n)printf("%lld\n",-n*1ll*a[4]+(n-m)*1ll*a[3]);
			else printf("%lld\n",-m*1ll*a[4]+(m-n)*1ll*a[5]);
		}
		else if(m>=0&&n<=0)printf("%lld\n",m*1ll*a[6]-n*1ll*a[5]);
		else if(m<=0&&n>=0)printf("%lld\n",n*1ll*a[2]-m*1ll*a[3]);
	}
}