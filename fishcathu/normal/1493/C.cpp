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
char a[N];
int b[26],m;
void add(int x,int val)
{
	b[x]=(b[x]+val+m)%m;
}
void solve()
{
	int n=read();
	m=read();
	scanf("%s",a+1);
	if(n%m)
	{
		puts("-1");
		return;
	}
	for(int i=1;i<=n;++i)a[i]-=97;
	int s=n/m,k=1;
	while(k<=n)
	{
		if(!b[a[k]]&&!s--)break;
		add(a[k],-1);
		++k;
	}
	if(k<=n)
	{
		int j=a[k]+1;
		while(j<26&&!b[j])++j;
		if(j<26)
		{
			a[k]=j;
			add(j,-1);
		}
		else while(--k)
		{
			add(a[k],1);
			if(!b[a[k]])
			{
				while(a[k]==25)
				{
					--k;
					add(a[k],1);
				}
				++a[k];
				add(a[k],-1);
				break;
			}
			j=a[k]+1;
			while(j<26&&!b[j])++j;
			if(j<26)
			{
				a[k]=j;
				add(j,-1);
				break;
			}
		}
	}
	else --k;
	for(int i=1;i<=k;++i)putchar(a[i]+97);
	s=n-k;
	for(int i=26;i--;)s-=b[i];
	while(s--)putchar(97);
	for(int i=0;i<26;++i)
	{
		while(b[i]--)putchar(i+97);
	}
	putchar('\n');
	memset(b,0,sizeof b);
}
int main()
{
	for(int x=read();x--;)
	{
		solve();
	}
}