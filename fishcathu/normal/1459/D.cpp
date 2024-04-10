#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=101;
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
int f[N][10001];
int main()
{
	int n=read(),s=0;
	memset(f,-128,sizeof f);
	f[0][0]=0;
	for(int i=1;i<=n;++i)
	{
		int l=read()<<1,r=read();
		s+=r;
		for(int j=i;j>=1;--j)for(int k=r;k<=s;++k)
		{
			f[j][k]=max(f[j][k],f[j-1][k-r]+l);
		}
	}
	for(int i=1;i<=n;++i)
	{
		int ans=0;
		for(int j=0;j<=s;++j)ans=max(ans,min(j+s,f[i][j]));
		write(ans>>1);
		if(ans&1)putchar('.'),putchar('5');
		putchar(' '); 
	}
}