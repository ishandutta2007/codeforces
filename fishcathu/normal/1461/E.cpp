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
ll m,l,r,t,d,u;
bool vis[N];
bool sovle()
{
	m-=l;
	r-=l;
	l=0;
	if(u<=d)
	{
		if(m+u>r)
		{
			m-=d;
			--t;
		}
		return m>=(__int128)(d-u)*t;
	}
	while(1)
	{
		t-=m/d;
		m-=m/d*d;
		if(t<=0||vis[m])return 1;
		vis[m]=1;
		m+=u;
		if(m>r)return 0;
		m-=d;
		--t;
	}
}
int main()
{
	scanf("%lld%lld%lld%lld%lld%lld",&m,&l,&r,&t,&d,&u);
	puts(sovle()?"Yes":"No");
}