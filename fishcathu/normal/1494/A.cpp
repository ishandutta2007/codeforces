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
const int N=55;
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
pii b[3];
bool check()
{
	scanf("%s",a+1);
	int n=strlen(a+1);
	for(int i=0;i<3;++i)
	{
		b[i].fi=0;
		b[i].se=i+65;
	}
	for(int i=1;i<=n;++i)++b[a[i]-65].fi;
	sort(b,b+3);
	if(b[0].fi+b[1].fi!=b[2].fi)return 0;
	if(a[1]==b[2].se)
	{
		for(int i=n,j=0;i>=1;--i)
		{
			a[i]==a[1]?--j:++j;
			if(j<0)return 0;
		}
	}
	else if(a[n]==b[2].se)
	{
		for(int i=1,j=0;i<=n;++i)
		{
			a[i]==a[n]?--j:++j;
			if(j<0)return 0;
		}
	}
	else return 0;
	return 1;
}
int main()
{
	for(int x=read();x--;)
	{
		puts(check()?"YES":"NO");
	}
}