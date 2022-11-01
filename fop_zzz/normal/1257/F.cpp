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

const int N=105;
int a[N],n,c[N];
map<unsigned ll,int> mp;
inline void Dfs1(int pos,int x)
{
	if(pos==15)
	{
		unsigned ll hsh=0;
		For(i,1,n)
		{
			int b=a[i]^x,cnt=0;
			For(p,0,14)	if(b>>p&1)	cnt++;
			hsh=hsh*37+cnt;
		}
		// if(x==1)	cout<<hsh<<endl;
		mp[hsh]=x;
		return;
	}
	Dfs1(pos+1,x);
	Dfs1(pos+1,x|(1<<pos));
}
inline void Dfs2(int pos,int x)
{
	if(pos==29)
	{
		int mi=1e9;
		For(i,1,n)	
		{
			int b=a[i]^x;
			c[i]=0;
			For(p,15,29)	if(b>>p&1)	c[i]++;
			mi=min(mi,c[i]);
		}
		For(sum,mi,29)
		{
			unsigned ll hsh=0;
			For(i,1,n)	hsh=hsh*37+(sum-c[i]);
			if(mp.count(hsh))	
			{
				writeln(x^mp[hsh]);
				exit(0);
			}	
		}
		return;
	}
	Dfs2(pos+1,x);
	Dfs2(pos+1,x|(1<<pos));
}
int main()
{
	n=read();
	For(i,1,n)	a[i]=read();
	Dfs1(0,0);Dfs2(15,0);
	puts("-1");
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
	-- Benq
*/