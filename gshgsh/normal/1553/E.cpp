#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 300001
int T,N,M,p[MAXN],cnt[MAXN],f[MAXN];int getf(int x){return f[x]==x?x:f[x]=getf(f[x]);}
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
bool check(int x){For(i,1,N)f[i]=i;int ans=0;For(i,1,N){int a=(i-x+N-1)%N+1,b=p[i],x=getf(a),y=getf(b);if(x!=y)f[x]=y,ans++;}return ans<=M;}
int main()
{
	T=get();
	while(T--)
	{
		N=get(),M=get();For(i,1,N)p[i]=get(),cnt[i]=0;For(i,1,N)cnt[(i-p[i]+N)%N]++;
		vector<int>ans;For(i,0,N-1)if(cnt[i]>=N-M*2)if(check(i))ans.push_back(i);
		cout<<ans.size();for(auto i:ans)cout<<' '<<i;cout<<'\n';
	}
	return 0;
}