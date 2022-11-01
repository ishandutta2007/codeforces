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
    char a[20],s=0;
    while(x)a[s++]=x&1|48,x>>=1;
    while(s)putchar(a[--s]);
    putchar('\n'); 
}
char a[N];
bitset<1<<20>b;
int main()
{
	for(int x=read();x--;)
	{
		int n=read(),m=read();
		int k=min(__lg(n-m+1)+1,m);
		scanf("%s",a+1);
		for(int i=1;i<=n;++i)a[i]=a[i]&1^1;
		int p=0,q=0,s=(1<<k)-1;
		for(int i=0;i<=s;++i)b[i]=0;
		for(int i=m-k;i>=1;--i)p+=a[i];
		for(int i=0;i<k;++i)if(a[m-i])q+=1<<i;
		for(int i=m;i<=n;++i)
		{
			if(!p)b[q]=1;
			p+=a[i-k+1]-a[i-m+1];
			q=(q<<1|a[i+1])&s;
		}
		int i=0;
		while(i<=s&&b[i])++i;
		if(i>s)
		{
			puts("NO");
			continue;
		}
		puts("YES");
		for(int j=m-__lg(i);--j;)putchar('0');
		write(i);
	}
}