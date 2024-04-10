#include<bits/stdc++.h>
using namespace std;
#define N 5000500
typedef long long ll;
int a[N],n,m,g[N],dmx[N];
int now;
void init(int n){
	dmx[1]=1;
	for(int i=2;i<=n;++i){
		if(!dmx[i]){
			for(int j=i;j<=n;j+=i){
				dmx[j]=max(dmx[j],i);
			}
		}
	}
}
void Solve(){
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		a[i]=g[i]=0;
	}
	int MX=0;
	for(int i=1;i<=n;++i){
		int x;
		cin>>x;
		++a[x];
		MX=max(MX,dmx[x]);
	}
	auto Add=[&](int x){
		for(int i=1;i<=m/x;++i){
			if(g[i]){
				if(!g[i*x])now+=a[i*x];
				g[i*x]+=g[i];
			}
		}
	};
	auto Del=[&](int x){
		for(int i=m/x;i>=1;--i){
			if(g[i]){
				g[i*x]-=g[i];
				if(!g[i*x])now-=a[i*x];
			}
		}
	};
	int ans=MX-1;
	now=0;
	g[1]=1;
	for(int i=2,j=2;i<=m;++i){
		while(j<=m&&now<n)Add(j++);
		if(now<n)break;
		Del(i);
		ans=min(ans,j-i-1);
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	init(5000000);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}