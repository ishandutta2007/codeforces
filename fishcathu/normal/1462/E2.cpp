#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2E5+1;
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
int a[N],u[N],d[N],p=1E9+7;
int main()
{
	u[0]=d[0]=u[1]=d[1]=1;
	for(int i=2;i<N;++i)
	{
		u[i]=u[i-1]*1ll*i%p;
		d[i]=(p-p/i)*1ll*d[p%i]%p;
	}
	for(int i=2;i<N;++i)d[i]=d[i]*1ll*d[i-1]%p;
	for(int x=read();x--;)
	{
		int n=read(),m=read()-1,k=read(),ans=0;
		for(int i=1;i<=n;++i)a[i]=read();
		sort(a+1,a+1+n);
		for(int i=1,l=1;i<=n;++i)
		{
			while(a[i]-a[l]>k)++l;
			if(i-l>=m)ans=(ans+u[i-l]*1ll*d[m]%p*d[i-l-m])%p;
		}
		write(ans);
		putchar('\n');
	}
}