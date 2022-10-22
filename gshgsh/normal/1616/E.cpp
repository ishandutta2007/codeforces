#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define lowbit(x) x&-x
#define INF 0x3fffffffffffffff
#define MAXN 100001
int T,N,a[MAXN],b[MAXN],c[MAXN],cnt[26];vector<int>pos[26];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void upd(int x,int v){for(int i=x;i<=N;i+=lowbit(i))c[i]+=v;}
int ask(int x){int ans=0;for(int i=x;i;i-=lowbit(i))ans+=c[i];return ans;}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N){char c;cin>>c;a[i]=c-'a';}For(i,1,N){char c;cin>>c;b[i]=c-'a';}
		For(i,0,25)cnt[i]=0,pos[i].clear();For(i,1,N)pos[a[i]].push_back(i);
		For(i,1,N)c[i]=0;For(i,1,N)upd(i,1);ll ans=INF,sum=0;
		For(i,1,N)
		{
			int mn=N+1;For(j,0,b[i]-1)if(cnt[j]<pos[j].size())mn=min(mn,ask(pos[j][cnt[j]]-1));
			if(mn!=N+1)ans=min(ans,sum+mn);if(cnt[b[i]]>=pos[b[i]].size())break;
			int p=pos[b[i]][cnt[b[i]]++];upd(p,-1);sum+=ask(p-1);
		}
		if(ans==INF)cout<<"-1\n";else cout<<ans<<'\n';
	}
}