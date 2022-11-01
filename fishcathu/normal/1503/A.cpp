#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=2E5+10;
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
bool check(char *a)
{
	int s=0;
	for(int i=1;a[i];++i)
	{
		a[i]=='('?++s:--s;
		if(s<0)return 0;
	}
	return !s;
}
char a[N],b[N],c[N];
void solve()
{
	int n=read();
	scanf("%s",a+1);
	b[n+1]=c[n+1]=0;
	int s=n;
	for(int i=1;i<=n;++i)
	{
		if(a[i]==49)continue;
		--s;
		if(s&1)
		{
			b[i]='(';
			c[i]=')';
		}
		else 
		{
			b[i]=')';
			c[i]='(';
		}
	}
	s>>=1;
	for(int i=1;i<=n;++i)
	{
		if(a[i]==48)continue;
		if(s)
		{
			b[i]=c[i]='(';
			--s;
		}
		else b[i]=c[i]=')';
	}
	if(check(b)&&check(c))
	{
		puts("YES");
		puts(b+1);
		puts(c+1);
	}
	else puts("NO");
}
int main()
{
	for(int x=read();x--;)
	{
		solve();
	}
}