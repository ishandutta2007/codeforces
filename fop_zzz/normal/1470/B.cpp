#include<bits/stdc++.h>
#define For(i,j,k)  for(int i=j;i<=k;++i)
#define Dow(i,j,k)  for(int i=k;i>=j;--i)
#define ll long long
#define pb push_back
#define fi first
#define se second
#define pb push_back
#define pa pair<int,int>
#define mk make_pair
 
using namespace std;
 
inline ll read()
{
    ll t=0,dp=1;char c=getchar();
    while(!isdigit(c))  {if(c=='-') dp=-1;c=getchar();}
    while(isdigit(c))   t=t*10+c-48,c=getchar();
    return t*dp;
}
inline void write(ll x){if(x<0)  {putchar('-');x=-x;}    if(x>=10)    write(x/10);putchar(x%10+48);}
inline void writeln(ll x){write(x);puts("");}
inline void write_p(ll x){write(x);putchar(' ');}

#define int long long 

int T,n,Q,a[500005],cnt,pri[500005];
bool bj[500005];

map<int,int> Mp;
signed main()
{
	bj[1]=1;
	For(i,2,1000) if (!bj[i])
	{
		pri[++cnt]=i;
		For(j,2,1000/i) bj[i*j]=1;
	}

	int T=read();
	while(T--)
	{
		Mp.clear();
		n=read();
		For(i,1,n)
		{
			a[i]=read();
			int y=1;
			For(j,1,cnt)
			{
				int x=0;
				while (a[i]%pri[j]==0) a[i]/=pri[j],++x;
				if (x&1) y=y*pri[j];
			}
			Mp[y*a[i]]+=1;
		// cout<<y*a[i]<<".."<<endl;
		}
		int ans=0,tot=0;
		for(auto x:Mp) ans=max(ans,x.se);
		int ans2=ans;
		tot=0;
		for (auto x:Mp) 
			if (x.fi==1||x.se%2==0) tot+=x.se;
		int q=read();
		ans2=max(ans2,tot);
		while (q--)
		{
			int x=read();
			if(x==0)	writeln(ans);	else	writeln(ans2);
		}
	}
}