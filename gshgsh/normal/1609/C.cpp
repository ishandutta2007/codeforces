#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 1000001
int T,N,M,a[MAXN],tot,prm[MAXN];bool Not[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
ll solve(vector<int>x)
{
	if(x.empty())return 0;
	vector<int>a;int cnt=0;for(auto i:x)if(i!=1)a.push_back(cnt+1),cnt=0;else cnt++;a.push_back(cnt+1);
	int M=a.size();ll ans=0;For(i,1,M-1)ans+=1ll*a[i-1]*a[i]-1;return ans;
}
int main()
{
	For(i,2,MAXN-1){if(!Not[i])prm[++tot]=i;for(int j=1;j<=tot&&i*prm[j]<MAXN;j++){Not[i*prm[j]]=1;if(i%prm[j]==0)break;}}
	T=get();
	while(T--)
	{
		N=get(),M=get();For(i,1,N)a[i]=get();ll ans=0;
		For(j,1,M){vector<int>v;for(int i=j;i<=N;i+=M){if(a[i]>1&&Not[a[i]])ans+=solve(v),v.clear();else v.push_back(a[i]);}ans+=solve(v);}
		cout<<ans<<'\n';
	}
	return 0;
}