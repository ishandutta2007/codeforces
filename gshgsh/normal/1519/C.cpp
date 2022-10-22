#include<algorithm>
#include<iostream>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 200001
int T,N,a[MAXN];ll res[MAXN];vector<ll>Div[MAXN],val[MAXN],ans[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N)a[i]=get(),Div[i].clear(),val[i].clear(),ans[i].clear(),res[i-1]=0;For(i,1,N)for(int j=i;j<=N;j+=i)Div[j].push_back(i);
		For(i,1,N)val[a[i]].push_back(get());For(i,1,N)if(!val[i].empty()){ans[i].resize(val[i].size());sort(val[i].begin(),val[i].end(),greater<ll>());For(j,1,val[i].size()-1)val[i][j]+=val[i][j-1];}
		For(i,1,N)if(!val[i].empty())FOR(j,val[i].size(),1)for(auto k:Div[j])if(!ans[i][k-1])ans[i][k-1]=val[i][j-1];
		For(i,1,N)if(!val[i].empty())For(j,0,val[i].size()-1)res[j]+=ans[i][j];For(i,1,N)cout<<res[i-1]<<' ';cout<<endl;
	}
	return 0;
}