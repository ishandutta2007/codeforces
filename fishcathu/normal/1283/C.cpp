#include<cstdio>
#include<algorithm>
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
int a[N],c[N],d[N];bool b[N],e[N];
int main()
{
	int n=read(),s=0,k=0;
	for(int i=1;i<=n;++i)(a[i]=read())?b[a[i]]=1:c[s++]=i;
	for(int i=1,j=0;i<=n;++i)if(!b[i])d[j++]=i;
	for(int i=0;i<s;++i)if(!b[c[i]])
	{
		int t=std::lower_bound(d,d+s,c[i])-d-i;
		e[t<0?t+s:t]=1;
	}
	while(e[k])++k;
	for(int i=0;i<s;++i)a[c[i]]=d[(i+k)%s];
	for(int i=1;i<=n;++i)printf("%d ",a[i]);
	return 0;
}