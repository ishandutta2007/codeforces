#include<cstdio>
typedef long long ll;
const int N=25;
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
ll a[N];
int main()
{
	for(int i=2;i<=20;i+=2)
	{
		a[i]=1;
		for(int j=1;j<<1<=i;++j)a[i]=a[i]*(i-j+1)/j;
		a[i]>>=1;
	}
	int n=read();
	ll ans=a[n],k=1;
	for(int i=n>>1;--i;)k*=i;
	printf("%lld",k*k*ans);
}