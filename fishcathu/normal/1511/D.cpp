#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=700;
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
    if(x<0)putchar(45),x=-x;
    char a[20],s=0;
    do a[++s]=x%10|48;while(x/=10);
    do putchar(a[s]);while(--s);
    putchar(c);
}
char a[N];
int main()
{
	int n=read();
	char m=read()+96;
	int s=0;
	for(char i=97;i<=m;++i)
	{
		a[s++]=i;
		for(char j=i+1;j<=m;++j)
		{
			a[s++]=i;
			a[s++]=j;
		}
	}
	for(int i=0;n--;i=(i+1)%s)
	{
		putchar(a[i]);
	}
}