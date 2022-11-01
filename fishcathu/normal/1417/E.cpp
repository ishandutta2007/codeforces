#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=3E5+1;
#define pb push_back
int read()
{
    int a=0;char b=1,c;
    do if((c=getchar())==45)b=-1;while(c<48||c>57);
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())>47&&c<58);
    return a*b;
}
void write(int x)
{
    if(x<0)putchar('-'),x=-x;
    char a[10],s=0;
    do a[s++]=x%10|48;while(x/=10);
    do putchar(a[--s]);while(s);
}
int nex[N<<5][2];vector<int>v[N<<5];ll dp[30][2];
void dfs(int x,int dep)
{
	int l=nex[x][0],r=nex[x][1];
	if(l)dfs(l,dep-1);
	if(r)dfs(r,dep-1);
	if(!l||!r)return;
	int sl=v[l].size(),sr=v[r].size();
	ll s=0;
	for(int i=0,j=0;i<sl;++i)
	{
		while(j<sr&&v[r][j]<v[l][i])++j;
		s+=j;
	}
	dp[dep][0]+=s;
	dp[dep][1]+=sl*1ll*sr-s;
}
int main()
{
	int n=read(),a2=0;
	ll a1=0;
	for(int i=1,cnt=0;i<=n;++i)
	{
		int t=read();
		for(int j=29,now=0;j>=0;--j)
		{
			int k=t>>j&1;
			if(!nex[now][k])nex[now][k]=++cnt;
			now=nex[now][k];
			v[now].pb(i);
		}
	}
	dfs(0,29);
	for(int i=29;i>=0;--i)
	{
		if(dp[i][0]<=dp[i][1])a1+=dp[i][0];
		else a1+=dp[i][1],a2+=1<<i;
	}
	printf("%lld %d",a1,a2);
}