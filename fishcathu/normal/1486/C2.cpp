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
int ask(int l,int r)
{
	if(l==r)return 0;
	printf("? ");
	write(l,' ');
	write(r,'\n');
	fflush(stdout);
	return read();
}
int f(int l,int r,int x)
{
	while(l!=r)
	{
		int m=l+r+2>>1;
		ask(m,x)==x?l=m:r=m-1;
	}
	return l;
}
int g(int l,int r,int x)
{
	while(l!=r)
	{
		int m=l+r>>1;
		ask(x,m)==x?r=m:l=m+1;
	}
	return l;
}
int main()
{
	int n=read();
	int x=ask(1,n);
	int ans=ask(1,x)==x?f(1,x-1,x):g(x+1,n,x);
	printf("! ");
	write(ans,'\n');
}