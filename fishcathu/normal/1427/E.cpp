#include<cstdio>
#include<cstring>
#define int long long 
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
int a[N],b[N],s;char c[N];
int gcd(int d,int e,int &f,int &g)
{
    if(d%e){int ans=gcd(e,d%e,g,f);return g-=d/e*f,ans;}
    else return f=0,g=1,e;
}
void add(int &l,char m,int r)
{
    a[++s]=l,c[s]=m,b[s]=r;
    if(m=='+')l+=r;
}
void mul(int x,int n)
{
    for(int t=0;n;n>>=1,add(x,'+',x))if(n&1)add(t,'+',x);
}
void work(int x)
{
    if(x==1)return;
    int t=x,z=x;
    do add(t,'+',t);while(!(t&x));
    add(t,'^',x),t^=x;
    int l,r,m=gcd(x,t,l,r);
    l<=0?l=-l:r=-r,mul(x,l),mul(t,r),x*=l,t*=r;
    while((x^t)>=z)add(x,'+',z),add(t,'+',z);
    add(x,'^',t),x^=t;
    work(x);
}
signed main()
{
    int x=read();   
    add(x,'^',x);
    work(x);
    write(s),putchar('\n');
    for(int i=1;i<=s;++i)printf("%lld %c %lld\n",a[i],c[i],b[i]);
}