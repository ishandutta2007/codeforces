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
int a[N];
int main()
{
 	for(int x=read();x--;)
 	{
 		ll n;
 		scanf("%lld",&n);
 		if(n&1)
 		{
 			puts("-1");
 			continue;
		}
		n>>=1;
		int s=0,ans=0;
		while(n)
		{
			if(n&1)
			{
				a[s]=1;
				ans+=s+1;
			}
			else a[s]=0;
			++s;
			n>>=1;
		}
		printf("%d\n",ans);
		for(int i=s-1;i>=0;--i)if(a[i])
		{
			printf("1 ");
			for(int j=i;j>=2;--j)printf("0 ");
			if(i)printf("1 ");
		}
		putchar('\n');
	}
}