#include<bits/stdc++.h>
#define For(i,j,k)  for(int i=j;i<=k;++i)
#define Dow(i,j,k)  for(int i=k;i>=j;--i)
#define ll long long
#define pb push_back
#define fir first
#define sec second
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

const int N=505;
vector<int> E[N];
int dep[N],n;
ll ans,mo=1e9+7;
inline ll ksm(ll x,ll y){ll ret=1;for(;y;y/=2,x=x*x%mo) if(y&1)	ret=ret*x%mo;return ret;}

int Fa[233][10];
inline void Dfs(int x,int fa)
{
	Fa[x][0]=fa;
	for(auto u:E[x])
	{
		if(u==fa)	continue;
		dep[u]=dep[x]+1;
		Dfs(u,x);
	}
}
inline int LCA(int x,int y)
{
	if(dep[x]<dep[y])	swap(x,y);
	Dow(i,0,9)	if((dep[x]-dep[y])>>i&1)	x=Fa[x][i];
	if(x==y)	return x;
	Dow(i,0,9)	if(Fa[x][i]!=Fa[y][i])	x=Fa[x][i],y=Fa[y][i];
	return Fa[x][0];		
}
ll dp[233][233];
inline void Solve(int rt)
{
	dep[rt]=0;
	Dfs(rt,rt);
	For(j,1,9)	For(i,1,n)		Fa[i][j]=Fa[Fa[i][j-1]][j-1];	
	// cout<<rt<<"::";
	For(i,1,n)
		For(j,1,i-1)
		{
			// cout<<i<<' '<<j<<':'<<endl;
			int lc=LCA(i,j);
			ll tt=dep[j]-dep[lc],rr=dep[i]-dep[lc];
			if(lc==i)	ans++;//cout<<"1/1"<<endl;
			else	if(lc==j)	{tt=0;}
			else	ans=ans+dp[rr][tt];//ans+=tt*ksm(tt+rr,mo-2)%mo;//cout<<tt<<"/"<<tt+rr<<endl;
			while(ans>=mo)	ans-=mo;
		}	
}
inline void Pre()
{
	ll re=ksm(2,mo-2);
	For(i,0,200)	For(j,0,200)	if(i+j!=0)
	{
		if(i==0)	dp[i][j]=1;
		else	if(j==0)	dp[i][j]=0;
		else	dp[i][j]=(dp[i-1][j]+dp[i][j-1])*re%mo;
	}
}
int main()
{
	// For(i,1,100)	For(j,1,100)	if(i*ksm(j,mo-2)%mo==733333342)	cout<<i<<"!!"<<j<<endl;
	n=read();
	Pre();
	For(i,1,n-1)	
	{
		int u=read(),v=read();
		E[u].pb(v);E[v].pb(u);
	}
	For(rt,1,n)
	{
		Solve(rt);
	}
	ans=ans*ksm(n,mo-2)%mo;
	cout<<ans<<endl;
}