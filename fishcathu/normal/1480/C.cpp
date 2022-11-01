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
int ask(int x)
{
	printf("? ");
	write(x,'\n');
	fflush(stdout);
	return read();
}
int main()
{
	int n=read();
	int l=1;
	for(int r=n;l!=r;)
	{
		int m=l+r>>1;
		int u=ask(m),v=ask(m+1);
		u<v?r=m:l=m+1;
	}
	printf("! ");
	write(l,'\n');
}