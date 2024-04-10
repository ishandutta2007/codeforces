#include<cstdio>
#include<algorithm>
const int N=5E5+10;
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
int a[N],b[N],v[N];
int main()
{
    int n=read(),m=read(),ans=0;
    for(int i=1;i<=n;++i)a[i]=read()-i;
    for(int i=1;i<=m;++i)b[i]=read();
    a[0]=v[0]=-2E9,a[n+1]=2E9,b[m+1]=n+1;
    for(int i=0;i<=m;++i)
    {
        if(a[b[i+1]]<a[b[i]]){puts("-1");return 0;}
        int s=0;
        for(int j=b[i]+1;j<b[i+1];++j)if(a[j]>=a[b[i]]&&a[b[i+1]]>=a[j])
        {
            if(a[j]>=v[s])v[++s]=a[j];
            else *std::upper_bound(v+1,v+1+s,a[j])=a[j];
        }
        ans+=b[i+1]-b[i]-1-s;
    }
    write(ans);
    return 0;
}