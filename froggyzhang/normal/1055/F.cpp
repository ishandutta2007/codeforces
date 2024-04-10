#include<bits/stdc++.h>
using namespace std;
#define N 2000100
#define M 63
typedef long long ll;
int n,ch[N][2],a[N],b[N],siz[N],cnt;
ll k,dis[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(int i=2;i<=n;++i){
		int fa;
		ll w;
		cin>>fa>>w;
		dis[i]=dis[fa]^w;
	}
	--k;
	ll ans=0;
	for(int i=1;i<=n;++i){
		a[i]=b[i]=1;
	}
	for(int j=61;j>=0;--j){
		for(int i=1;i<=cnt;++i){
			ch[i][0]=ch[i][1]=siz[i]=0;
		}
		cnt=0;
		for(int i=1;i<=n;++i){
			int c=dis[i]>>j&1;
			if(!ch[a[i]][c])ch[a[i]][c]=++cnt;
			++siz[a[i]=ch[a[i]][c]];
		}
		ll tot=0;
		for(int i=1;i<=n;++i){
			int c=dis[i]>>j&1;
			tot+=siz[ch[b[i]][c]];
		}
		int flag=0;
		if(tot<=k)k-=tot,ans|=1LL<<j,flag=1;
		for(int i=1;i<=n;++i){
			int c=dis[i]>>j&1;
			b[i]=ch[b[i]][c^flag];
		}
	}
	cout<<ans<<'\n';
	return 0;
}