#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<queue>
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll long long
#define inf 1e9
#define fir first
#define sec second
#define pb push_back
#define mk make_pair
#define pa pair<int,int>
using namespace std;
inline int read()
{
	int t=0,f=1;char c=getchar();
	while(!isdigit(c))	{if(c=='-')	f=-1;c=getchar();}
	while(isdigit(c))	t=t*10+c-'0',c=getchar();
	return t*f;
}
inline void write(int x){if(x>=10)	write(x/10);putchar(x%10+'0');}
inline void writeln(int x){write(x);puts("");}
inline void write_p(int x){write(x);putchar(' ');}
int n,x,y;
int dr[500001],dl[500001],ul[500001],ur[500001];
ll ans=0;
vector<pa> vec[2];
inline void Solve(int p)
{
	memset(ur,0,sizeof ur);memset(ul,0x3f,sizeof ul);
	memset(dr,0,sizeof dr);memset(dl,0x3f,sizeof dl);
	for(int i=0;i<vec[p].size();++i)
	{
		ur[vec[p][i].fir]=dr[vec[p][i].fir]=max(ur[vec[p][i].fir],vec[p][i].sec);
		ul[vec[p][i].fir]=dl[vec[p][i].fir]=min(ul[vec[p][i].fir],vec[p][i].sec);
	}	
	For(i,1,400000)dl[i]=min(dl[i],dl[i-1]),dr[i]=max(dr[i],dr[i-1]);
	Dow(i,0,399999)ul[i]=min(ul[i],ul[i+1]),ur[i]=max(ur[i],ur[i+1]);
	For(i,0,400000)	if(i&1)	ans+=max(0,min(dr[i],ur[i])/2-max(dl[i],ul[i])/2);	
}
int main()
{
	n=read();
	For(i,1,n)
	{
		x=read();y=read();
		if((x+y)&1)	x--,vec[1].pb(mk(x+y+200000,x-y+200000));else	vec[0].pb(mk(x+y+200000,x-y+200000));
	}
	Solve(1);Solve(0);
	cout<<ans<<endl;
}