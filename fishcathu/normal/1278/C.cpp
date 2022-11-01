#include<cstdio>
#include<cstring>
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
int a[N],b[N],c[N>>1];
int main()
{
	for(int x=read();x--;)
	{
		int n=read(),ans=0;
		memset(a,0xc0,sizeof a),memset(b,0xc0,sizeof b),a[n]=b[n]=0;
		for(int i=1,s=n;i<=n;++i)a[read()==1?--s:++s]=i;
		for(int i=n;i;--i)c[i]=read();
		for(int i=1,s=n;i<=n;++i)b[c[i]==1?++s:--s]=i;
		for(int i=n<<1;i>=0;--i)if(a[i]+b[i]>ans)ans=a[i]+b[i];
		write(n*2-ans),putchar('\n');
	}
	return 0;
}