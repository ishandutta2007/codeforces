#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define P 998244853
#define base 257
#define MAXN 251
int N,M,K,b[MAXN*4],f[MAXN*4],a[MAXN][MAXN],cnt[MAXN][MAXN][27],val[MAXN],ans;
int solve(vector<int>a)
{
	if(a.empty())return 0;b[0]=-2;b[1]=-1;K=1;for(auto i:a)b[++K]=i,b[++K]=-1;b[K+1]=-3;
	int ans=0,r=0,mid=0;For(i,1,K){if(i<=r)f[i]=min(f[mid*2-i],r-i+1);else f[i]=0;while(b[i-f[i]]==b[i+f[i]])f[i]++;if(i+f[i]-1>r)r=i+f[i]-1,mid=i;ans+=f[i]>>1;}return ans;
}
int main()
{
	cin>>N>>M;For(i,1,N)For(j,1,M){char c;cin>>c;a[i][j]=c-'a'+1;}
	For(i,1,N)For(j,1,M){For(k,1,26)cnt[i][j][k]=cnt[i][j-1][k];cnt[i][j][a[i][j]]++;}
	For(l,1,M)For(r,l,M)
	{
		For(i,1,N){int x=0,flag=0;For(j,1,26)x=(1ll*x*base+cnt[i][r][j]-cnt[i][l-1][j]+1)%P,flag+=cnt[i][r][j]-cnt[i][l-1][j]&1;if(flag>1)x=0;val[i]=x;}
		vector<int>v;For(i,1,N)if(val[i])v.push_back(val[i]);else ans+=solve(v),v.clear();ans+=solve(v);
	}
	cout<<ans<<'\n';
}