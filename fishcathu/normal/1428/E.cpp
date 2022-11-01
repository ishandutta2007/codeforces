#include<cstdio>
typedef long long ll;
const int N=1E5+1;
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
int a[N],b[N],d[N],s;ll c[N];
void pop()
{
	d[1]=d[s--];
	for(int i=1;i<<1<=s;)
	{
		int son=i<<1!=s&&c[d[i<<1]]<c[d[i<<1|1]]?i<<1|1:i<<1;
		if(c[d[i]]<c[d[son]]){int t=d[i];d[i]=d[son],d[i=son]=t;}
		else return; 
	}
}
ll mon(int x,int n)
{
	int l=x/n,r=x%n;
	return l*1ll*l*(n-r)+(l+1)*1ll*(l+1)*r;
}
void cut(int x)
{	
	++b[d[++s]=x];
	c[x]=mon(a[x],b[x])-mon(a[x],b[x]+1);
	for(int i=s;c[d[i]]>c[d[i>>1]];i>>=1){int t=d[i];d[i]=d[i>>1],d[i>>1]=t;}
} 
int main()
{
	c[0]=0x7fffffffffffffff;
	int n=read(),m=read();
	ll ans=0;
	for(int i=1;i<=n;++i)a[i]=read(),cut(i),ans+=a[i]*1ll*a[i];
	for(int i=m-n;i--;)
	{
		int t=d[1];
		pop(),ans-=c[t],cut(t);
	}
	printf("%lld",ans);
	return 0;
}