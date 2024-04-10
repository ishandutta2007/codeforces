#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5E5+10;
ll read()
{
    ll a=0;char b=1,c;
    do if((c=getchar())==45)b=-1;while(c<48||c>57);
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())>47&&c<58);
    return a*b;
}
void write(ll x)
{
    if(x<0)putchar('-'),x=-x;
    char a[20],s=0;
    do a[++s]=x%10|48;while(x/=10);
    do putchar(a[s]);while(--s);
}
int a[4],b[6];
bool check()
{
	for(int i=1;i<=3;++i)a[i]=read();
	for(int i=1;i<=5;++i)b[i]=read();
	for(int i=1;i<=3;++i)if(b[i]>a[i])return 0;
	if(b[1]+b[3]+b[4]>a[1]+a[3])return 0;
	if(b[2]+b[3]+b[5]>a[2]+a[3])return 0;
	if(b[1]+b[2]+b[3]+b[4]+b[5]>a[1]+a[2]+a[3])return 0;
	return 1;
}
int main()
{
	for(int x=read();x--;)
	{
		puts(check()?"YES":"NO");
	}
}