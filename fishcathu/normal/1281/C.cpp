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
const int N=1E6+10;
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
const int p=1E9+7;
void solve()
{
	int n=read();
	scanf("%s",a+1);
	int s=strlen(a+1);
	int i=1;
	while(s<n)
	{
		int t=s-i;
		int j=s+1;
		s+=t*(a[i]-49);
		while(j<=s&&j<=n)
		{
			a[j]=a[j-t];
			++j;
		}
		++i;
	}
	while(i<=n)
	{
		s=(s+(s-i)*1ll*(a[i]-49))%p;
		++i;
	}
	write((s+p)%p,'\n'); 
}
int main()
{
	for(int x=read();x--;)
	{
		solve();
	}
}