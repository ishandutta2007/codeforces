#include<cstdio>
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
int pow[N];
int main()
{
	int n=read(),p=1E9+7,ans=0;
	pow[0]=1;
	for(int i=1;i<=n;++i)pow[i]=pow[i-1]*1ll*3%p;
	char c;
	while((c=getchar())<=32);
	for(int a[4]={0},b=0;n--;c=getchar())
	{
		if(c=='?')ans=(ans*1ll*3+b)%p,b=(b*1ll*3+a[0]*1ll*pow[a[3]]+a[3]*1ll*pow[a[3]-1])%p;
		else if(c=='b')b=(b+a[0]*1ll*pow[a[3]]+a[3]*1ll*pow[a[3]-1])%p;
		else if(c=='c')(ans+=b)%=p; 
		++a[c=='?'?3:c-97];
	}
	write(ans);
	return 0;
}