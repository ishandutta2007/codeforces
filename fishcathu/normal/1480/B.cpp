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
int l[N],r[N];
int f(int u,int v)
{
	bool t=u%v;
	return u/v+t;
}
bool check()
{
	int a=read();
	ll b=read();
	int n=read(),x=0;
	for(int i=1;i<=n;++i)
	{
		l[i]=read();
		if(l[i]>l[x])x=i;
	}
	for(int i=1;i<=n;++i)
	{
		r[i]=read();
		if(i!=x)b-=f(r[i],a)*1ll*l[i];
	}
	return b>0&&f(b,l[x])*1ll*a>=r[x];
}
int main()
{
	for(int x=read();x--;)
	{
		puts(check()?"YES":"NO");
	}
}