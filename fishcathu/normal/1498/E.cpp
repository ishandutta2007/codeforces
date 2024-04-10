#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=510;
const int inf=1<<30;
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
pii a[N];
struct st
{
	int l,r,val;
	bool operator<(const st m)const
	{
		return val>m.val;
	}
}b[N*N];
bool ask(int l,int r)
{
	printf("? ");
	write(l,' ');
	write(r,'\n');
	fflush(stdout);
	char c[5];
	scanf("%s",c);
	return c[0]=='Y';
}
int main()
{
	int n=read();
	for(int i=1;i<=n;++i)
	{
		a[i].fi=read();
		a[i].se=i;
	}
	sort(a+1,a+1+n);
	int s=0;
	for(int i=1;i<=n;++i)
	{
		for(int j=i+1;j<=n;++j)
		{
			b[++s]={a[j].se,a[i].se,a[j].fi-a[i].fi};
		}
	}
	sort(b+1,b+1+s);
	for(int i=1;i<=s;++i)
	{
		if(ask(b[i].l,b[i].r))
		{
			printf("! ");
			write(b[i].l,' ');
			write(b[i].r,'\n');
			return 0;
		}
	}
	puts("! 0 0");
}