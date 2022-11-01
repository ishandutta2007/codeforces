#include<bits/stdc++.h>
#define ll long long
#define inf 1e9
#define pb push_back
#define fir first
#define sec second
#define c(x,y)  ((x-1))*m+(y)
#define int unsigned long long
#define pa pair<int,int>
#define mk make_pair
#define For(i,j,k)  for(int i=j;i<=k;++i)
#define Dow(i,j,k)  for(int i=k;i>=j;--i)

using namespace std;

int bas=23;
char l_s[2003][203],s_s[203][2003];
int hsh[2004];
int a[203][2004],n,m;
int bas1=29;
map<int,int> vis;
signed main()
{
	cin>>n>>m;
	For(i,1,n) scanf("\n%s",l_s[i]+1);
	For(i,1,m) scanf("\n%s",s_s[i]+1);
	For(i,1,n)
	{
		For(j,1,m)	hsh[i]=hsh[i]*bas+l_s[i][j];
	}
	For(i,1,m)
	{
		For(j,1,n-m+1)
		{
			int h=0;
			For(k,j,j+m-1)	h=h*bas+s_s[i][k];
			a[i][j]=h;

		}
	}
	For(i,1,n-m+1)
	{
		int now=a[m][i];
		Dow(j,1,m-1)  now=now*bas*bas1+a[j][i];
		vis[now]=i;
	}
	For(i,m,n)
	{
		int now=hsh[i];
		Dow(j,i-m+1,i-1)
			now=now*bas*bas1+hsh[j];
		if(vis.count(now))
		{
			cout<<i-m+1<<' '<<vis[now]<<endl;
			return 0;
		}
	}
}
/*
10 5
somer
andom
noise
mayth
eforc
ebewi
thyou
hctwo
again
noise
somermayth
andomeforc
noiseebewi
mayththyou
noisehctwo
*/