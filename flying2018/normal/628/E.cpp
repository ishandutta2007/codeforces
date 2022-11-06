#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define ll long long
#define P pair<int,int>
#define MP make_pair
#define N 3010
using namespace std;
int a[N][N],s[N][N],l[N][N],v[N][N];
void add(int x,int y,int p){for(;x<N;x+=(x&(-x))) v[x][y]+=p;}
int qry(int x,int y){int ans=0;for(;x;x-=(x&(-x))) ans+=v[x][y];return ans;}
char st[N];
vector<P >vl[N];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",st+1);
		for(int j=1;j<=m;j++) a[i][j]=st[j]=='z';
	}
	for(int i=1;i<=n;i++)
		for(int j=m;j>0;j--)
			if(a[i][j]) l[i][j]=l[i][j+1]+1,s[i][j]=s[i-1][j+1]+1;
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>0;j--)
		if(a[i][j])
		{
			add(i,j,1);
			if(i+l[i][j]-1<N) vl[i+l[i][j]-1].push_back(MP(i,j));
			ans+=qry(i,j)-qry(i-min(l[i][j],s[i][j]),j);
		}
		for(P u:vl[i]) add(u.first,u.second,-1);
	}
	printf("%lld",ans);
	return 0;
}