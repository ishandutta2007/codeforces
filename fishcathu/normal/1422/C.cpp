#include<cstdio>
const int N=1E5+2,p=1E9+7;
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
char a[N];int b[N],c[N];
int main()
{
    int n=0,ans=0;
    while((a[++n]=getchar())&16)a[n]&=15;
    --n;
    for(int i=1;i<n;++i)b[i]=(b[i-1]*10ll+a[i])%p;
    for(int i=n,j=1;i>=1;--i,j=j*10ll%p)c[i]=(a[i]*1ll*j+c[i+1])%p;
    for(int i=n,j=1;--i;j=(j*10ll+1)%p)ans=(ans+b[i]*1ll*j+i*1ll*c[i+1])%p;
    write(ans);
    return 0;
}