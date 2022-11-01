#include<cstdio>
#include<cstring>
const int N=10000,pp=1E9+7;
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
int p,q;
void work(int l,int r,int x)
{
	if(l==r)return;
	int m=(l+r)>>1;
	if(x>m)++p,work(m+1,r,x);
	else if(x==m)work(m+1,r,x);
	else ++q,work(l,m,x);	
} 
int f(int m,int n)
{
	int ans=1;
	for(int i=0;i<n;++i)ans=ans*1ll*(m-i)%pp;
	return ans;
}
int main()
{
	int n=read(),s=read();
	work(0,n,read());
	int ans=1;
	ans=ans*1ll*f(s-1,p)%pp;
	ans=ans*1ll*f(n-s,q)%pp;
	ans=ans*1ll*f(n-1-p-q,n-1-p-q)%pp;
	write(ans);
}