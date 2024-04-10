//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define int long long
#define YES puts("YES")
#define NO puts("NO")
#define Yes puts("Yes")
#define No puts("No")
#define edl puts("")
#define mc cerr<<"qwq\n"
#define error goto gg
#define def gg:
#define rd(x) x=read()
#define opl(x) printf("%lld",x)
#define opls(x) printf("%lld ",x)
#define opd(x) printf("%d",x)
#define opds(x) printf("%d ",x)
#define ver(x) for(int i=head[x];i;i=nxt[i])
#define up(i,x,y) for(int i=x,i##end=y;i<=i##end;++i)
#define pu(i,x,y) for(int i=x,i##end=y;i>=i##end;--i)
#define ft(x) for(int i=head[x];i;i=nxt[i])
#define upn up(i,1,n)
#define upm up(j,1,m)
#define pun pu(i,n,1)
#define pum pu(j,m,1)
#define up_(x) up(i,1,x)
#define pu_(x) pu(j,x,1)
#define ep emplace_back
#define fp for(auto to:
#define pf )
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define mkp make_pair
#define fi first
#define se second
#define mii map<int,int>
#define mis map<int,string>
#define msi map<string,int>
#define mvi map<vector<int>,int>
#define miv map<int,vector<int>>
#define rdn rd(n)
#define rdm rd(m)
#define rdk rd(k)
using namespace std;
int n, m, k;
int read()
{
    int s = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        s = s * 10 + ch - '0';
        ch = getchar();
    }
    return s * f;
}

#define inf 1000000000000000000ll
ll Max(ll a=-inf,ll b=-inf,ll c=-inf,ll d=-inf,ll e=-inf,ll f=-inf,ll g=-inf,ll h=-inf)
{
	return max(max(max(a,b),max(c,d)),max(max(e,f),max(g,h)));
}
ll Min(ll a=inf,ll b=inf,ll c=inf,ll d=inf,ll e=inf,ll f=inf,ll g=inf,ll h=inf)
{
	return min(min(min(a,b),min(c,d)),min(min(e,f),min(g,h)));
}
#undef inf
int a[303030],d[303030],f[303030];
int p,q,ff;
void F(int p1,int val)
{
	if(p1<=n)
	{
		val%=p;
		int nw=d[p1];
		(d[p1]+=val+p*p)%=p;
		if(!d[p1]&&nw)--ff;
		if(d[p1]&&!nw)++ff;
	}
	
}
signed main()
{
	int T=1;
	while(T--)
	{
		rdn;rd(q);rd(p);f[1]=f[2]=1;
		upn rd(a[i]);up(i,3,n)f[i]=(f[i-1]+f[i-2])%p;
		upn
		{
			a[i]%=p;a[i]-=read()%p;a[i]+=p*p;a[i]%=p;
		}
		upn
		{
			d[i]=(a[i]-a[i-1]-(i==1?0:a[i-2]));
			
			d[i]+=p*p;d[i]%=p;
		}
		upn if(d[i])ff++;
		
		up(wwww,1,q)
		{
			char c;scanf("%c",&c);
			int l,r;rd(l);rd(r);
			if(c=='A')
			{
				if(r-l==1)
				{
					F(l,1);
					F(l+2,-2);
					F(l+3,-1);
				}
				else if(r-l==0)
				{
					F(l+1,-1);
					F(l+2,-1);
					F(l,1);
					
				}
				else
				{
					F(l,1);F(r+2,p-f[r-l+1]);
					F(r+1,p-(f[r-l+1]+f[r-l])%p);
					
				}
			}
			else
			{
				if(r-l==1)
				{
					F(l,-1);
					F(l+2,2);
					F(l+3,1);
				}
				else if(r-l==0)
				{
					F(l+1,1);
					F(l+2,1);
					F(l,-1);
					
				}
				else
				{
					F(l,-1);F(r+2,f[r-l+1]);
					F(r+1,(f[r-l+1]+f[r-l])%p);
					
				}
			}
			if(!ff)YES;
			else NO;
		}
		
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/