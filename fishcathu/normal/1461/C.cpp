#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1E6+10;
int read()
{
    int a=0;char b=1,c;
    do if((c=getchar())==45)b=-1;while(c<48||c>57);
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())>47&&c<58);
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
	for(int x=read();x--;)
	{
		int n=read(),m=read();
		for(int i=1;i<=n;++i)b[i]=0;
		for(int i=1;i<=n;++i)a[i]=read(),b[a[i]]=1;
		int y=n;
		while(y>=1&&a[y]==y)--y;
		long double ans=1;
		while(m--)
		{
			int r=read();
			long double k;
			scanf("%Lf",&k);
			if(r>=y)ans*=((long double)1.0-k);
		}
		if(y<2)
		{
			puts("1.000000000");
			continue;
		}
		printf("%.9Lf\n",1-ans);
	}
}