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
const int N=1010;
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
char a[N];
int s[123];
void solve()
{
	int n=read();
	for(int m=n;m--;)
	{
		scanf("%s",a+1);
		for(int i=1;a[i];++i)
		{
			++s[a[i]];
		}
	}
	bool b=1;
	for(int i=97;i<=122;++i)
	{
		if(s[i]%n)b=0;
		s[i]=0;
	}
	puts(b?"YES":"NO");
}
int main()
{
	for(int x=read();x--;)
	{
		solve();
	}
}