#include<cstdio>
#include<algorithm>
typedef long long ll;
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
int a[N],ny[N>>1]; 
int main()
{
    int n=read(),m=n<<1,ans=0,p=998244353;
    for(int i=1;i<=m;++i)a[i]=read();
    std::sort(a+1,a+1+m);
    for(int i=1;i<=n;++i)ans=(ans*1ll-a[i]+a[i+n])%p;
    ny[1]=1;
    for(int i=2;i<=n;++i)ny[i]=(p-p/i)*1ll*ny[p%i]%p;
    for(int i=1;i<=n;++i)ans=ans*1ll*(m+1-i)%p*ny[i]%p;
    write(ans);
    return 0;
}