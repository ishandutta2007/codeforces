#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 200001
int T,N,a[MAXN],cnt[MAXN],tot[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N)a[i]=get();For(i,0,N)cnt[i]=0;For(i,1,N)cnt[a[i]]++;int mex=0;while(cnt[mex])mex++;vector<int>ans;int x=1;
		while(x<=N)
		{
			int y=x+1,now=0;tot[a[x]]++;if(!a[x])now=1;while(now<mex){tot[a[y++]]++;while(tot[now])now++;}
			ans.push_back(now);For(i,x,y-1)tot[a[i]]--,cnt[a[i]]--,!cnt[a[i]]&&(mex=min(mex,a[i]));x=y;
		}
		cout<<ans.size()<<'\n';for(auto i:ans)cout<<i<<' ';cout<<'\n';
	}
	return 0;
}