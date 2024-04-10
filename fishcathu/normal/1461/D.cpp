#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1E5+10;
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
ll sum[N];
set<ll>v;
void begin(int l,int r)
{
	v.insert(sum[r]-sum[l-1]);
	if(a[l]==a[r])return;
	int m=a[l]+a[r]>>1;
	int t=upper_bound(a+l,a+r+1,m)-a;
	begin(l,t-1);
	begin(t,r);
}
int main()
{
	for(int x=read();x--;)
	{
		v.clear();
		int n=read(),m=read();
		for(int i=1;i<=n;++i)a[i]=read();
		sort(a+1,a+1+n);
		for(int i=1;i<=n;++i)sum[i]=sum[i-1]+a[i];
		begin(1,n);
		while(m--)
		{
			int t=read();
			puts(v.count(t)?"Yes":"No");
		}
	}
}