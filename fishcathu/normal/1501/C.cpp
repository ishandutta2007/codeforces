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
const int N=2E5+10,M=2.5E6+10;
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
pii a[N];
int l[M],r[M];
int main()
{
	int n=read();
	for(int i=1;i<=n;++i)
	{
		a[i].fi=read();
		a[i].se=i;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i)for(int j=1;j<i;++j)
	{
		int t=a[i].fi-a[j].fi;
		if(!l[t])
		{
			l[t]=j;
			r[t]=i;
		}
		else if(r[t]<j)
		{
			puts("YES");
			write(a[l[t]].se,' ');
			write(a[i].se,' ');
			write(a[r[t]].se,' ');
			write(a[j].se,'\n');
			return 0;
		}
	}
	puts("NO");
}