#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=1E5+10;
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
int a[N][2],b[N],c[N];
void solve()
{
	int n=read(),m=read();
	memset(c+1,0,n<<2);
	for(int i=1;i<=m;++i)
	{
		b[i]=read();
		++c[a[i][0]=read()];
		if(b[i]!=1)
		{
			++c[a[i][1]=read()];
			for(int j=b[i]-2;j--;)
			{
				read();
			}
			b[i]=2;
		}
	}
	int w=max_element(c+1,c+1+n)-c;
	c[w]-=m+1>>1;
	int i=1;
	while(i<=m&&c[w]>0)
	{
		if(b[i]!=1)
		{	
			if(a[i][0]==w)
			{
				a[i][0]=a[i][1];
				--c[w];
			}
			else if(a[i][1]==w)
			{
				--c[w];
			}
		}
		++i;
	}
	if(c[w]>0)puts("NO");
	else
	{
		while(i<=m)
		{
			if(b[i]!=1)
			{
				if(a[i][1]==w)
				{
					a[i][0]=w;
				}
			}
			++i;
		}
		puts("YES");
		for(i=1;i<=m;++i)
		{
			write(a[i][0],' ');
		}
		putchar('\n');
	}
}
int main()
{
	for(int x=read();x--;)
	{
		solve();
	}
}