#include<cstdio>
#include<algorithm>
const int N=2010; 
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
int a[N],b[N]; 
int main()
{
    int n=read(),p=read(),ans=p;
    for(int i=0;i<n;++i)a[i]=read();
    for(int i=0;i<n;++i)b[i]=read();
    std::sort(a,a+n),std::sort(b,b+n);
    for(int k=0;k<n;++k)
    {
        int t=b[k]-a[0]<0?b[k]-a[0]+p:b[k]-a[0],i=1;
        while(i<n&&(b[(i+k)%n]-a[i]<0?b[(i+k)%n]-a[i]+p:b[(i+k)%n]-a[i])==t)++i;
        if(i>=n&&t<ans)ans=t;
    }
    write(ans);
    return 0;
}