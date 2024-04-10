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
const int N=1E4+10;
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
const int p=1E4;
ll a[N];
bool check()
{
	ll n=read();
	for(int i=1;i<p;++i)
	{
		ll t=n-a[i];
		if(*lower_bound(a+1,a+p,t)==t)return 1;
	}
	return 0;
}
int main()
{
	for(int i=1;i<p;++i)a[i]=i*1ll*i*i;
	for(int x=read();x--;)
	{
		puts(check()?"YES":"NO");
	}
}