#include<cstdio>
#include<algorithm>
const int N=2001;
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
struct st
{
	int l,r;
	bool operator<(const st m)const{return l>m.l;}
}b[4000001]; 
int a[N][2];
int main()
{
	int n=read(),m=read(),cnt=0,ans=1<<30;
	for(int i=1;i<=n;++i)a[i][0]=read(),a[i][1]=read();
	for(int i=1;i<=m;++i)
	{
		int l=read(),r=read();
		for(int j=1;j<=n;++j)b[++cnt].l=a[j][0]<=l?l-a[j][0]+1:0,b[cnt].r=a[j][1]<=r?r-a[j][1]+1:0;
	}
	std::sort(b+1,b+1+cnt);
	for(int i=1,max=0;i<=cnt+1;++i)
	{
		if(b[i].l+max<ans)ans=b[i].l+max;
		if(b[i].r>max)max=b[i].r;
	}
	write(ans);
	return 0;
}