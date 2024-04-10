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
const int N=1.5E5+10,M=2E5+10;
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
pii a[4][N],c[M];
int b[4];
int main()
{
	for(int i=0;i<4;++i)b[i]=read();
	for(int i=0;i<4;++i)
	{
		for(int j=1;j<=b[i];++j)
		{
			a[i][j].fi=read();
			a[i][j].se=j;
		}
	}
	for(int i=0;i<3;++i)
	{
		sort(a[i]+1,a[i]+1+b[i]);
		int cnt=read();
		for(int j=1;j<=cnt;++j)
		{
			c[j].fi=read();
			c[j].se=read();
		}
		sort(c+1,c+1+cnt);
		c[cnt+1].fi=0;
		int x=1;
		while(x<=b[i]&&!~a[i][x].fi)++x;
		for(int j=1;j<=b[i+1];++j)
		{
			int t=x;
			while(t<=b[i])
			{
				pii y=mp(a[i][t].se,j);
				if(*lower_bound(c+1,c+1+cnt,y)!=y)break;
				++t;
			}
			if(t>b[i])a[i+1][j].fi=-1;
			else a[i+1][j].fi+=a[i][t].fi;
		}
	}
	int ans=1<<30;
	for(int i=1;i<=b[3];++i)if(~a[3][i].fi)
	{
		ans=min(ans,a[3][i].fi);
	}
	write(ans==1<<30?-1:ans,'\n');
}