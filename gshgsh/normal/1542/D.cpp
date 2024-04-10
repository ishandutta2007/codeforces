#include<algorithm>
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define P 998244353
#define MAXN 501
int N,M,type[MAXN],x[MAXN],f[MAXN][MAXN],id[MAXN],pos[MAXN],ans;
int calc(int x)
{
	For(i,0,N)For(j,0,M)f[i][j]=0;f[0][0]=1;
	For(i,1,x-1)
	{
		For(j,0,M)f[i][j]=f[i-1][j];
		if(type[i])For(j,0,M)f[i][j+(id[i]<id[x])]=(f[i][j+(id[i]<id[x])]+f[i-1][j])%P;
		else For(j,0,M)f[i][max(j-1,0)]=(f[i][max(j-1,0)]+f[i-1][j])%P;
	}
	For(i,0,M)f[x][i]=f[x-1][i];
	For(i,x+1,N)
	{
		For(j,0,M)f[i][j]=f[i-1][j];
		if(type[i])For(j,0,M)f[i][j+(id[i]<id[x])]=(f[i][j+(id[i]<id[x])]+f[i-1][j])%P;
		else For(j,1,M)f[i][j-1]=(f[i][j-1]+f[i-1][j])%P;
	}
	int ans=0;For(i,0,M)ans=(ans+f[N][i])%P;return ans;
}
int main()
{
	cin>>N;For(i,1,N){char c;cin>>c;type[i]=c=='+';type[i]&&cin>>x[i];}
	vector<pair<int,int> >tmp;For(i,1,N)if(type[i])M++,tmp.push_back({x[i],i});
	sort(tmp.begin(),tmp.end());For(i,0,M-1)id[tmp[i].second]=i+1,pos[i+1]=tmp[i].second;
	For(i,1,N)if(type[i])ans=(ans+1ll*x[i]*calc(i))%P;cout<<ans<<endl;return 0;
}