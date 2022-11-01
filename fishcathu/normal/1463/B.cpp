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
		int n=read();
		ll s1=0,s2=0;
		for(int i=1;i<=n;++i)
		{
			((i&1)?s1:s2)+=a[i]=read();
		}
		int k=s1>s2;
		for(int i=1;i<=n;++i)
		{
			printf("%d ",(i&1)==k?a[i]:1);
		}
		putchar('\n');
	}
}