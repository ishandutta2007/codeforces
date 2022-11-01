#include<bits/stdc++.h>
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll long long
#define pb push_back
#define pa pair<int,int>
#define fir first
#define sec second
#define mk make_pair
#define int ll 

using namespace std;

inline ll read()
{
    ll t=0,dp=1;char c=getchar();
    while(!isdigit(c))	{if(c=='-')	dp=-1;c=getchar();}
    while(isdigit(c))	t=t*10+c-48,c=getchar();
    return t*dp;
}
inline void write(ll x){if(x<0)	{putchar('-');x=-x;}	if(x>=10)	write(x/10);putchar(x%10+48);}
inline void writeln(ll x){write(x);puts("");}
inline void write_p(ll x){write(x);putchar(' ');}
/*------------------------------------------------------------------------------------------------------*/

const int N=100005;
int n,S,t,a[N],Fa[N],head[N];
inline ll check(ll k)
{
	a[1]=1;
	int now=2,hav=n-1;
	ll tot=1;
	while(hav)
	{
		if(a[now-1]*k>=hav)	tot+=hav*now,hav=0,now++;
		else
		{
			a[now]=a[now-1]*k;
			tot+=a[now]*now;
			hav-=a[now];
			++now;
		}
	}
	return tot;
}
vector<pa> vec[N];
inline void Solve()
{
	ll tot=0;
	For(i,1,n)	Fa[i]=i-1,tot+=i,vec[i].push_back(mk(i,t-1)),head[i]=0;	
	tot-=S;
	if(tot<0)
	{
		puts("No");
		return;
	}
	puts("Yes");
	int dep=1;
	Dow(i,2,n)
	{
		if(tot==0)	break;		
		if(head[dep]+1<vec[dep].size()&&vec[dep][head[dep]].sec==0)	head[dep]++;
		while(dep+1<=i&&!(vec[dep][head[dep]].sec))	dep++;
		int will=i-(dep+1);
		if(will>=tot)
		{
			dep=i-tot-1;
			if(head[dep]+1<vec[dep].size()&&vec[dep][head[dep]].sec==0)	head[dep]++;
			Fa[i]=vec[dep][head[dep]].fir;
			break;
		}
		else
		{
			tot-=will;
			vec[dep][head[dep]].sec--;Fa[i]=vec[dep][head[dep]].fir;
			vec[dep+1].pb(mk(i,t));
		}
	}
	For(i,2,n)	write_p(Fa[i]);
}
signed main()
{
	n=read();S=read();
	t=-1;
	int l=1,r=n-1;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(check(mid)<=S)	t=mid,r=mid-1;else	l=mid+1;
	}
	if(t==-1)	puts("No");else	Solve();
}