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
char a[N],b[N];
int l[N],r[N];
int main()
{
	int n=read(),m=read();
	scanf("%s%s",a+1,b+1);
	for(int i=1,j=1;i<=m;++i)
	{
		while(a[j]!=b[i])++j;
		l[i]=j++;
	}
	for(int i=m,j=n;i>=1;--i)
	{
		while(a[j]!=b[i])--j;
		r[i]=j--;
	}
	int ans=0;
	for(int i=1;i<m;++i)ans=max(ans,r[i+1]-l[i]);
	write(ans,'\n');
}