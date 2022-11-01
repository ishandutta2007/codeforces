#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2E5+10;
ll read()
{
    ll a=0;
	char b=1,c;
    do if((c=getchar())==45)b=-1;while(c<48||c>57);
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())>47&&c<58);
    return a*b;
}
void write(ll x,char c)
{
    if(x<0)putchar('-'),x=-x;
    char a[20],s=0;
    do a[++s]=x%10|48;while(x/=10);
    do putchar(a[s]);while(--s);
    putchar(c);
}
bitset<N>b;
int p[N],s;
void begin()
{
	for(int i=2;i<N;++i)
	{
		if(!b[i])p[++s]=i;
		for(int j=1;j<=s&&i*p[j]<N;++j)
		{
			b[i*p[j]]=1;
			if(!(i%p[j]))break;
		}
	}
}
void solve()
{
	int n=read();
	int l=*lower_bound(p+1,p+1+s,n+1);
	int r=*lower_bound(p+1,p+1+s,n+l);
	write(l*r,'\n');
}
int main()
{
	begin();
	for(int x=read();x--;)
	{
		solve();
	}
}